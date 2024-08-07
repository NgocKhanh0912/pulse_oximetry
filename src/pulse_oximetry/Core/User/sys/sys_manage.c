/**
 * @file       sys_manage.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    v1.0.0
 * @date       2024-08-06
 * @author     Giang Phan Truong
 *             Khanh Nguyen Ngoc
 *             Viet Hoang Xuan
 *
 * @brief      Service manage all tasks of system
 *
 * @note
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "sys_manage.h"
#include "common.h"
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
static sys_measure_t s_ppg_signal;
static sys_display_t s_oled_screen;
static drv_buzzer_t s_passive_buzzer;
static drv_ds1307_t s_rtc;

static cbuffer_t s_rx_pkt_cbuf;
static uint8_t s_rx_pkt_buf[100] = {0};

static sys_manage_t s_mng = {SYS_MANAGE_STATE_IDLE, 0xFF, 0x0, 0x0};
static sys_protocol_pkt_t s_check_pkt = {0x00, 0xFFFFFFFF, 0xFF};
static const uint8_t s_success_noti[] = "Success!";
/* Private function prototypes ---------------------------------------- */

/**
 * @brief       Sleep down the system service.
 *
 * @return
 * -  None
 */
static void sys_manage_sleep();

/**
 * @brief       Wake up the system service.
 *
 * @return
 * -  None
 */
static void sys_manage_wakeup();

/**
 * @brief       Record the current heart rate.
 *
 * @return
 * -  None
 */
static void sys_manage_record_heart_rate();
/* Function definitions ----------------------------------------------- */
uint32_t sys_manage_start_display(bsp_i2c_handle_t *i2c, uint8_t *dev_buffer)
{
  uint32_t ret = SYS_DISPLAY_OK;
  ret = sys_display_init(&s_oled_screen, i2c, dev_buffer);
  __ASSERT(ret == SYS_DISPLAY_OK, SYS_MANAGE_ERROR);

  return SYS_MANAGE_OK;
}

uint32_t sys_manage_start_measure(bsp_adc_typedef_t *adc,
                                  bsp_tim_typedef_t *tim,
                                  uint32_t prescaler,
                                  uint32_t autoreload,
                                  double *data_buf)
{
  uint32_t ret = SYS_MEASURE_OK;
  ret = sys_measure_init(&s_ppg_signal, adc, tim, prescaler, autoreload, data_buf);
  __ASSERT(ret == SYS_MEASURE_OK, SYS_MANAGE_FAILED);

  return SYS_MANAGE_OK;
}

uint32_t sys_manage_start_button(GPIO_TypeDef *gpio, uint16_t pin, uint32_t button_active_level)
{
  uint32_t ret = SYS_BUTTON_OK;
  ret = sys_button_init(gpio, pin, button_active_level);
  __ASSERT(ret == SYS_BUTTON_OK, SYS_MANAGE_ERROR);
  ret = sys_button_register_cb_function(sys_manage_wakeup,
                                        sys_manage_sleep,
                                        sys_manage_record_heart_rate);
  __ASSERT(ret == SYS_BUTTON_OK, SYS_MANAGE_ERROR);
  return SYS_MANAGE_OK;
}

uint32_t sys_manage_start_protocol(UART_HandleTypeDef *uart)
{
  uint32_t ret = SYS_PROTOCOL_OK;
  ret = sys_protocol_init(uart);
  __ASSERT(ret == SYS_PROTOCOL_OK, SYS_MANAGE_ERROR);

  cb_init(&s_rx_pkt_cbuf, s_rx_pkt_buf, sizeof(s_rx_pkt_buf));
  ret = sys_protocol_register_node_to_send(SYS_PROTOCOL_SYS_MNG, &s_rx_pkt_cbuf);
  __ASSERT(ret == SYS_PROTOCOL_OK, SYS_MANAGE_ERROR);

  return SYS_MANAGE_OK;
}

