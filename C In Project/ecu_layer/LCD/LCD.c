/*
 * LCD.c
 *
 * Created: 10/3/2023 10:19:37 PM
 *  Author: 20115
 */ 
#include "LCD.h"

static std_return_type ecu_lcd_8bit_command_intiallize_config(lcd_config*my_lcd);
static std_return_type ecu_lcd_4bit_command_intiallize_config(lcd_config*my_lcd);

std_return_type ecu_lcd_intiallize(lcd_config*my_lcd,gpio_port data_port,gpio_port control_port)
{
	std_return_type ret=OK;
	if(NULL==my_lcd)
	{
		ret=NOT_OK;
	}
	else{
		#if LCD_MODE==LCD_4_bit_mode
				my_lcd->register_select_pin.port=control_port;
				my_lcd->register_select_pin.direction=output;
				mcal_gpio_pin_direction_intiallize(&(my_lcd->register_select_pin));
				
				my_lcd->read_write_pin.port=control_port;
				my_lcd->read_write_pin.direction=output;
				mcal_gpio_pin_direction_intiallize(&(my_lcd->read_write_pin));
				
				my_lcd->enable_pin.port=control_port;
				
				my_lcd->enable_pin.direction=output;
				mcal_gpio_pin_direction_intiallize(&(my_lcd->enable_pin));
			//uint8 current_pin_index=3;
			for(uint8 data_pin_index=0;data_pin_index<4;data_pin_index++)
			{
				my_lcd->lcd_data_pins[data_pin_index].port=data_port;
				my_lcd->lcd_data_pins[data_pin_index].pin=data_pin_index;
				my_lcd->lcd_data_pins[data_pin_index].direction=output;
				mcal_gpio_pin_direction_intiallize(&(my_lcd->lcd_data_pins[data_pin_index]));
				//current_pin_index++;
			}
		#else
		my_lcd->register_select_pin.port=control_port;
		my_lcd->register_select_pin.pin=pin0;
		my_lcd->register_select_pin.direction=output;
		mcal_gpio_pin_direction_intiallize(&(my_lcd->register_select_pin));
		
		my_lcd->read_write_pin.port=control_port;
		my_lcd->read_write_pin.pin=pin1;
		my_lcd->read_write_pin.direction=output;
		mcal_gpio_pin_direction_intiallize(&(my_lcd->read_write_pin));
		
		my_lcd->enable_pin.port=control_port;
		my_lcd->enable_pin.pin=pin2;
		my_lcd->enable_pin.direction=output;
		mcal_gpio_pin_direction_intiallize(&(my_lcd->enable_pin));
		for(uint8 data_pin_index=0;data_pin_index<8;data_pin_index++)
		{
			my_lcd->lcd_data_pins[data_pin_index].port=data_port;
			my_lcd->lcd_data_pins[data_pin_index].pin=data_pin_index;
			my_lcd->lcd_data_pins[data_pin_index].direction=output;
			mcal_gpio_pin_direction_intiallize(&(my_lcd->lcd_data_pins[data_pin_index]));
		}
		#endif
	}
	return ret;
}


std_return_type ecu_lcd_write_command_or_data_intiallize(data_or_command sended_data_type,lcd_config*my_lcd)
{
	std_return_type ret=OK;
	if(NULL==my_lcd)
	{
		ret=NOT_OK;
	}
	else{
		my_lcd->read_write_pin.logic=LCD_WRITE_SELECT;
		switch(sended_data_type)
		{
			case intiallize_command:
			my_lcd->register_select_pin.logic=LCD_INSTRUCTION_SELECT;
			mcal_gpio_pin_output_write_logic(&(my_lcd->register_select_pin),my_lcd->register_select_pin.logic);
			my_lcd->read_write_pin.logic=LCD_WRITE_SELECT;
			mcal_gpio_pin_output_write_logic(&(my_lcd->read_write_pin),my_lcd->read_write_pin.logic);
			my_lcd->enable_pin.logic=high;
			mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
			#if LCD_MODE==LCD_4_bit_mode
			ecu_lcd_4bit_command_intiallize_config(my_lcd);
			#else
			ecu_lcd_8bit_command_intiallize_config(my_lcd);
			//ecu_lcd_8bit_command_intiallize_config(my_lcd->lcd_data_pins[0].port);
			#endif
			break;
			
			case data:
			my_lcd->register_select_pin.logic=LCD_DATA_SELECT;
			mcal_gpio_pin_output_write_logic(&(my_lcd->register_select_pin),my_lcd->register_select_pin.logic);
			my_lcd->read_write_pin.logic=LCD_WRITE_SELECT;
			mcal_gpio_pin_output_write_logic(&(my_lcd->read_write_pin),my_lcd->read_write_pin.logic);
			break;
			
			default:
			ret=NOT_OK;
			break;
		}
		_delay_ms(20);
	}
	return ret;
}

