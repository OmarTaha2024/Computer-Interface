/*
 * PWM.h
 *
 * Created: 10/9/2023 10:16:43 PM
 *  Author: 20115
 */ 


#ifndef PWM_H_
#define PWM_H_

/*******Includes********/
#include "../timer0/timer0.h"
#include "../gpio/mcal_gpio.h"
#include <util/delay.h>


/*******macro functions********/

#define  OC0_OUTPUT_FUNCTION()	DDRB|=(1<<PB3)

//make OC0 pin work at its normal function
#define PWM0_DISCONNECT()				TCCR0&=~(1<<COM00);\
										TCCR0&=~(1<<COM01)
										
//clear OC0 on compare match and set at the top
#define FAST_PWM0_CLEAR_ON_COMPARE()				TCCR0&=~(1<<COM00);\
													TCCR0|=(1<<COM01)
													
//set OC0 on compare match and clear at the top
#define FAST_PWM0_SET_ON_COMPARE()				TCCR0|=(1<<COM00);\
												TCCR0|=(1<<COM01)

//Clear OC0 on compare match when up-counting, set OC0 on compare match when down-counting
#define PWM0_CLEAR_ON_UP_COUNTING()				TCCR0&=~(1<<COM00);\
											TCCR0|=(1<<COM01)

//set OC0 on compare match when up-counting, clear OC0 on compare match when down-counting
#define PWM0_SET_ON_UP_COUNTING()				TCCR0|=(1<<COM00);\
											TCCR0|=(1<<COM01)


/*******user data types decleration********/


typedef struct{

	timer0_mode mode;
	timer0_clock_select_and_prescalar clock_prescale;
	
	
	}pwm_config;

/*******functions decleration********/
std_return_type mcal_PWM0_intiallize(pwm_config*);
std_return_type mcal_PWM0_increase();
std_return_type mcal_PWM0_decrease();
std_return_type mcal_PWM0_decrease_from_value(uint8);
std_return_type mcal_PWM0_increase_to_value(uint8 );
std_return_type mcal_PWM0_start_to_end(uint8,uint8);
#endif /* PWM_H_ */