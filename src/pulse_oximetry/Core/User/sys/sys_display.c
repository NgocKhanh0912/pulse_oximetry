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
#define MAX_WIDTH (SSD1306_WIDTH - 1)
#define MAX_HEIGHT (SSD1306_HEIGHT - 1)
#define GRAPH_HEIGHT (45)
#define GRAPH_WIDTH (MAX_WIDTH)
/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
static char s_heart_rate[18] = "HeartRate: --- bpm";
static char s_notifications[11] = "Noti";
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
  drv_ssd1306_write_string(&(display->screen),
                           s_heart_rate,
                           Font_6x8,
                           DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_draw_bitmap(&(display->screen),
                          MAX_WIDTH - BITMAP_WIDTH,
                          0,
                          heart_icon,
                          BITMAP_WIDTH,
                          BITMAP_HEIGHT,
                          DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_draw_rectangle(&(display->screen),
                             0,
                             MAX_HEIGHT - GRAPH_HEIGHT,
                             MAX_WIDTH,
                             MAX_HEIGHT - 9,
                             DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen),
                         0,
                         MAX_HEIGHT - BITMAP_HEIGHT + 1);
  drv_ssd1306_write_string(&(display->screen),
                           s_notifications,
                           Font_6x8,
                           DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen),
                         MAX_WIDTH - 6 * 5 * 2 - 2, // Number of chars in s_high_threshold
                         MAX_HEIGHT - BITMAP_HEIGHT + 1);
  drv_ssd1306_write_string(&(display->screen),
                           s_high_threshold,
                           Font_6x8,
                           DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen),
                         MAX_WIDTH - 6 * 5, // Number of chars in s_low_threshold
                         MAX_HEIGHT - BITMAP_HEIGHT + 1);
  drv_ssd1306_write_string(&(display->screen),
                           s_low_threshold,
                           Font_6x8,
                           DRV_SSD1306_COLOR_WHITE);
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
  drv_ssd1306_set_cursor(&(display->screen),
                         0,
                         0);
  drv_ssd1306_write_string(&(display->screen),
                           s_heart_rate,
                           Font_6x8,
                           DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  // Return
  return SYS_DISPLAY_OK;
}

uint32_t sys_display_update_threshold(sys_display_t *display, uint8_t *threshold)
{
  // Check parameters
  __ASSERT((display != NULL), SYS_DISPLAY_ERROR);
  __ASSERT((threshold != NULL), SYS_DISPLAY_ERROR);
  // Operation
  char low[4];
  char high[4];
  uint8_t low_bytes = sprintf(low, "%03d", (*(threshold) < *(threshold + 1) ? *(threshold) : *(threshold + 1)));
  uint8_t high_bytes = sprintf(high, "%03d", (*(threshold) > *(threshold + 1) ? *(threshold) : *(threshold + 1)));
  memcpy(s_low_threshold + 2, low, low_bytes);
  memcpy(s_high_threshold + 2, high, high_bytes);
  drv_ssd1306_set_cursor(&(display->screen), 123 - 6 * 5 * 2 - 2, 55);
  drv_ssd1306_write_string(&(display->screen), s_high_threshold, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_set_cursor(&(display->screen), 123 - 6 * 5, 55);
  drv_ssd1306_write_string(&(display->screen), s_low_threshold, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  // Return
  return SYS_DISPLAY_OK;
}

uint32_t sys_display_show_noti(sys_display_t *display, char *noti)
{
  // Check parameters
  __ASSERT((display != NULL), SYS_DISPLAY_ERROR);
  __ASSERT((noti != NULL), SYS_DISPLAY_ERROR);
  // Operation
  drv_ssd1306_set_cursor(&(display->screen), 0, 55);
  drv_ssd1306_write_string(&(display->screen), "          ", Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  drv_ssd1306_set_cursor(&(display->screen), 0, 55);
  drv_ssd1306_write_string(&(display->screen), noti, Font_6x8, DRV_SSD1306_COLOR_WHITE);
  drv_ssd1306_update_screen(&(display->screen));
  // Return
  return SYS_DISPLAY_OK;
}

uint32_t sys_display_clear_all(sys_display_t *display)
{
  // Check parameters
  __ASSERT((display != NULL), SYS_DISPLAY_ERROR);
  // Operation
  display->heart_rate = 0;
  display->threshold_buf = NULL;
  // Terminate screen properties
  display->screen.i2c = NULL;
  display->screen.address = NULL;
  display->screen.buffer = NULL;
  display->screen.size.height = 0;
  display->screen.size.width = 0;
  // Return
  return SYS_DISPLAY_OK;
}
/* Private definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */
