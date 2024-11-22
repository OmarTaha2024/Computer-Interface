/*
 * timer0.h
 *
 * Created: 9/14/2023 11:09:06 PM
 *  Author: 20115
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

/*******Includes********/
//#include <avr/io.h>
#include "../interrupt/interrupt_module.h"
#include "../mcal_layer_header_files/mcal_std_types.h"

/*******macro defintions********/
#define  TIMER0_REGISTER_SIZE		8
#define  TIMER0_FLAG_IS_SET			1
#define  TIMER0_FLAG_IS_CLEARED     0

 /*******macro functions********/
#define TIMER0_TIMER_MODE_FLAG_STATE()			(TIFR&=(1<<TOV0))
#define TIMER0_TIMER_MODE_CLEAR_FLAG()			(TIFR|=(1<<TOV0)) //cleared by write logic 1
#define TIMER0_TIMER_MODE_COMPLETED()			(TIFR&(1<<TOV0))==1
#define TIMER0_TIMER_MODE_RUNNING()				(TIFR&(1<<TOV0))==0
#define TIMER0_COMPARE_MODE_RUNNING()				(TIFR&(1<<OCF0))==0
#define TIMER0_COMPARE_MATCH_MODE_DONE()			(TIFR&(1<<OCF0)==1)
#define TIMER0_COMPARE_MATCH_MODE_NOT_DONE()		(TIFR&(1<<OCF0)==0)
#define TIMER0_COMPARE_MODE_CLEAR_FLAG()			(TIFR|=(1<<OCF0))
//compare mode
#define TIMER0_COMPARE_MODE_FORCE_OUTPUT_COMPARE()		(TCCR0|=(1<<FOC0)) //don't cause interrupt or clear value in timer
// if we in fast PWM or PWM there is no toggle 
#define TIMER0_COMPARE_MODE_TOGGLE_OUTPUT()				TCCR0|=(1<<COM00);\
														TCCR0&=~(1<<COM01)
//clear on compare set at bottom
#define TIMER0_COMPARE_MODE_CLEAR_OUTPUT()				TCCR0&=~(1<<COM00);\
														TCCR0|=(1<<COM01)
//set on compare clear at bottom
#define TIMER0_COMPARE_MODE_SET_OUTPUT()				TCCR0|=(1<<COM00);\
														TCCR0|=(1<<COM01)

#define TIMER0_WRITE_VALUE_IN_TIMER_REGISTER(value)			TCNT0=value
#define TIMER0_WRITE_VALUE_IN_COMPARE_REGISTER(value)		OCR0=value

/**************************Timer0 mode interrupt**********************/
#define TIMER0_TIMER_MODE_INTERRUPT_ENABLE()				TIMSK|=(1<<TOIE0)
#define TIMER0_COMPARE_MODE_INTERRUPT_ENABLE()				TIMSK|=(1<<OCIE0)
#define TIMER0_TIMER_MODE_INTERRUPT_FLAG_CHECK()			(TIFR&=(1<<TOV0))==TIMER0_FLAG_IS_SET
#define TIMER0_COMPARE_MODE_INTERRUPT_FLAG_CHECK()			(TIFR&=(1<<OCF0))==TIMER0_FLAG_IS_SET

#define TIMER0_PRESCALAR_RESET()							(SFIOR|=(1<<PSR10))				

							
/*****************************************************Timer0 mode select*********************************************/

//COUNT UP in TCNT0 FROM 0 TO 255 (overflow->TOV0)
#define TIMER0_NORMAL_MODE_SELECT()					TCCR0&=~(1<<WGM00);\
													TCCR0&=~(1<<WGM01)


#define TIMER0_PWM_MODE_SELECT()					TCCR0|=(1<<WGM00);\
													TCCR0&=~(1<<WGM01)
													
//CLEAR TIMER ON COMPARE MATCH the TCNT0 is cleared when match value in OCR0 
//<warning> if the value in OCR0 is less than current value in TCNT0 the timer will count untill over flow then become 0 then count up till the value in OCR0 
// to display wave form on OC0 pin the pin must be set ad output and the (COM01:0 = 1) -> toggle the level with every compare match fOCn=(fclk_I/O)/2*N*(1+OCRn)  ->(N is prescalar)
#define TIMER0_CTC_MODE_SELECT()					TCCR0&=~(1<<WGM00);\
													TCCR0|=(1<<WGM01)
													
#define TIMER0_FAST_PWM_MODE_SELECT()				TCCR0|=(1<<WGM00);\
													TCCR0|=(1<<WGM01)

/*****************************************************Timer0 clock select*********************************************/
#define TIMER0_CLOCK_OFF()								TCCR0&=~(1<<CS02);\
														TCCR0&=~(1<<CS01);\
														TCCR0&=~(1<<CS00)

#define TIMER0_CLOCK_NO_PRESCALING()					TCCR0&=~(1<<CS02);\
														TCCR0&=~(1<<CS01);\
														TCCR0|=(1<<CS00)
														
#define TIMER0_CLOCK_8_PRESCALING()						TCCR0&=~(1<<CS02);\
														TCCR0|=(1<<CS01);\
														TCCR0&=~(1<<CS00)
												
#define TIMER0_CLOCK_64_PRESCALING()					TCCR0&=~(1<<CS02);\
														TCCR0|=(1<<CS01);\
														TCCR0|=(1<<CS00)
														
#define TIMER0_CLOCK_256_PRESCALING()					TCCR0|=(1<<CS02);\
														TCCR0&=~(1<<CS01);\
														TCCR0&=~(1<<CS00)
												
#define TIMER0_CLOCK_1024_PRESCALING()					TCCR0|=(1<<CS02);\
														TCCR0&=~(1<<CS01);\
														TCCR0|=(1<<CS00)

#define TIMER0_EXTERNAL_CLOCK_T0_FALLING_EDGE()			TCCR0|=(1<<CS02);\
														TCCR0|=(1<<CS01);\
														TCCR0&=~(1<<CS00)
														
#define TIMER0_EXTERNAL_CLOCK_T0_RISING_EDGE()			TCCR0|=(1<<CS02);\
														TCCR0|=(1<<CS01);\
														TCCR0|=(1<<CS00)
														
/*******user data types decleration********/

typedef enum{
	normal_mode=0,
	pwm_mode,
	ctc_mode, //compare
	fast_pwm_mode,
	}timer0_mode;

typedef  enum{
	no_clock=0,
	no_prescalar,// produce smallest delay
	prescalar_divide_by_8,
	prescalar_divide_by_64,
	prescalar_divide_by_256,
	prescalar_divide_by_1024,
	external_clock_T0_falling_edge,
	external_clock_T0_rising_edge,
	}timer0_clock_select_and_prescalar;

typedef struct{
	uint8 preload_value; // value you want you timer to count or value you want to compare with
	
	timer0_mode mode; 
	timer0_clock_select_and_prescalar prescalar;
	}timer0_config;
/*******functions decleration********/
std_return_type mcal_timer0_mode_select(timer0_config*);
std_return_type mcal_timer0_normal_mode_blocking(timer0_config*);
std_return_type mcal_timer0_compare_mode_blocking(timer0_config*);
std_return_type mcal_timer0_normal_mode_interrupt(timer0_config*);
std_return_type mcal_timer0_compare_mode_interrupt(timer0_config*);
std_return_type mcal_timer0_select_prescalar(timer0_clock_select_and_prescalar prescalar);
#endif /* TIMER0_H_ */