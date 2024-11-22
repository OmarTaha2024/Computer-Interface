/*
 * LCD.h
 *
 * Created: 10/3/2023 10:19:46 PM
 *  Author: 20115
 
 
  this driver is for 16*8 4-bit LCD 
  /*
  first of  all define the LCD_MODE with suitable mode 
  edit lcd_config struct
  
  code:
lcd_config my_lcd_main={
	.lcd_data_pins[0].port=port?,
	.register_select_pin.pin=pin?,
	.read_write_pin.pin=pin?,
	.enable_pin.pin=pin?,
};
  
  
  
  
  */
 
 
 //this driver is for 16*2 LCD 
 
 
 /*
		ecu_lcd_intiallize(&my_lcd_main,portD,portC);
		ecu_lcd_write_command_or_data_intiallize(intiallize_command,&my_lcd_main);
		ecu_lcd_write_command_or_data_intiallize(data,&my_lcd_main);
		ecu_lcd_8bit_write_on_data_pins(&my_lcd_main,'1');
		ecu_lcd_8bit_write_on_data_pins(&my_lcd_main,'2');
		ecu_lcd_8bit_write_specfic_command(&my_lcd_main,LCD_CURSOR_TO_NEXT_LINE);
		ecu_lcd_8bit_write_command_or_data_intiallize(data,&my_lcd_main);
		ecu_lcd_8bit_write_on_data_pins(&my_lcd_main,'1');
		ecu_lcd_8bit_write_on_data_pins(&my_lcd_main,'2');
 */
  /*
  in case of 4-bit you will need to intiallize
   my_lcd->lcd_data_pins[0].pin
   
   
  */



#ifndef LCD_H_
#define LCD_H_

#include "../../mcal_layer/gpio/mcal_gpio.h"
#include <util/delay.h>

/***define**/
#define LCD_INSTRUCTION_SELECT		0
#define LCD_DATA_SELECT				1

#define LCD_WRITE_SELECT			0
#define LCD_READ_SELECT				1



/***************commands*************/
#define LCD_8_BIT_DATA_2_ROWS							0x38
#define LCD_SCREEN_ON_CURSOR_DISPLAY_COMMAND			0x0D
#define LCD_SCREEN_ON_CURSOR_NOT_DISPLAY_COMMAND		0x0C
#define LCD_SCREEN_OFF_COMMAND							0x80
#define LCD_CURSOR_HOME									0x02
#define LCD_CLEAR_DISPLAY								0x01
#define LCD_CURSOR_AUTO_INCREMENT						0x06
#define LCD_CURSOR_TO_NEXT_LINE							0xC0
#define LCD_4_BIT_DATA_2_ROWS_FIRST_INTIALLIZE			0x33
#define LCD_4_BIT_DATA_2_ROWS_SECOND_INTIALLIZE			0x32
#define LCD_4_BIT_MATRIX_INTIALLIZE						0x28
#define LCD_MODE										LCD_8_bit_mode

/*******user data types decleration********/
typedef enum{
	intiallize_command=0,
	data,
	}data_or_command;
typedef enum{
	LCD_8_bit_mode=0,
	LCD_4_bit_mode
	}LCD_mode;
	
typedef struct{
	gpio_pin_config register_select_pin;
	gpio_pin_config	read_write_pin;
	gpio_pin_config	enable_pin;
	//if LCD_MODE==LCD_4_bit_mode
	//gpio_pin_config lcd_data_pins[4];
	//else
	gpio_pin_config lcd_data_pins[8];
	//#endif
	}lcd_config;

/*******functions decleration********/

std_return_type ecu_lcd_intiallize(lcd_config*my_lcd,gpio_port data_port,gpio_port control_port);   /*make all pins connected to MCU as output*/
//std_return_type ecu_lcd_4bit_intiallize(lcd_config*my_lcd,gpio_port data_port,gpio_port control_port);
std_return_type ecu_lcd_write_command_or_data_intiallize(data_or_command sended_data_type,lcd_config*my_lcd);

std_return_type ecu_lcd_8bit_write_on_data_pins(lcd_config*my_lcd,uint8 data);
std_return_type ecu_lcd_4bit_write_on_data_pins(lcd_config*my_lcd,uint8 data);


std_return_type ecu_lcd_8bit_string_write(lcd_config*my_lcd,uint8*string);
std_return_type ecu_lcd_4bit_string_write(lcd_config*my_lcd,uint8*string);


std_return_type ecu_lcd_8bit_write_specfic_command(lcd_config*my_lcd,uint8 command);
std_return_type ecu_lcd_4bit_write_specfic_command(lcd_config*my_lcd,uint8 command);
#endif /* LCD_H_ */