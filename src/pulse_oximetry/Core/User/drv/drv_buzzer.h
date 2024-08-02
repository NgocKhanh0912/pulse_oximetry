/**
 * @file       drv_buzzer.h
 * @copyright
 * @license
 * @version    1.0.0
 * @date       31/07/2024
 * @author     Giang Phan Truong
 *             Khanh Nguyen Ngoc
 *             Viet Hoang Xuan
 *
 * @brief      Driver for interfacing with the passive buzzer
 *
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef USER_DRV_DRV_BUZZER_H_
#define USER_DRV_DRV_BUZZER_H_

/* Includes ----------------------------------------------------------- */
#include "bsp_timer.h"
#include "sound_effects.h"
#include <stdbool.h>

/* Public defines ----------------------------------------------------- */

/* Public enumerate/structure ----------------------------------------- */
enum drv_buzzer_status_t
{
  DRV_BUZZER_FAIL = 0xFFFFFFFF,
  DRV_BUZZER_ERROR = 0x7FFFFFFF,
  DRV_BUZZER_OK = 0x3FFFFFFF
};

typedef struct __attribute__((__packed__))
{
  bsp_tim_typedef_t *htim;
  uint32_t pwm_channel;
  uint32_t prescaler;
  uint16_t period;
  uint16_t duty_cycle;
} drv_buzzer_tim_config_t;

typedef struct __attribute__((__packed__))
{
  drv_buzzer_tim_config_t config;
  sound_effect_t *sound_effect;
  uint32_t note_nums;
  bool active;
} drv_buzzer_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief       Inititialize the buzzer.
 *
 * @param[in]   buzzer         Pointer to buzzer handler.
 * @param[in]   tim            Pointer of timer buzzer handler.
 * @param[in]   pwm_channel    Channel PWM connect to buzzer.
 *
 * @attention   the valid buzzer period and duty cycle.
 * @note        Module buzzer low level trigger.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_init(drv_buzzer_t *buzzer,
                         bsp_tim_typedef_t *tim,
                         uint32_t pwm_channel);

/**
 * @brief       Set the buzzer on-time.
 *
 * @param[in]   buzzer                Pointer to buzzer handler.
 * @param[in]   sound_effect_buf      Pointer to sound effect buffer.
 *
 * @note        sound_effect_buf contains the notes for sound effect.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_set_sound_effect(drv_buzzer_t *buzzer, sound_effect_t *sound_effect_buf);

/**
 * @brief       Buzzer plays the Windows 10 Error sound.
 *
 * @param[in]   buzzer     Pointer to buzzer handler.
 *
 * @note        Devs can change the effect in buzzer_effect.h.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_sound_system_fail(drv_buzzer_t *buzzer);

/**
 * @brief       Buzzer plays the "beep beep" sound.
 *
 * @param[in]   buzzer      Pointer to buzzer handler.
 *
 * @note        Devs can change the effect in buzzer_effect.h.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_sound_alert(drv_buzzer_t *buzzer);

/**
 * @brief       Enable the buzzer.
 *
 * @param[in]   buzzer                Pointer to buzzer handler.
 *
 * @note        Should be configured before use this function.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_enable(drv_buzzer_t *buzzer);

/**
 * @brief       Disable the buzzer.
 *
 * @param[in]   buzzer                Pointer to buzzer handler.
 *
 * @note        Should be configuared before use this function.
 *
 * @return      drv_buzzer_status_t value.
 */
uint32_t drv_buzzer_disable(drv_buzzer_t *buzzer);

#endif /* USER_DRV_DRV_BUZZER_H_ */