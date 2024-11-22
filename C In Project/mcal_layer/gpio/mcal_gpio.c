/*
 * mcal_gpio.c
 *
 * Created: 8/31/2023 5:06:34 PM
 *  Author: 20115
 */ 
#include "mcal_gpio.h"
volatile uint8 *gpio_ddr_reg[PORT_MAX_NUMBER]={&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8 *gpio_port_reg[PORT_MAX_NUMBER]={&PORTA,&PORTB,&PORTC,&PORTD};
volatile uint8 *gpio_pin_reg[PORT_MAX_NUMBER]={&PINA,&PINB,&PINC,&PIND};

std_return_type mcal_gpio_pin_direction_intiallize(gpio_pin_config* my_gpio_pin)
{
	std_return_type ret=OK;
	if(NULL==my_gpio_pin)
	{
		ret=NOT_OK;
	}
	else{
		if((PIN_MAX_NUMBER<my_gpio_pin->pin)||(PORT_MAX_NUMBER<my_gpio_pin->port))
		{
			ret=NOT_OK;
		}
		
		else{
			switch(my_gpio_pin->direction)
				{
					case input:
					CLEAR_BIT(*gpio_ddr_reg[my_gpio_pin->port],my_gpio_pin->pin);
					break;
					case output:
					SET_BIT(*gpio_ddr_reg[my_gpio_pin->port],my_gpio_pin->pin);
					break;
				}
		}
	}
	return ret;
}
std_return_type mcal_gpio_pin_get_direction(gpio_pin_config* my_gpio_pin,gpio_direction* my_direction)
{
	std_return_type ret=OK;
	if((NULL==my_gpio_pin) || (NULL==my_direction))
	{
		ret=NOT_OK;
	}
	else{
		*my_direction=my_gpio_pin->direction;
	}
	return ret;
	
}
std_return_type mcal_gpio_pin_output_write_logic(gpio_pin_config*my_gpio_pin ,gpio_logic my_logic)
{
	std_return_type ret=OK;
	if((NULL==my_gpio_pin))
	{
		ret=NOT_OK;
	}
	else{
		switch(my_logic)
		{
			case low:
			CLEAR_BIT(*gpio_port_reg[my_gpio_pin->port],my_gpio_pin->pin);
			break;
			case high:
			SET_BIT(*gpio_port_reg[my_gpio_pin->port],my_gpio_pin->pin);
			break;
		}
	}
	return ret;
}
std_return_type mcal_gpio_pin_input_read_logic(gpio_pin_config*my_gpio_pin,gpio_logic*my_logic)
{
	std_return_type ret=OK;
	if((NULL==my_gpio_pin)||(NULL==my_logic))
	{
		ret=NOT_OK;
	}
	else{
		*my_logic=READ_BIT(*gpio_pin_reg[my_gpio_pin->port],my_gpio_pin->pin);
		if(high==*my_logic)
		{
			my_gpio_pin->logic=high;
		}
		else if(low==*my_logic)
		{
			my_gpio_pin->logic=low;
		}
	}
	return ret;
}
std_return_type mcal_gpio_pin_toggle_logic(gpio_pin_config*my_gpio_pin)
{
	{
		std_return_type ret=OK;
		if((NULL==my_gpio_pin))
		{
			ret=NOT_OK;
		}
		else{
			
				TOGGLE_BIT(*gpio_port_reg[my_gpio_pin->port],my_gpio_pin->pin);
		}
		return ret;
	}
}

std_return_type mcal_gpio_port_direction_intiallize(gpio_port_number port,gpio_direction direction)
{
	std_return_type ret=OK;
	if(PORT_MAX_NUMBER<port)
	{
		ret=NOT_OK;
	}
	
	else{
		switch(direction)
		{
			case input:
			for (uint8 index=0;index<=PIN_MAX_NUMBER;index++)
			{
				CLEAR_BIT(*gpio_ddr_reg[port],index);
			}
			break;
			case output:
			for (uint8 index=0;index<=PIN_MAX_NUMBER;index++)
			{
				SET_BIT(*gpio_ddr_reg[port],index);
			}
			break;
		}
	}
	return ret;
}
std_return_type mcal_gpio_port_get_direction(gpio_port_number,gpio_direction*);
std_return_type mcal_gpio_port_output_write_logic(gpio_port_number,gpio_logic);
std_return_type mcal_gpio_port_read_logic(gpio_port_number,gpio_logic*);