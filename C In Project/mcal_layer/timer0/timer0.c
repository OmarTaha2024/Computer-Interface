/*
 * timer0.c
 *
 * Created: 9/14/2023 11:09:17 PM
 *  Author: 20115
 */ 
#include "timer0.h"

 std_return_type mcal_timer0_select_prescalar(timer0_clock_select_and_prescalar prescalar);

//std_return_type mcal_timer0_mode_select(timer0_config*)
// {
// 	std_return_type ret=OK;
// 	if(NULL==my_timer)
// 	{
// 		ret=NOT_OK;
// 	}
// 	else{
// 		switch(my_timer->mode)
// 		{
// 			
// 		}
// 	}
// 	return ret;
// }

std_return_type mcal_timer0_normal_mode_blocking(timer0_config* timer0_normal_mode){
	std_return_type ret=OK;
	if(NULL==timer0_normal_mode)
	{
		ret=NOT_OK;
	}
	else{
		TIMER0_WRITE_VALUE_IN_TIMER_REGISTER(256-timer0_normal_mode->preload_value);
		TIMER0_NORMAL_MODE_SELECT();
		ret=mcal_timer0_select_prescalar(timer0_normal_mode->prescalar);
		while(TIMER0_TIMER_MODE_RUNNING());
		//while((TIFR &(1<<TOV0))==0);
		timer0_normal_mode->preload_value=0;
		TIMER0_TIMER_MODE_CLEAR_FLAG();
		TIMER0_CLOCK_OFF();
	}
	return ret;
}
std_return_type mcal_timer0_compare_mode_blocking(timer0_config*timer0_compare_mode){
	std_return_type ret=OK;
	if(NULL==timer0_compare_mode)
	{
		ret=NOT_OK;
	}
	else{
		TIMER0_WRITE_VALUE_IN_COMPARE_REGISTER(timer0_compare_mode->preload_value);
		TIMER0_CTC_MODE_SELECT();
		ret=mcal_timer0_select_prescalar(timer0_compare_mode->prescalar);
		while(TIMER0_COMPARE_MODE_RUNNING());
		timer0_compare_mode->preload_value=0;
		TIMER0_COMPARE_MODE_CLEAR_FLAG();
		TIMER0_CLOCK_OFF();
	}
	return ret;	
}

std_return_type mcal_timer0_normal_mode_interrupt(timer0_config*timer0_normal_mode){
	std_return_type ret=OK;
	if(NULL==timer0_normal_mode)
	{
		ret=NOT_OK;
	}
	else{
		TIMER0_TIMER_MODE_INTERRUPT_ENABLE();
		TIMER0_WRITE_VALUE_IN_TIMER_REGISTER(256-timer0_normal_mode->preload_value);
		TIMER0_NORMAL_MODE_SELECT();
		ret=mcal_timer0_select_prescalar(timer0_normal_mode->prescalar);
		//in main enable global interrupt -> sei();
		//implement ISR with TIMER0_OVF_vect
	}
	return ret;
	
}

std_return_type mcal_timer0_compare_mode_interrupt(timer0_config*timer0_compare_mode){
	std_return_type ret=OK;
	if(NULL==timer0_compare_mode)
	{
		ret=NOT_OK;
	}
	else{
		TIMER0_COMPARE_MODE_INTERRUPT_ENABLE();
		TIMER0_WRITE_VALUE_IN_COMPARE_REGISTER(timer0_compare_mode->preload_value);
		TIMER0_CTC_MODE_SELECT();
		ret=mcal_timer0_select_prescalar(timer0_compare_mode->prescalar);
		//in main enable global interrupt -> sei();
		//implement ISR with TIMER0_COMP_vect
	}
	return ret;
}

 std_return_type mcal_timer0_select_prescalar(timer0_clock_select_and_prescalar prescalar)
{
	std_return_type ret=OK;
	if(NULL==prescalar)
	{
		ret=NOT_OK;
	}
	else{
		switch(prescalar)
		{
			case no_clock:
			TIMER0_CLOCK_OFF();
			break;
			
			case no_prescalar:
			TIMER0_CLOCK_NO_PRESCALING();
			break;
			
			case prescalar_divide_by_8:
			TIMER0_CLOCK_8_PRESCALING();
			break;
			
			case prescalar_divide_by_64:
			TIMER0_CLOCK_64_PRESCALING();
			break;
			
			case prescalar_divide_by_256:
			TIMER0_CLOCK_256_PRESCALING();
			break;
			
			case prescalar_divide_by_1024:
			TIMER0_CLOCK_1024_PRESCALING();
			break;
			
			case external_clock_T0_falling_edge:
			TIMER0_EXTERNAL_CLOCK_T0_FALLING_EDGE();
			break;
			
			case external_clock_T0_rising_edge:
			TIMER0_EXTERNAL_CLOCK_T0_RISING_EDGE();
			break;
			
			default:
			TIMER0_CLOCK_NO_PRESCALING();
			break;
		}
	}
	return ret;
}