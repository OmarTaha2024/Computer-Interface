/*
 * ecu_keypad.c
 *
 * Created: 10/8/2023 9:04:40 PM
 *  Author: 20115
 */ 
#include "ecu_keypad.h"

static const uint8 keypad_array[KEYPAD_ROW_NUMBER][KEYPAD_COL_NUMBER]={
																		{'7','8','9','/'},	
																		{'4','5','6','*'},
																		{'1','2','3','-'},
																		{'#','0','=','+'}																			
																		};
																		
std_return_type ecu_keypad_intiallize(keypad_config*my_keypad,gpio_port port,gpio_pin starting_pin)
{
	std_return_type ret=OK;
	if(NULL==my_keypad)
	{
		ret=NOT_OK;
	}
	else{
		uint8 row_index=0;
		uint8 col_index=0;
		uint8 current_pin_number=starting_pin;
		for(row_index=0;row_index<KEYPAD_ROW_NUMBER;row_index++)
		{
			my_keypad->keypad_rows[row_index].direction=output;
			my_keypad->keypad_rows[row_index].pin=current_pin_number;
			my_keypad->keypad_rows[row_index].port=port;
			current_pin_number++;
			if(PIN_MAX_NUMBER==current_pin_number)
			{
				current_pin_number=pin0;
				port++;
			}
			mcal_gpio_pin_direction_intiallize(&(my_keypad->keypad_rows[row_index]));
			mcal_gpio_pin_output_write_logic(&(my_keypad->keypad_rows[row_index]),low);
		}
		
		for(col_index=0;col_index<KEYPAD_COL_NUMBER;col_index++)
		{
			my_keypad->keypad_cols[col_index].direction=input;
			my_keypad->keypad_cols[col_index].pin=current_pin_number;
			current_pin_number++;
			if(PIN_MAX_NUMBER==current_pin_number)
			{
				current_pin_number=pin0;
				port++;
			}
			my_keypad->keypad_cols[col_index].port=port;
			mcal_gpio_pin_direction_intiallize(&(my_keypad->keypad_cols[col_index]));
		}
		
	}
	return ret;
}
std_return_type ecu_keypad_get_pressed_button_value(keypad_config*my_keypad,uint8*button_value)
{
	
	std_return_type ret=OK;
	gpio_logic my_logic;
	if((NULL==my_keypad)||(NULL==button_value))
	{
		ret=NOT_OK;
	}
	else{
		uint8 row_index=0;
		uint8 row_looping=0;
		uint8 col_index=0;
		for (row_index=0;row_index<KEYPAD_ROW_NUMBER;row_index++)
		{
			for (row_looping=0;row_looping<KEYPAD_ROW_NUMBER;row_looping++)
			{
				mcal_gpio_pin_output_write_logic(&(my_keypad->keypad_rows[row_looping]),low);
			}
			mcal_gpio_pin_output_write_logic(&(my_keypad->keypad_rows[row_index]),high);
		_delay_ms(20);
		for(col_index=0;col_index<KEYPAD_COL_NUMBER;col_index++)
		{
			mcal_gpio_pin_input_read_logic(&(my_keypad->keypad_rows[col_index]),&my_logic);
			if (high==my_logic)
			{
				*button_value=keypad_array[row_index][col_index];
			}
		}
	}
		
	}
	return ret;
}