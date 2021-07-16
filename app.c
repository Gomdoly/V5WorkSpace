/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/
#include "blink_pwm_app.h"
#include "sl_button.h"
#include "sl_simple_button.h"

extern const sl_button_t sl_button_btn0;
uint8_t blinking_max_period=0;
/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  blink_pwm_init();
}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  blink_pwm_process_action();
//  sl_button_on_change(&sl_button_btn0);
}



/***************************************************************************//**
 * Callback on button change.
 ******************************************************************************/
void sl_button_on_change(const sl_button_t *handle)
{
  if (sl_button_get_state(handle) == SL_SIMPLE_BUTTON_PRESSED) {
    if (&sl_button_btn0 == handle) {
//      sl_led_toggle(&LED_INSTANCE_0);
         if(blinking_max_period>=250)
           blinking_max_period = 0;
         else
           blinking_max_period+=50;
    }
  }
}