std_return_type ecu_lcd_8bit_write_on_data_pins(lcd_config*my_lcd,uint8 data)
{
	std_return_type ret=OK;

	switch (my_lcd->lcd_data_pins[0].port)
	{
		case portA:
		PORTA=data;
		break;
		case portB:
		PORTB=data;
		break;
		case portC:
		PORTC=data;
		break;
		case portD:
		PORTD=data;
		break;
		default:
		ret=NOT_OK;
		break;
	}
	my_lcd->enable_pin.logic=high;
	mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
	_delay_ms(1);
	my_lcd->enable_pin.logic=low;
	mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
	_delay_ms(1);
	return ret;
}

std_return_type ecu_lcd_8bit_write_specfic_command(lcd_config*my_lcd,uint8 command)
{
	my_lcd->register_select_pin.logic=LCD_INSTRUCTION_SELECT;
	mcal_gpio_pin_output_write_logic(&(my_lcd->register_select_pin),my_lcd->register_select_pin.logic);
	my_lcd->read_write_pin.logic=LCD_WRITE_SELECT;
	mcal_gpio_pin_output_write_logic(&(my_lcd->read_write_pin),my_lcd->read_write_pin.logic);
	my_lcd->enable_pin.logic=high;
	mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
	std_return_type ret=OK;

	switch (my_lcd->lcd_data_pins[0].port)
	{
		case portA:
		PORTA=command;
		break;
		case portB:
		PORTB=command;
		break;
		case portC:
		PORTC=command;
		break;
		case portD:
		PORTD=command;
		break;
		default:
		ret=NOT_OK;
		break;
	}
	my_lcd->enable_pin.logic=high;
	mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
	_delay_ms(1);
	my_lcd->enable_pin.logic=low;
	mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
	_delay_ms(1);
	return ret;
}

std_return_type ecu_lcd_8bit_string_write(lcd_config*my_lcd,uint8*string)
{
	std_return_type ret=OK;
	if((NULL==my_lcd) || (NULL==string))
	{
		ret=NOT_OK;
	}
	else{
		for(uint8 i=0;string[i]!=0;i++)		/* Send each char of string till the NULL */
		{
			ecu_lcd_8bit_write_on_data_pins(my_lcd,string[i]);
		}
	}
	return ret;
}


static std_return_type ecu_lcd_8bit_command_intiallize_config(lcd_config*my_lcd)
{
	std_return_type ret=OK;	
	ecu_lcd_8bit_write_on_data_pins(my_lcd,LCD_8_BIT_DATA_2_ROWS);
	ecu_lcd_8bit_write_on_data_pins(my_lcd,LCD_SCREEN_ON_CURSOR_DISPLAY_COMMAND);
	ecu_lcd_8bit_write_on_data_pins(my_lcd,LCD_CURSOR_AUTO_INCREMENT);
	ecu_lcd_8bit_write_on_data_pins(my_lcd,LCD_CLEAR_DISPLAY);
	ecu_lcd_8bit_write_on_data_pins(my_lcd,LCD_CURSOR_HOME);
	_delay_ms(2);      // Wait for clear operation to complete
	return ret;
}
std_return_type ecu_lcd_4bit_write_on_data_pins(lcd_config *my_lcd,uint8 data)
{
	std_return_type ret=OK;
	
	switch (my_lcd->lcd_data_pins[0].port)
	{
		case portA:
		PORTA = (PORTA & 0x0F) | (data & 0xF0);/* Sending upper nibble */
		my_lcd->enable_pin.logic=high;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		PORTA = (PORTA & 0x0F) | (data << 4);/* Sending lower nibble */
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		break;
		case portB:
		PORTB = (PORTB & 0x0F) | (data & 0xF0);/* Sending upper nibble */
		my_lcd->enable_pin.logic=high;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		PORTB = (PORTB & 0x0F) | (data << 4);/* Sending lower nibble */
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		break;
		case portC:
		PORTC = (PORTC & 0x0F) | (data & 0xF0);/* Sending upper nibble */
		my_lcd->enable_pin.logic=high;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		PORTC = (PORTC & 0x0F) | (data << 4);/* Sending lower nibble */
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_us(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		break;
		case portD:
		PORTD = (PORTD & 0x0F) | (data & 0xF0);/* Sending upper nibble */
		my_lcd->enable_pin.logic=high;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		PORTD = (PORTD & 0x0F) | (data << 4);/* Sending lower nibble */
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		my_lcd->enable_pin.logic=low;
		mcal_gpio_pin_output_write_logic(&(my_lcd->enable_pin),my_lcd->enable_pin.logic);
		_delay_ms(1);
		break;
		default:
		ret=NOT_OK;
		break;
	}
	

	return ret;
}

static std_return_type ecu_lcd_4bit_command_intiallize_config(lcd_config*my_lcd)
{
	std_return_type ret=OK;
	_delay_ms(20);	
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_4_BIT_DATA_2_ROWS_FIRST_INTIALLIZE);
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_4_BIT_DATA_2_ROWS_SECOND_INTIALLIZE);
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_4_BIT_MATRIX_INTIALLIZE);
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_SCREEN_ON_CURSOR_DISPLAY_COMMAND);
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_CURSOR_AUTO_INCREMENT);
	ecu_lcd_4bit_write_on_data_pins(my_lcd,LCD_CLEAR_DISPLAY);
	return ret;
}