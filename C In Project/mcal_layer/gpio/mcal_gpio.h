/*
 * mcal_gpio.h
 *
 * Created: 8/31/2023 5:06:01 PM
 *  Author: 20115
 */ 


#ifndef MCAL_GPIO_H_
#define MCAL_GPIO_H_



/*******Includes********/
#include <avr/io.h>
#include "../mcal_layer_header_files/mcal_std_types.h"
#include "../mcal_layer_header_files/device_config.h"

/*******macro declerations and defintions ********/
#define BIT_MASK (uint8)1
#define POT_MASK (uint8)0xff
#define PORT_MAX_NUMBER (uint8)4
#define PIN_MAX_NUMBER (uint8)7

/*******macro functions ********/
#define  SET_BIT(REGISTER,PIN_POS)       (REGISTER|=(BIT_MASK<<PIN_POS))
#define  MASK_BIT(REGISTER,PIN_POS)      (REGISTER&=(BIT_MASK<<PIN_POS))
#define  CLEAR_BIT(REGISTER,PIN_POS)     (REGISTER&=~(BIT_MASK<<PIN_POS))
#define  TOGGLE_BIT(REGISTER,PIN_POS)    (REGISTER^=(BIT_MASK<<PIN_POS))
#define  READ_BIT(REGISTER,PIN_POS)      ((REGISTER>>PIN_POS)&BIT_MASK)
/******* data types defenitions ********/
typedef  uint8 gpio_port_number;

/******* data declerations ********/
typedef enum{
	portA=0,
	portB,
	portC,
	portD,
	}gpio_port;
typedef enum{
	pin0=0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7,
}gpio_pin;
typedef enum{
	input=0,
	output,
	}gpio_direction;
typedef enum{
	low=0,
	high,
}gpio_logic;

typedef struct{
	gpio_port port:2;
	gpio_pin pin:3;
	gpio_direction direction:1;
	gpio_logic logic:1;
	}gpio_pin_config;
	


/******* functions declerations ********/
std_return_type mcal_gpio_pin_direction_intiallize(gpio_pin_config*);
std_return_type mcal_gpio_pin_toggle_logic(gpio_pin_config*);
std_return_type mcal_gpio_pin_get_direction(gpio_pin_config*,gpio_direction*);
std_return_type mcal_gpio_pin_output_write_logic(gpio_pin_config*my_gpio_pin ,gpio_logic my_logic);
std_return_type mcal_gpio_pin_input_read_logic(gpio_pin_config*,gpio_logic*);
std_return_type mcal_gpio_port_direction_intiallize(gpio_port_number,gpio_direction direction);
std_return_type mcal_gpio_port_get_direction(gpio_port_number,gpio_direction*);
std_return_type mcal_gpio_port_output_write_logic(gpio_port_number,gpio_logic);
std_return_type mcal_gpio_port_read_logic(gpio_port_number,gpio_logic*);


#endif /* MCAL_GPIO_H_ */