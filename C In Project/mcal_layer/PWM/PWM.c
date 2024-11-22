/*
 * PWM.c
 *
 * Created: 10/9/2023 10:16:34 PM
 *  Author: 20115
 */ 
#include "PWM.h"



std_return_type mcal_PWM0_intiallize(pwm_config*my_pwm0)
{
	std_return_type ret=OK;
	if(NULL==my_pwm0)
	{
		ret=NOT_OK;
	}
	else{
		switch(my_pwm0->mode)
		{
			case pwm_mode:
			TIMER0_PWM_MODE_SELECT();
			PWM0_CLEAR_ON_UP_COUNTING();
			mcal_timer0_select_prescalar(my_pwm0->clock_prescale);
			break;
			
			case fast_pwm_mode:
			TIMER0_FAST_PWM_MODE_SELECT();
			FAST_PWM0_CLEAR_ON_COMPARE();
			mcal_timer0_select_prescalar(my_pwm0->clock_prescale);
			break;
			
			default:
			ret=NOT_OK;
			break;
		}
		OC0_OUTPUT_FUNCTION();
		
	}
}

std_return_type mcal_PWM0_increase()
{
	std_return_type ret=OK;
	uint8 duty;
	for(duty=0; duty<255; duty++)
	{
		OCR0=duty;  /*increase the LED light intensity*/
		//_delay_us(50);
	}
	return ret;
}
std_return_type mcal_PWM0_increase_to_value(uint8 final_value)
{
	std_return_type ret=OK;
	uint8 duty;
	for(duty=0; duty<=final_value; duty++)
	{
		OCR0=duty;  /*increase the LED light intensity*/
		//_delay_us(50);
	}
	return ret;
}
std_return_type mcal_PWM0_decrease()
{
		std_return_type ret=OK;
		uint8 duty;
		for(duty=255; duty>1; duty--)
		{
			OCR0=duty;  /*decrease the LED light intensity*/
			//_delay_us(50);
		}
		return ret;
}
std_return_type mcal_PWM0_decrease_from_value(uint8 start_value)
{
	std_return_type ret=OK;
	uint8 duty;
	for(duty=start_value; duty>1; duty--)
	{
		OCR0=duty;  /*decrease the LED light intensity*/
		//_delay_us(50);
	}
	return ret;
}
std_return_type mcal_PWM0_start_to_end(uint8 start, uint8 end)
{
	std_return_type ret=OK;
	uint8 duty;
	for(duty=start; duty<=end; duty++)
	{
		OCR0=duty;  /*increase the LED light intensity*/
		//_delay_us(50);
	}
	return ret;
}