/*
 * ecu_seven_segment.c
 *
 * Created: 9/5/2023 12:46:24 AM
 *  Author: 20115
 */ 
#include "ecu_seven_segment.h"



std_return_type ecu_seven_segment_intiallize(seven_segment_config* my_seven_segment,seven_segment_common_type my_mode,gpio_port port,gpio_pin starting_pin){
	std_return_type ret=OK;
	if(NULL==my_seven_segment)
	{
		ret=NOT_OK;
	}
	else{
		my_seven_segment->seven_segment_common_mode=my_mode;
		uint8 intial_pin=starting_pin;
		for(uint8 index=seven_segment_first_pin ; index<=seven_segment_fourth_pin ; index++)
		{
			my_seven_segment->seven_segment_pins[index].direction=output;
			my_seven_segment->seven_segment_pins[index].pin=intial_pin;
			if(PIN_MAX_NUMBER<intial_pin)
			{
				intial_pin=0;
				port++;
			}
			else{
				intial_pin++;
			}
			
			my_seven_segment->seven_segment_pins[index].port=port;
			mcal_gpio_pin_direction_intiallize(& my_seven_segment->seven_segment_pins[index]);
		}
		
	}
	return ret;
}
std_return_type ecu_seven_segment_write_number(seven_segment_config* my_seven_segment,uint8 number){
	std_return_type ret=OK;
	if(NULL==my_seven_segment)
	{
		ret=NOT_OK;
	}
	else{
		if(number<10)
		{
			if(seven_segment_common_cathode==my_seven_segment->seven_segment_common_mode)
			{
				//uint8 seven_segment_array_decode[10]={0b0000,0b0001,0b0010,0b0011,0b0100,0b0101,0b0110,0b0111,0b1000,0b1001};
					uint8 shift_pos=0;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_first_pin]), (number>>shift_pos) & 0x01);
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_second_pin]), (number>>shift_pos) & 0x01);
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_third_pin]), (number>>shift_pos) & 0x01);
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_fourth_pin]), (number>>shift_pos) & 0x01);
				shift_pos++;
				
			}
			else if (seven_segment_common_anode==my_seven_segment->seven_segment_common_mode)
			{
				uint8 shift_pos=0;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_first_pin]), ((number>>shift_pos) & 0x01));
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_second_pin]), ((number>>shift_pos) & 0x01));
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_third_pin]), ((number>>shift_pos) & 0x01));
				shift_pos++;
				ret = mcal_gpio_pin_output_write_logic(&(my_seven_segment->seven_segment_pins[seven_segment_fourth_pin]), ((number>>shift_pos) & 0x01));
				shift_pos++;
				
			}
		}
		
	}
	return ret;
}