uint32_t sys_manage_start_rtc(bsp_i2c_handle_t *i2c)
{
  uint32_t ret = SYS_TIME_OK;
  ret = sys_time_init(i2c, &s_rtc);
  __ASSERT(ret == SYS_TIME_OK, SYS_MANAGE_ERROR);

  return SYS_MANAGE_OK;
}

uint32_t sys_manage_start_buzzer(bsp_tim_typedef_t *tim, uint32_t pwm_channel)
{
  uint32_t ret = DRV_BUZZER_OK;
  ret = drv_buzzer_init(&s_passive_buzzer, tim, pwm_channel);
  __ASSERT(ret == DRV_BUTTON_OK, SYS_MANAGE_ERROR);

  return SYS_MANAGE_OK;
}

uint32_t sys_manage_loop()
{
  sys_button_manage();
  if (cb_data_count(&s_rx_pkt_cbuf) > 0)
  {
    cb_read(&s_rx_pkt_cbuf, &s_mng.cmd, CMD_PKT_SIZE);

    switch (s_mng.cmd)
    {
    case SYS_MANAGE_CMD_CHECK_UART:
      sys_protocol_send_pkt_to_port(s_check_pkt);
      break;
    case SYS_MANAGE_CMD_GET_DATA:
    {
      // Check UART
      sys_protocol_send_pkt_to_port(s_check_pkt);
      // Send current time first
      uint32_t ept = sys_time_get_epoch_time(&s_rtc);
      sys_protocol_pkt_t temp_pkt = {s_mng.cmd, ept, 0xFF};
      sys_protocol_send_pkt_to_port(temp_pkt);
      // Send current heart rate;
      temp_pkt.data = &s_ppg_signal.heart_rate;
      sys_protocol_send_pkt_to_port(temp_pkt);
      break;
    }
    case SYS_MANAGE_CMD_SET_THRESHOLD:
    {
      // Check UART
      sys_protocol_send_pkt_to_port(s_check_pkt);
      // Get threshold from packet
      uint32_t temp_data = 0;
      cb_read(&s_rx_pkt_cbuf, &temp_data, DATA_PKT_SIZE);
      // Set threshold
      s_mng.lower_thresshold = temp_data & (0x000000FF);
      s_mng.upper_threshold = temp_data & (0x000000FF << 8);
      // Notification
      sys_display_show_noti(&s_oled_screen, s_success_noti);
      break;
    }
    case SYS_MANAGE_CMD_SET_INTERVAL:
    {

      break;
    }
    case SYS_MANAGE_CMD_SET_TIME:
    {
      // Get epoch time from packet
      uint32_t temp_ept = 0;
      uint32_t ret = SYS_TIME_OK;
      cb_read(&s_rx_pkt_cbuf, &temp_ept, DATA_PKT_SIZE);
      // Set time for system RTC
      ret = sys_time_set_epoch_time(temp_ept, &s_rtc);
      __ASSERT(ret = SYS_TIME_OK, SYS_MANAGE_ERROR);
      // Notification
      sys_display_show_noti(&s_oled_screen, s_success_noti);
      break;
    }
    case SYS_MANAGE_CMD_CLEAR_RECORDS:
    {
      break;
    }
    default:
      break;
    }
  }
  sys_measure_process_data(&s_ppg_signal);
  sys_display_update_heart_rate(&s_oled_screen, s_ppg_signal.heart_rate);
  sys_display_update_ppg_signal(&s_oled_screen, &(s_ppg_signal.filtered_data));
}
/* Private definitions ------------------------------------------------ */
static void sys_manage_sleep()
{
  // Do something stuffs
  drv_hr_sleep(&(s_ppg_signal.dev));
  sys_display_sleep(&s_oled_screen);
}

static void sys_manage_wakeup()
{
  // Do something stuffs
  drv_hr_wakeup(&(s_ppg_signal.dev));
  sys_display_wakeup(&s_oled_screen);
}

static void sys_manage_record_heart_rate()
{
  // Waiting for Khanh
}
/* End of file -------------------------------------------------------- */
