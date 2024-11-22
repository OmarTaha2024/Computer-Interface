/*
 * main.h
 *
 * Created: 8/31/2023 5:20:24 PM
 *  Author: 20115
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL			/* Define CPU Frequency e.g. here 1MHz */

/*******Includes********/

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "ecu_layer/led/ecu_led.h"
#include "ecu_layer/seven_segment/ecu_seven_segment.h"
#include "ecu_layer/LCD/LCD.h"
#include "ecu_layer/keypad/ecu_keypad.h"
#include "ecu_layer/push_button/ecu_push_button.h"
#include "mcal_layer/interrupt/interrupt_module.h"
#include "mcal_layer/ADC/ADC_module.h"
#include "mcal_layer/timer0/timer0.h"
#include "mcal_layer/USART/USART.h"
#include "mcal_layer/I2C/I2C.h"
#include "mcal_layer/PWM/PWM.h"
#include "intiallization.h"
uint16 getvalue(uint8);
 uint16 get_temp_value(uint16 reg_val);
void auto_temp_decrease();
void auto_temp_increase();
void intiallize_timer();
void temp_status_display();
void auto_mode_handle_and_lcd_status_update();
void temp_to_string(uint8 str[], uint16);
void toggle_led();
#endif /* MAIN_H_ */