/**
 * @file       sys_display.c
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    0.0.1
 * @date       2024-08-03
 * @author     Viet Hoang Xuan
 *             Giang Phan Truong
 *             Khanh Nguyen Ngoc
 *
 * @brief      <A brief description of the content of the file>
 *
 * @note
 * @example
 * @example
 */

/* Includes ----------------------------------------------------------- */
#include "sys_display.h"
#include "common.h"
#include "heart_icon.h"
#include <string.h>
#include <stdlib.h>
/* Private defines ---------------------------------------------------- */

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
static char s_heart_rate[18] = "HeartRate: --- bpm";
static char s_notifications[5] = "Noti";
static char s_high_threshold[6] = "H:---";
static char s_low_threshold[6] = "L:---";
/* Private function prototypes ---------------------------------------- */

/* Function definitions ----------------------------------------------- */
uint32_t sys_display_init(sys_display_t *display, bsp_i2c_handle_t *i2c, uint8_t *dev_buffer)
{
  // Check parameters
  __ASSERT((display != NULL), SYS_DISPLAY_OK);
  __ASSERT((i2c != NULL), SYS_DISPLAY_OK);
  // Initialize UI
  drv_ssd1306_init(&(display->screen),
                   i2c,
                   SSD1306_I2C_ADDRESS,
                   dev_buffer,
                   SSD1306_WIDTH,
                   SSD1306_HEIGHT);
  drv_ssd1306_write_string(&(display->screen), s_heart_rate, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_draw_bitmap(&(display->screen), 121, 0, heart_icon, 9, 9, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_draw_rectangle(&(display->screen), 0, 9, 127, 54, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen), 0, 55);
  drv_ssd1306_write_string(&(display->screen), s_notifications, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen), 123 - 6 * 5 * 2 - 2, 55); // Set position for High threshold
  drv_ssd1306_write_string(&(display->screen), s_high_threshold, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen), 123 - 6 * 5, 55); // Set position for Low threshold
  drv_ssd1306_write_string(&(display->screen), s_low_threshold, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  // Return
  return SYS_DISPLAY_OK;
}

uint32_t sys_display_update_heart_rate(sys_display_t *display, uint8_t heart_rate)
{
  // Check parameters
  __ASSERT((display != NULL), SYS_DISPLAY_OK);
  // Operation
  char heart_rate_update[4];
  uint8_t bytes = sprintf(heart_rate_update, "%03d", heart_rate);
  memcpy(s_heart_rate + 11, heart_rate_update, bytes);
  drv_ssd1306_set_cursor(&(display->screen), 0, 0);
  drv_ssd1306_write_string(&(display->screen), s_heart_rate, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  // Return
  return SYS_DISPLAY_OK;
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
