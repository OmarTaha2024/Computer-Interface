/*
 * ADC_module.h
 *
 * Created: 9/12/2023 9:32:36 PM
 *  Author: 20115
 */ 


#ifndef ADC_MODULE_H_
#define ADC_MODULE_H_

/*
	adc_config my_adc={
		.refrence=adc_AREF_pin,
		.adjust=adc_right_adjust,
		.channel=adc_CH0,
		.prescalar=adc_divide_by_128,
	};
	
CODE:
	mcal_adc_intiallize(&my_adc);
	if poilling inside while(1)
	{
		mcal_adc_read_poilling_value(&my_adc,&adc_val);
	} 
	
	if Interruprt
		mcal_adc_read_interrupt_value();
		sei();
		and implement ISR(ADC_vect)
*/
/*******Includes********/
//#include <avr/io.h>
#include "../interrupt/interrupt_module.h"
#include "../mcal_layer_header_files/mcal_std_types.h"

/*******macro defintions********/
#define ADC_RESOLUTION		  (uint8) 10;
#define ADC_CHANNEL_NUMBER	  (uint8) 8;

#define ADC_AUTO_TRIGGER_ENABLE  1
#define ADC_AUTO_TRIGGER_DIABLE  0

#define ADC_AUTO_TRIGGER_STATE  ADC_AUTO_TRIGGER_DIABLE

#define ADC_CONVERSION_RUNNING  (ADCSRA&(1<<4)==0) 

 /*******macro functions********/
 
 //enable and disable ADC peripheral
#define ADC_ENABLE_FUNCTION()							(ADCSRA|=(1<<7)) 
#define ADC_DISABLE_FUNCTION()							(ADCSRA&=~(1<<7))

#define ADC_START_CONVERSION_FUNCTION()				(ADCSRA|=(1<<6))

#define ADC_CLEAR_FLAG_FUNCTION()					(ADCSRA|=(1<<4))
 //ADC auto triggering (uncompleted) modes in SFIOR register
#define ADC_AUTO_TRIGGER_ENABLE_FUNCTION()				(ADCSRA|=(1<<5))
#define ADC_AUTO_TRIGGER_DISABLE_FUNCTION()				(ADCSRA&=~(1<<5))

#if (ADC_AUTO_TRIGGER_STATE==ADC_AUTO_TRIGGER_ENABLE)
#define ADC_FREE_RUNNING_MODE_FUNCTION()		

#endif


//ADC prescalar

#define ADC_DIVIDE_BY_2_FUNCTION()				ADCSRA&=~(1<<0);\
                                             ADCSRA&=~(1<<1);\
											 ADCSRA&=~(1<<2)

#define ADC_DIVIDE_BY_4_FUNCTION()				ADCSRA&=~(1<<0);\
												ADCSRA|=(1<<1);\
												ADCSRA&=~(1<<2)

#define ADC_DIVIDE_BY_8_FUNCTION()				ADCSRA|=(1<<0);\
												ADCSRA|=(1<<1);\
												ADCSRA&=~(0<<2)


#define ADC_DIVIDE_BY_16_FUNCTION()				ADCSRA&=~(1<<0);\
												ADCSRA&=~(1<<1);\
												ADCSRA|=(1<<2)

#define ADC_DIVIDE_BY_32_FUNCTION()			    ADCSRA|=(1<<0);\
												ADCSRA&=~(1<<1);\
												ADCSRA|=(1<<2)


#define ADC_DIVIDE_BY_64_FUNCTION()				ADCSRA&=~(1<<0);\
												ADCSRA|=(1<<1);\
												ADCSRA|=(1<<2)										


#define ADC_DIVIDE_BY_128_FUNCTION()			ADCSRA|=(1<<0);\
												ADCSRA|=(1<<1);\
												ADCSRA|=(1<<2)

//ADC interrupt
#if (INTERRUPT_PERIPEHRAL_STATE==INTERRUPT_ENABLE)
#define ADC_INTERRUPT_ENABLE_FUNCTION()				(ADCSRA|=(1<<3))
#endif


//ADC channel select
#define ADC_CHANNEL_0()					ADMUX&=~(1<<0);\
										ADMUX&=~(1<<1);\
										ADMUX&=~(1<<2)
										
#define ADC_CHANNEL_1()					ADMUX|=(1<<0);\
										ADMUX&=~(1<<1);\
										ADMUX&=~(1<<2)

#define ADC_CHANNEL_2()					ADMUX&=~(1<<0);\
										ADMUX|=(1<<1);\
										ADMUX&=~(1<<2)

#define ADC_CHANNEL_3()					ADMUX|=(1<<0);\
										ADMUX|=(1<<1);\
										ADMUX&=~(1<<2)
										
#define ADC_CHANNEL_4()					ADMUX&=~(1<<0);\
										ADMUX&=~(1<<1);\
										ADMUX|=(1<<2)
										
#define ADC_CHANNEL_5()					ADMUX|=(1<<0);\
										ADMUX&=~(1<<1);\
										ADMUX|=(1<<2)

#define ADC_CHANNEL_6()					ADMUX|=(1<<0);\
										ADMUX|=(1<<1);\
										ADMUX&=~(1<<2)
										
#define ADC_CHANNEL_7()					ADMUX|=(1<<0);\
										ADMUX|=(1<<1);\
										ADMUX|=(1<<2)

//ADC voltage refrence select
#define ADC_VOLTAGE_REFRENCE_AREF_PIN()   ADMUX&=~(1<<6);\
										  ADMUX&=~(1<<7)

#define ADC_VOLTAGE_REFRENCE_AVCC__PIN()   ADMUX|=(1<<6);\
											ADMUX&=~(1<<7)
										
#define ADC_VOLTAGE_REFRENCE_INTERNAL()    ADMUX|=(1<<6);\
												ADMUX|=(1<<7)

//ADC adjust												
#define ADC_LEFT_ADJUST()						(ADMUX|=(1<<5))												
#define ADC_RIGHT_ADJUST()						(ADMUX&=~(1<<5))	

/*******user data types decleration********/

typedef enum{
	adc_right_adjust=0,
	adc_left_adjust
	}adc_adjust;
	
typedef enum{
	adc_CH0=0,
	adc_CH1,
	adc_CH2,
	adc_CH3,
	adc_CH4,
	adc_CH5,
	adc_CH6,
	adc_CH7,
	}adc_channel;
	
typedef enum{
	adc_divide_by_2=0,
	adc_divide_by_4,
	adc_divide_by_8,
	adc_divide_by_16,
	adc_divide_by_32,
	adc_divide_by_64,
	adc_divide_by_128,
}adc_prescalar;

typedef enum{
	adc_AREF_pin=0,
	adc_AVCC_pin,
	adc_internal,
}adc_voltage_refrence;

typedef struct{
	adc_adjust adjust:1;
	adc_channel channel:4;
	adc_prescalar prescalar:3;
	adc_voltage_refrence refrence:2;
	}adc_config;
	
/*******functions decleration********/
std_return_type mcal_adc_intiallize(adc_config*my_adc);
std_return_type mcal_adc_read_poilling_value(adc_config*my_adc,uint16*value);
std_return_type mcal_adc_read(adc_config*my_adc,uint16*value);
std_return_type mcal_adc_read_interrupt_value();


#endif /* ADC_MODULE_H_ */
