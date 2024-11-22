/*
 * timer1.h
 *
 * Created: 9/18/2023 2:32:26 PM
 *  Author: 20115
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_

/*******Includes********/
//#include <avr/io.h>
#include "../interrupt/interrupt_module.h"
#include "../mcal_layer_header_files/mcal_std_types.h"

/*********Macro defintions****/
#define  TIMER1_REGISTER_SIZE		16
#define  TIMER1_FLAG_IS_SET			1
#define  TIMER1_FLAG_IS_CLEARED     0

 /*******macro functions********/
#define TIMER1_PRESCALAR_RESET()							(SFIOR|=(1<<PSR10)


/********output signal on compare mode  DDR of OC0A or OC0B and OC1A or OC1B are set to be output in normal and ctc mode NOT PWM mode*******/
//toggle output on compare match
#define TIMER1_COMPARE_MODE_A_TOGGLE_OUTPUT()				TCCR1A|=(1<<COM1A0);\
														TCCR1A&=~(1<<COM1A1)
//clear output on compare match
#define TIMER0_COMPARE_MODE_A_CLEAR_OUTPUT()				TCCR1A&=~(1<<COM1A0);\
														TCCR1A|=(1<<COM1A1)
//set output on compare match
#define TIMER0_COMPARE_MODE_A_SET_OUTPUT()				TCCR1A|=(1<<COM1A0);\
														TCCR1A|=(1<<COM1A1)

//toggle output on compare match
#define TIMER1_COMPARE_MODE_B_TOGGLE_OUTPUT()				TCCR1B|=(1<<COM1B0);\
															TCCR1B&=~(1<<COM1B1)
//clear output on compare match
#define TIMER0_COMPARE_MODE_B_CLEAR_OUTPUT()				TCCR1B&=~(1<<COM1B0);\
															TCCR1B|=(1<<COM1B1)
//set output on compare match
#define TIMER0_COMPARE_MODE_B_SET_OUTPUT()				TCCR1B|=(1<<COM1B0);\
														TCCR1B|=(1<<COM1B1)
														
														

#endif /* TIMER1_H_ */