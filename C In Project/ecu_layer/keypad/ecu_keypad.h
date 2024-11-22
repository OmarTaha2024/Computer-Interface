/*
 * ecu_keypad.h
 *
 * Created: 10/8/2023 9:04:27 PM
 *  Author: 20115
 */ 


#ifndef ECU_KEYPAD_H_
#define ECU_KEYPAD_H_

/*******Includes********/
#include "../../mcal_layer/gpio/mcal_gpio.h"
#include <util/delay.h>

/*********Macro defintions****/

#define KEYPAD_ROW_NUMBER	4
#define KEYPAD_COL_NUMBER	4


/*******macro functions********/

/*******user data types decleration********/
typedef struct{
	gpio_pin_config keypad_rows[KEYPAD_ROW_NUMBER];
	gpio_pin_config keypad_cols[KEYPAD_COL_NUMBER];
	}keypad_config;

/*******functions decleration********/
std_return_type ecu_keypad_intiallize(keypad_config*my_keypad,gpio_port port,gpio_pin starting_pin);
std_return_type ecu_keypad_get_pressed_button_value(keypad_config*my_keypad,uint8*button_value);
#endif /* ECU_KEYPAD_H_ */