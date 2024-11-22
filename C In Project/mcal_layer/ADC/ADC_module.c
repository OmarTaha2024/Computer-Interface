/*
 * ADC_module.c
 *
 * Created: 9/12/2023 9:32:53 PM
 *  Author: 20115
 */ 
#include "ADC_module.h"

std_return_type mcal_adc_intiallize(adc_config*my_adc){
	std_return_type ret=OK;
	if(NULL==my_adc)
	{
		ret=NOT_OK;
	}
	else{
		ADC_ENABLE_FUNCTION();
		switch(my_adc->refrence)
		{
			case adc_AREF_pin:
			ADC_VOLTAGE_REFRENCE_AREF_PIN();
			break;
			
			case adc_AVCC_pin:
			ADC_VOLTAGE_REFRENCE_AVCC__PIN();
			break;
			
			case  adc_internal:
			ADC_VOLTAGE_REFRENCE_INTERNAL();
			break;
			
			default:
			ADC_VOLTAGE_REFRENCE_AREF_PIN();
			break;
		}
		switch(my_adc->adjust)
		{
			case  adc_right_adjust:
			ADC_RIGHT_ADJUST();
			break;
			
			case adc_left_adjust:
			ADC_LEFT_ADJUST();
			break; 
			
			default:
			ADC_LEFT_ADJUST();
			break;
		}
		switch(my_adc->channel)
		{
			case  adc_CH0:
			ADC_CHANNEL_0();
			break;
			
			case  adc_CH1:
			ADC_CHANNEL_1();
			break;
			
			case  adc_CH2:
			ADC_CHANNEL_2();
			break;
			
			case  adc_CH3:
			ADC_CHANNEL_3();
			break;
			
			case  adc_CH4:
			ADC_CHANNEL_4();
			break;
			
			case  adc_CH5:
			ADC_CHANNEL_5();
			break;
			
			case  adc_CH6:
			ADC_CHANNEL_6();
			break;
			
			case  adc_CH7:
			ADC_CHANNEL_7();
			break;
			
			default:
			ADC_CHANNEL_0();
			break;
		}
		switch (my_adc->prescalar)
		{
			case adc_divide_by_2:
			ADC_DIVIDE_BY_2_FUNCTION();
			break;
			
			case adc_divide_by_4:
			ADC_DIVIDE_BY_4_FUNCTION();
			break;
			
			case adc_divide_by_8:
			ADC_DIVIDE_BY_8_FUNCTION();
			break;
			
			case adc_divide_by_16:
			ADC_DIVIDE_BY_16_FUNCTION();
			break;
			
			case adc_divide_by_32:
			ADC_DIVIDE_BY_32_FUNCTION();
			break;
			
			case adc_divide_by_64:
			ADC_DIVIDE_BY_64_FUNCTION();
			break;
			
			case adc_divide_by_128:
			ADC_DIVIDE_BY_128_FUNCTION();
			break;
			
			default:
			ADC_DIVIDE_BY_2_FUNCTION();
			break;
		}
	}
	return ret;
} //Don't start the conversion

std_return_type mcal_adc_read(adc_config*my_adc,uint16*value)
{
	std_return_type ret=OK;
	if((NULL==my_adc) || (NULL==value))
	{
		ret=NOT_OK;
	}
	else{
		switch(my_adc->adjust)
		{
			case  adc_right_adjust:
			//ADCL&=0xff;
			//ADCH&=0x03;
			*value=(ADC/2)-2;
			break;
			
			case adc_left_adjust:
			*value=ADC;
			*value=(*value>>6);
			break;
			
			default:
			ADC_RIGHT_ADJUST();
			break;
		}
	}
	return ret;
}

std_return_type mcal_adc_read_poilling_value(adc_config*my_adc,uint16*value){
	std_return_type ret=OK;
	if((NULL==my_adc)||(NULL==value))
	{
		ret=NOT_OK;
	}
	else{
	ADC_START_CONVERSION_FUNCTION();
	while (ADC_CONVERSION_RUNNING);
	ret=mcal_adc_read(my_adc,value);
	
	ADC_CLEAR_FLAG_FUNCTION();
	}
	return ret;
}

std_return_type mcal_adc_read_interrupt_value()
{
	std_return_type ret=OK;
	if(INTERRUPT_PERIPEHRAL_STATE==INTERRUPT_DISABLE)
	{
		ret= NOT_OK;
	}
	else{
			ADC_INTERRUPT_ENABLE_FUNCTION();
			ADC_START_CONVERSION_FUNCTION();
			//in main call sei()
			//ISR will be called
			//in ISR add: 
			//1-mcal_adc_read(my_adc,value);
			//2-ADC_CLEAR_FLAG_FUNCTION();
	}
}

