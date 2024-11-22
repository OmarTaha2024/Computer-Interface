/*
 * ecu_push_button.c
 *
 * Created: 9/2/2023 5:06:46 PM
 *  Author: 20115
 */ 
#include "ecu_push_button.h"

std_return_type ecu_push_button_intiallize(push_button_config* my_push_button){
	std_return_type ret;
	if(NULL==my_push_button)
	{
		ret=NOT_OK;
	}
	else{
		my_push_button->push_button_pin.direction=input;
		mcal_gpio_pin_direction_intiallize(&my_push_button->push_button_pin);
		/*this switch case to intiallize button state but it not be updated during run time*/
		switch(my_push_button->connection_type){
			case push_button_activ_low:
				if(high==my_push_button->push_button_pin.logic)
				{
					my_push_button->status=push_button_released;
				}
				else if(low==my_push_button->push_button_pin.logic)
				{
					my_push_button->status=push_button_pressed;
				}
				break;
			case push_button_activ_high:
			if(high==my_push_button->push_button_pin.logic)
			{
				my_push_button->status=push_button_pressed;
			}
			else if(low==my_push_button->push_button_pin.logic)
			{
				my_push_button->status=push_button_released;
			}
			break;
			
		}
	}
	return ret;
}

std_return_type ecu_push_button_read_logic(push_button_config* my_push_button,gpio_logic*my_logic){
		std_return_type ret;
		if((NULL==my_push_button)||(NULL==my_logic))
		{
			ret=NOT_OK;
		}
		else{
			gpio_logic pin_logic;
			mcal_gpio_pin_input_read_logic(&my_push_button->push_button_pin,&pin_logic);
			switch (my_push_button->connection_type)
			{
				case push_button_activ_low:
				if(high==my_push_button->push_button_pin.logic) //or if(high==pin_logic)
				{
					my_push_button->status=push_button_released;
					*my_logic=high;
				}
				else if(low==my_push_button->push_button_pin.logic)
				{
					my_push_button->status=push_button_pressed;
					*my_logic=low;
				}
				break;
				case push_button_activ_high:
				if(high==my_push_button->push_button_pin.logic)
				{
					my_push_button->status=push_button_pressed;
					*my_logic=high;
				}
				else if(low==my_push_button->push_button_pin.logic)
				{
					my_push_button->status=push_button_released;
					*my_logic=low;
				}
				break;
			}
		}
		return ret;
}