/*
 * ecu_led.c
 *
 * Created: 8/31/2023 5:18:29 PM
 *  Author: 20115
 */ 


/*******Includes********/
#include "ecu_led.h"
/**functions implementaion***/
std_return_type ecu_led_intiallize(led_config*my_led){
	std_return_type ret;
	if(NULL==my_led)
	{
		ret=NOT_OK;
	}
	else{
		gpio_pin_config my_pin;
		my_pin.direction=output;
		my_pin.logic=my_led->status;
		my_pin.pin=my_led->pin;
		my_pin.port=my_led->port;
		mcal_gpio_pin_direction_intiallize(&my_pin);
		mcal_gpio_pin_output_write_logic(&my_pin,my_pin.logic);
	}
	return ret;
}
std_return_type ecu_led_turn_on(led_config*my_led){
	std_return_type ret;
	if(NULL==my_led)
	{
		ret=NOT_OK;
	}
	else{
		gpio_pin_config my_pin;
		my_pin.direction=output;
		my_pin.logic=my_led->status;
		my_pin.pin=my_led->pin;
		my_pin.port=my_led->port;
		mcal_gpio_pin_direction_intiallize(&my_pin);
		mcal_gpio_pin_output_write_logic(&my_pin,high);
	}
	return ret;
}
std_return_type ecu_led_turn_off(led_config*my_led){
	std_return_type ret;
	if(NULL==my_led)
	{
		ret=NOT_OK;
	}
	else{
		gpio_pin_config my_pin;
		my_pin.direction=output;
		my_pin.logic=my_led->status;
		my_pin.pin=my_led->pin;
		my_pin.port=my_led->port;
		mcal_gpio_pin_direction_intiallize(&my_pin);
		mcal_gpio_pin_output_write_logic(&my_pin,low);
	}
	return ret;
}
std_return_type ecu_led_toggle(led_config*my_led){
	std_return_type ret;
	if(NULL==my_led)
	{
		ret=NOT_OK;
	}
	else{
		gpio_pin_config my_pin;
		my_pin.direction=output;
		my_pin.logic=my_led->status;
		my_pin.pin=my_led->pin;
		my_pin.port=my_led->port;
		mcal_gpio_pin_direction_intiallize(&my_pin);
		mcal_gpio_pin_toggle_logic(&my_pin);	
		}
	return ret;
}