/**
 * @file       sys_managw.h
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

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __USER_SYS_MANAGE_H
#define __USER_SYS_MANAGE_H

/* Includes ----------------------------------------------------------- */
#include "sys_button.h"
#include "sys_display.h"
#include "sys_measure.h"
#include "sys_protocol.h"
#include "drv_buzzer.h"
/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */

enum sys_manage_status_t
{
  SYS_MANAGE_ERROR = 0xFFFFFFFF,
  SYS_MANAGE_FAILED = 0x7FFFFFFF,
  SYS_MANAGE_OK = 0x3FFFFFFF
};

typedef enum
{
  SYS_MAMAGE_STATE_SLEEP = 0,
  SYS_MANAGE_STATE_IDLE,
  SYS_MANAGE_STATE_NORMAL,
  SYS_MANAGE_STATE_RECORD,
  SYS_MANAGE_STATE_SEND_PKT,
  SYS_MANAGE_STATE_ERROR,

} sys_manage_state_t;

typedef struct
{
  sys_manage_state_t current_state;
  sys_manage_state_t previous_state;

} sys_manage_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */

/**
 * @brief  Start the service control display
 *
 * @param[in]     display  pointer to sys_display_t structure for manage the display in the system
 * @param[in]     i2c      pointer to I2C handler
 *
 * @return
 *  - 0xFFFFFFFF: Error
 *  - 0X7FFFFFFF: Failed
 *  - 0X3FFFFFFF: Success
 */
uint32_t sys_manage_start_display(bsp_i2c_handle_t *i2c, uint8_t *dev_buffer);

/**
 * @brief  Start the service to collect and process signal
 *
 * @param[in]     adc           Channel attaches to sensor
 * @param[in]     tim           Timer to trigger ADC Conversion
 * @param[in]     prescaler     Prescale the clock timer source
 * @param[in]     autoreload    Set the top of counter
 * @param[in]     data_buf      Pointer to buffer that store processed data.
 *
 * @return
 *  - 0xFFFFFFFF: Error
 *  - 0x7FFFFFFF: Failed
 *  - 0x3FFFFFFF: Success
 */
uint32_t sys_manage_start_measure(bsp_adc_typedef_t *adc,
                                  bsp_tim_typedef_t *tim,
                                  uint32_t prescaler,
                                  uint32_t autoreload,
                                  double *data_buf);

/**
 * @brief       Start the serivce handle the user button
 *
 * @param[in]   gpio  Pointer point to GPIO port
 * @param[in]   pin   pin of that port
 * @param[in]   button_active_level Determine the active high or active low button
 *
 *
 * @return
 *  - 0xFFFFFFFF: Error
 *  - 0x7FFFFFFF: Failed
 *  - 0x3FFFFFFF: Success
 */
uint32_t sys_manage_start_button(GPIO_TypeDef *gpio, uint16_t pin, uint32_t button_active_level);

/**
 * @brief                 Start service to manage the UART protocol
 *
 * @param[in]     uart    Hardware UART handler
 *
 * @return
 * -  (0xFFFFFFFF)  : Error
 * -  (0x7FFFFFFF)  : Failed
 * -  (0x3FFFFFFF)  : Success
 */
uint32_t sys_manage_start_protocol(UART_HandleTypeDef *uart);

/**
 * @brief       Initialize the buzzer.
 *
 * @param[in]   buzzer         Pointer to buzzer handler.
 * @param[in]   tim            Pointer of timer buzzer handler.
 * @param[in]   pwm_channel    Channel PWM connect to buzzer.
 *
 * @attention   the valid buzzer period and duty cycle.
 * @note        Module buzzer low level trigger.
 *
 * @return
 * -  0xFFFFFFFF: Error
 * -  0x7FFFFFFF: Failed
 * -  0x3FFFFFFF: Success
 */
uint32_t sys_manage_start_buzzer(bsp_tim_typedef_t *tim, uint32_t pwm_channel);
#endif // __USER_SYS_MANAGE_H

/* End of file -------------------------------------------------------- */
