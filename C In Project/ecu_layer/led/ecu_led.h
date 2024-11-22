/*
 * ecu_led.h
 *
 * Created: 8/31/2023 5:18:40 PM
 *  Author: 20115
 */ 


#ifndef ECU_LED_H_
#define ECU_LED_H_

/*******Includes********/
#include "../../mcal_layer/gpio/mcal_gpio.h"

/*******user data types decleration********/
typedef enum{
	led_off=0,
	led_on,
	}led_status;
typedef struct{
	gpio_port port:2;
	gpio_pin pin:3;
	led_status status:1;
	}led_config;

/*******functions decleration********/
std_return_type ecu_led_intiallize(led_config*);
std_return_type ecu_led_turn_on(led_config*);
std_return_type ecu_led_turn_off(led_config*);
std_return_type ecu_led_toggle(led_config*);
#endif /* ECU_LED_H_ */