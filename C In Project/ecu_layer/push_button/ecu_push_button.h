/*
 * ecu_push_button.h
 *
 * Created: 9/2/2023 5:06:27 PM
 *  Author: 20115
 */ 


#ifndef ECU_PUSH_BUTTON_H_
#define ECU_PUSH_BUTTON_H_

/*******Includes********/
#include "../../mcal_layer/gpio/mcal_gpio.h"

/*******macro declerations and defintions ********/


/*******user data types decleration********/
typedef enum{
	push_button_activ_low=0, //pull up
	push_button_activ_high   //pull down
	}push_button_logic_type;
	
typedef enum{
	push_button_released=0, 
	push_button_pressed
}push_button_status;

typedef struct{
	push_button_logic_type connection_type;
	push_button_status status;
	gpio_pin_config  push_button_pin;
	}push_button_config;

/*******functions decleration********/
std_return_type ecu_push_button_intiallize(push_button_config* my_push_button);
std_return_type ecu_push_button_read_logic(push_button_config* my_push_button,gpio_logic*my_logic);

#endif /* ECU_PUSH_BUTTON_H_ */