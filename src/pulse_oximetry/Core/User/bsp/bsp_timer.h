/**
 * @file       bsp_timer.h
 * @copyright
 * @license
 * @version    1.0.0
 * @date       10/07/2024
 * @author     Giang Phan Truong
 *             Khanh Nguyen Ngoc
 *             Viet Hoang Xuan
 *
 * @brief      APIs of BSP timer
 *
 * @note       None
 * @example    None
 */

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef USER_BSP_BSP_TIMER_H_
#define USER_BSP_BSP_TIMER_H_

/* Includes ----------------------------------------------------------- */
#include "main.h"
/* Public defines ----------------------------------------------------- */
typedef TIM_HandleTypeDef bsp_tim_typedef_t;
/* Public enumerate/structure ----------------------------------------- */
typedef enum
{
  BSP_TIMER_ERROR = -2,
  BSP_TIMER_FAIL,
  BSP_TIMER_OK
} bsp_timer_status_t;

/* Public macros ------------------------------------------------------ */

/* Public variables --------------------------------------------------- */

/* Public function prototypes ----------------------------------------- */
/**
 * @brief       Set the prescaler for clock of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   prescale      Desired prescaler .
 *
 * @attention   the range of the prescaler and valid precaler value.
 *
 * @return      -2 if error,
 *              -1 if fail to set prescaler,
 *              0 if set prescler successfully.
 */
bsp_timer_status_t bsp_timer_set_prescaler(bsp_tim_typedef_t *htim, uint32_t prescaler);

/**
 * @brief       Set the counter period value for clock of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   autoreload    Desired counter period.
 *
 * @attention   the range of the counter (16-bit).
 *
 * @return      -2 if error,
 *              -1 if fail to set counter,
 *              0 if set counter successfully.
 */
bsp_timer_status_t bsp_timer_set_autoreload(bsp_tim_typedef_t *htim, uint32_t autoreload);

/**
 * @brief       Set pulse value for PWM of this channel.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   compare       Desired PWM pulse.
 *
 * @attention   the range of the pulse (16-bit).
 *
 * @return      -2 if error,
 *              -1 if fail to set pulse value,
 *              0 if set pulse value successfully.
 */
bsp_timer_status_t bsp_timer_set_output_compare(bsp_tim_typedef_t *htim, uint32_t tim_channel, uint32_t compare);

/**
 * @brief       Start the PWM generator on a channel of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @attention   timer initialize first.
 *
 * @return      -2 if error,
 *              -1 if fail to start PWM,
 *              0 if start PWM successfully.
 */
bsp_timer_status_t bsp_timer_start(bsp_tim_typedef_t *htim);

/**
 * @brief       Start the PWM generator on a channel of timer and enable this timer interrupt.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @attention   timer initialize first.
 *
 * @return      -2 if error,
 *              -1 if fail to start PWM,
 *              0 if start PWM successfully.
 */
bsp_timer_status_t bsp_timer_start_it(bsp_tim_typedef_t *htim);

/**
 * @brief       Stop counter on a channel of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @return      -2 if error,
 *              -1 if fail to stop that channel,
 *              0 if stop that channel successfully.
 */
bsp_timer_status_t bsp_timer_stop(bsp_tim_typedef_t *htim);

/**
 * @brief       Stop counter on a channel of timer in interrupt mode.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @return      -2 if error,
 *              -1 if fail to stop that channel,
 *              0 if stop that channel successfully.
 */
bsp_timer_status_t bsp_timer_stop_it(bsp_tim_typedef_t *htim);

/**
 * @brief       Start the PWM generator on a channel of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   tim_channel   Channel of that timer.
 *
 * @attention   timer initialize first.
 *
 * @return      -2 if error,
 *              -1 if faile to start PWM,
 *              0 if start PWM successfully.
 */
bsp_timer_status_t bsp_pwm_start(bsp_tim_typedef_t *htim, uint32_t tim_channel);

/**
 * @brief       Start the PWM generator on a channel of timer and enable this timer interrupt.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   tim_channel   Channel of that timer.
 *
 * @attention   timer initialize first.
 *
 * @return      -2 if error,
 *              -1 if faile to start PWM,
 *              0 if start PWM successfully.
 */
bsp_timer_status_t bsp_pwm_start_it(bsp_tim_typedef_t *htim, uint32_t tim_channel);

/**
 * @brief       Stop the PWM generator on a channel of timer.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   tim_channel   Channel of that timer.
 *
 * @return      -2 if error,
 *              -1 if fail to stop PWM on that channel,
 *              0 if stop PWM on that channel successfully.
 */
bsp_timer_status_t bsp_pwm_stop(bsp_tim_typedef_t *htim, uint32_t tim_channel);

/**
 * @brief       Stop the PWM generator on a channel of timer in interrupt mode.
 *
 * @param[in]   htim          Pointer of timer handler.
 * @param[in]   tim_channel   Channel of that timer.
 *
 * @return      -2 if error,
 *              -1 if fail to stop PWM on that channel,
 *              0 if stop PWM on that channel successfully.
 */
bsp_timer_status_t bsp_pwm_stop_it(bsp_tim_typedef_t *htim, uint32_t tim_channel);

/**
 * @brief       Get current SysTick value.
 *
 * @param[in]   None
 * @param[in]   None
 *
 * @return      SysTick value.
 */
uint32_t bsp_get_systick();

/**
 * @brief       Trigger the counter overflow event and handle it in BSP.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @return      -2 if error,
 *              -1 if fail to handle this event,
 *              0 if handle this event successfully.
 */
bsp_timer_status_t bsp_timer_period_elapsed_handler(bsp_tim_typedef_t *htim);

/**
 * @brief       Trigger the counter overflow event in PWM mode and handle it in BSP.
 *
 * @param[in]   htim          Pointer of timer handler.
 *
 * @return      -2 if error,
 *              -1 if fail to handle this event,
 *              0 if handle this event successfully.
 */
bsp_timer_status_t bsp_pwm_pulse_finished_handler(bsp_tim_typedef_t *htim);

#endif /* USER_BSP_BSP_TIMER_H_ */
