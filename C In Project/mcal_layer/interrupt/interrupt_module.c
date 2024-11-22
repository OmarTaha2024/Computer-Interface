/*
 * interrupt_module.c
 *
 * Created: 9/8/2023 5:22:24 PM
 *  Author: 20115
 */ 
#include "interrupt_module.h"

// static void INT0_service_routine_low_level(void);
// static void INT0_service_routine_on_change(void);
// static void INT0_service_routine_falling_edge(void);
// static void INT0_service_routine_rising_edge(void);
// 
// static void INT1_service_routine_low_level(void);
// static void INT1_service_routine_on_change(void);
// static void INT1_service_routine_falling_edge(void);
// static void INT1_service_routine_rising_edge(void);
// 
// static void INT2_service_routine_falling_edge(void);
// static void INT2_service_routine_rising_edge(void);

//static void inteerupt_service_routine(void (*ptr_fun) (vector));


std_return_type mcal_interrupt_external_firring(interrupt_external_config*my_interrupt){
	std_return_type ret=NOT_OK;
	if(NULL==my_interrupt)	
	{
		ret=NOT_OK;
	}
	else{
		switch(my_interrupt->external_int_type)
		{
			case interrupt_INT0:
			INT0_ENABLE_FUNCTION();
		
			//my_interrupt->sense_control.int0_or_int1=INT0;
			switch(my_interrupt->sense_control.int0_or_int1)
			{
				case interrupt_INT0_or_INT1_low_level:
					INT0_LOW_LEVEL_FUNCTION();
					break;
				case interrupt_INT0_or_INT1_on_change:
					INT0_ON_CHANGE_FUNCTION();
					break;
				case interrupt_INT0_or_INT1_falling_edge:
					INT0_ON_FALLING_EDGE_FUNCTION();
					break;
				case interrupt_INT0_or_INT1_rising_edge:
					INT0_ON_RISING_EDGE_FUNCTION();
					break;
			}
			sei();
		
			break;
			////
			case interrupt_INT1:
			INT1_ENABLE_FUNCTION();
			
			//my_interrupt->sense_control.int0_or_int1=INT1;
			switch(my_interrupt->sense_control.int0_or_int1)
			{
				case interrupt_INT0_or_INT1_low_level:
				INT1_LOW_LEVEL_FUNCTION();
				break;
				case interrupt_INT0_or_INT1_on_change:
				INT1_ON_CHANGE_FUNCTION();
				break;
				case interrupt_INT0_or_INT1_falling_edge:
				INT1_ON_FALLING_EDGE_FUNCTION();
				break;
				case interrupt_INT0_or_INT1_rising_edge:
				INT1_ON_RISING_EDGE_FUNCTION();
				break;
			}
			sei();
			//ISR(INT1_vect);
			break;
			/////
			////
			case interrupt_INT2:
			INT2_ENABLE_FUNCTION();
			//my_interrupt->sense_control.int0_or_int1=INT2;
			switch(my_interrupt->sense_control.int2)
			{
				case interrupt_INT2_falling_edge:
				INT2_ON_FALLING_EDGE_FUNCTION();
				break;
				case interrupt_INT2_rising_edge:
				INT2_ON_RISING_EDGE_FUNCTION();
				break;
			}
			sei();
			//ISR(INT2_vect);
			break;
		}
	}
	return ret;
}

