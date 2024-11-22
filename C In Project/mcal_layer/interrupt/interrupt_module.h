/*
 * interrupt_module.h
 *
 * Created: 9/8/2023 5:22:02 PM
 *  Author: 20115
 */ 


#ifndef INTERRUPT_MODULE_H_
#define INTERRUPT_MODULE_H_

/*******Includes********/
#include <avr/interrupt.h>
#include "../mcal_layer_header_files/mcal_std_types.h"

/*******macro defintions********/
#define INTERRUPT_ENABLE  1

#define INTERRUPT_DISABLE 0

#define INTERRUPT_PERIPEHRAL_STATE  INTERRUPT_ENABLE

/*******macro functions********/
#define INTERRUPT_ENABLE_FUNCTION()				 (SREG|=(1<<7))
#define INTERRUPT_DISABLE_FUNCTION()			 (SREG&=~(1<<7))
#define INT0_ENABLE_FUNCTION()					 (GICR|=(1<<6))
#define INT0_DISABLE_FUNCTION()					 (GICR&=~(1<<6))
#define INT1_ENABLE_FUNCTION()					 (GICR|=(1<<7))
#define INT1_DISABLE_FUNCTION()					 (GICR&=~(1<<7))
#define INT2_ENABLE_FUNCTION()					 (GICR|=(1<<5))
#define INT2_DISABLE_FUNCTION()					 (GICR&=~(1<<5))
#define INT0_FLAG_CLEAR_FUNCTION()				 (GIFR&=~(1<<6))
#define INT1_FLAG_CLEAR_FUNCTION()				 (GIFR&=~(1<<7))
#define INT2_FLAG_CLEAR_FUNCTION()				 (GIFR&=~(1<<5))
#define INT0_LOW_LEVEL_FUNCTION()				 (MCUCR&=~(3<<0))


#define INT0_ON_CHANGE_FUNCTION()				 (MCUCR|=(1<<0));\
												  (MCUCR&=~(1<<1))
												  
#define INT0_ON_FALLING_EDGE_FUNCTION()	     	 (MCUCR&=~(1<<0));\
												 (MCUCR|=(1<<1))
												 
#define INT0_ON_RISING_EDGE_FUNCTION()	        (MCUCR|=~(3<<0))
 
#define INT1_LOW_LEVEL_FUNCTION()				 (MCUCR&=~(3<<2))

#define INT1_ON_CHANGE_FUNCTION()				 (MCUCR|=(1<<2));\
												(MCUCR&=~(1<<3))
												
#define INT1_ON_FALLING_EDGE_FUNCTION()	        (MCUCR&=~(1<<2));\
												(MCUCR|=(1<<3))
												
#define INT1_ON_RISING_EDGE_FUNCTION()	        (MCUCR|=(3<<3))

#define INT2_ON_FALLING_EDGE_FUNCTION()	        ( MCUCSR&=~(1<<6))

#define INT2_ON_RISING_EDGE_FUNCTION()	        ( MCUCSR|=(1<<6))
  
 
/*******user data types decleration********/
typedef enum{
	interrupt_INT0=0,
	interrupt_INT1,
	interrupt_INT2,
}interrupt_external_type;
typedef enum{
	interrupt_INT0_or_INT1_low_level=0,
	interrupt_INT0_or_INT1_on_change,
	interrupt_INT0_or_INT1_falling_edge,
	interrupt_INT0_or_INT1_rising_edge,
}INT0_or_INT1_sense_control;

typedef enum{
	interrupt_INT2_falling_edge,
	interrupt_INT2_rising_edge,
}INT2_sense_control; //has minimum pulse time

typedef union{
	INT0_or_INT1_sense_control int0_or_int1;
	INT2_sense_control int2;
	}interrupt_sense_control;
	



typedef struct{
	interrupt_external_type external_int_type;
	interrupt_sense_control sense_control;
	}interrupt_external_config;
	
/*******functions decleration********/

std_return_type mcal_interrupt_external_firring(interrupt_external_config*my_interrupt);




#endif /* INTERRUPT_MODULE_H_ */