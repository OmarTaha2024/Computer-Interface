/*
 * ecu_seven_segment.h
 *
 * Created: 9/5/2023 12:46:09 AM
 *  Author: 20115
 */ 


#ifndef ECU_SEVEN_SEGMENT_H_
#define ECU_SEVEN_SEGMENT_H_

/*******Includes********/
#include "../../mcal_layer/gpio/mcal_gpio.h"

/*******user data types decleration********/
typedef enum{
	seven_segment_common_anode,
	seven_segment_common_cathode
	}seven_segment_common_type;
typedef enum{
	seven_segment_first_pin=0,
	seven_segment_second_pin,
	seven_segment_third_pin,
	seven_segment_fourth_pin //seven_segment_fourth_pin=3
	}seven_segment_decoder_mcu_pins;


typedef struct{
	seven_segment_common_type seven_segment_common_mode;
	gpio_pin_config seven_segment_pins[4];
	}seven_segment_config;
	
/*******functions decleration********/
std_return_type ecu_seven_segment_intiallize(seven_segment_config* my_seven_segment,seven_segment_common_type my_mode,gpio_port port,gpio_pin starting_pin);
std_return_type ecu_seven_segment_write_number(seven_segment_config* my_seven_segment,uint8 number);

#endif /* ECU_SEVEN_SEGMENT_H_ */