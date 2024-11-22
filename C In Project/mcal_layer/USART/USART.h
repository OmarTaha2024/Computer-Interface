/*
 * USART.h
 *
 * Created: 9/18/2023 5:32:28 PM
 *  Author: 20115
 */ 


#ifndef USART_H_
#define USART_H_

/*
		FULL DUPLEX,
		ASYNC & SYNC,
		SERIAL,
		ASYNC-> frame     -  BAUD RATE
		SYNC->
*/

/*	Transmit 
Config : in proteus adjust CSKEL fuse to extrnal high freq
Coding:	
	my_uart.baud_rate=9600;
	my_uart.frame.data_size=data_size_8_bits;
	my_uart.frame.parity=no_parity;
	my_uart.frame.stop_bits=stop_bit_1;
	my_uart.ubrr_value=103;
	mcal_usart_async_transmit_intiallize(&my_uart);
	
	while (1)
	{
		mcal_usart_async_transmit_data_blocking('a');
		_delay_ms(50);
	}
*/

/*******Includes********/
#include "../interrupt/interrupt_module.h"
#include "../mcal_layer_header_files/mcal_std_types.h"
#include <util/delay.h>
/*********Macro defintions****/

/*******macro functions********/
#define USART_RECIEVE_ENABLE()					UCSRB|=(1<<RXEN)
#define USART_TRANSMIT_ENABLE()					UCSRB|=(1<<TXEN)	//write this bit to zero will not become effective until ongoing and pending transmissions are completed

#define  USART_ASYNC_MODE_SELECT()				UCSRC&=~(1<<UMSEL)
#define  USART_SYNC_MODE_SELECT()				UCSRC|=(1<<UMSEL)
/*#define USART_ASYNC_WRITE_BAUD_RATE(value)		UBRRL=value;\
												value=(value>>8);\
												value&=0x0f;\
												UBRRH=value*/
#define USART_ASYNC_SEND_VALUE(value)			UDR=value
#define  USART_PARITY_DISABLE()					UCSRC&=~(1<<UPM0);\
												UCSRC&=~(1<<UPM1)
#define  USART_PARITY_EVEN_SELECT()				UCSRC&=~(1<<UPM0);\
												UCSRC|=(1<<UPM1)
#define  USART_PARITY_ODD_SELECT()				UCSRC|=(1<<UPM0);\
												UCSRC|=(1<<UPM1)
												
#define  USART_ASYNC_1_STOP_BIT_SELECT()		UCSRC&=~(1<<USBS)
#define  USART_ASYNC_2_STOP_BIT_SELECT()		UCSRC|=(1<<USBS)

#define USART_NOT_READY_TO_RECIEVE()			UCSRA&(1<<RXC)==0
#define USART_RECIEVE_COMPLETED()				UCSRA&(1<<RXC)==1

#define USART_NOT_READY_TO_TRANSMIT()				UCSRA&(1<<UDRE)==0 //now buffer register is empty and can send data
#define USART_RECIEVE_INTRRUPT_ENABLE()			UCSRB|=(1<<RXCIE)   //enable RXC bit flag in UCSRA to be set.
#define USART_TRANSMIT_INTRRUPT_ENABLE()		UCSRB|=(1<<TXCIE)	//enable TXC bit flag in UCSRA to be set.
#define USART_DATA_EMPTY_INTRRUPT_ENABLE()		UCSRB|=(1<<UDRIE)	//enable UDRE bit flag in UCSRA to be set.
#define USART_REGISTER_SELECT_UCSRC()			UCSRC|=(1<<URSEL)	//this is default rarely switch to UBRRH you must set it to high when read or write to UCSRC
#define USART_REGISTER_SELECT_UBRRH()			UBRRH&=~(1<<URSEL)
#define USART_ASYNC_DOUBLE_BAUD_RATE()			UCSRA|=(1<<U2X)
#define USART_ASYNC_DOUBLE_BAUD_RATE_CHECK()	UCSRA&(1<<U2X)==1
/********frame macros**************/
#define USART_ASYNC_5_BITS_DATA()			UCSRC&=~(1<<UCSZ0);\
											UCSRC&=~(1<<UCSZ1)
#define USART_ASYNC_6_BITS_DATA()			UCSRC|=(1<<UCSZ0);\
											UCSRC&=~(1<<UCSZ1)
#define USART_ASYNC_7_BITS_DATA()			UCSRC&=~(1<<UCSZ0);\
											UCSRC|=(1<<UCSZ1)
#define USART_ASYNC_8_BITS_DATA()			UCSRC|=(1<<UCSZ0);\
											UCSRC|=(1<<UCSZ1)
//not in same register
#define USART_ASYNC_9_BITS_DATA()			UCSRC|=(1<<UCSZ0);\
											UCSRC|=(1<<UCSZ1);\
											UCSRB|=(1<<UCSZ2)

#define USART_ASYNC_1_STOP_BIT()			UCSRC&=~(1<<USBS)
#define USART_ASYNC_2_STOP_BIT()			UCSRC|=(1<<USBS)

#define USART_ASYNC_NO_PARITY()				UCSRC&=~(1<<UPM0);\
											UCSRC&=~(1<<UPM1)
											
#define USART_ASYNC_EVEN_PARITY()			UCSRC&=~(1<<UPM0);\
											UCSRC|=(1<<UPM1)
#define USART_ASYNC_ODD_PARITY()			UCSRC|=(1<<UPM0);\
											UCSRC|=(1<<UPM1)

/*******user data types decleration********/
typedef enum{
	async_mode=0,
	sync_mode
	}usart_mode;

typedef enum{
	data_size_5_bits,
	data_size_6_bits,
	data_size_7_bits,
	data_size_8_bits,
	data_size_9_bits
}usart_async_data_size;

typedef enum{
	stop_bit_1,
	stop_bit_2
}usart_async_stop_bits;

typedef enum{
	no_parity,
	even,
	odd,
	}usart_async_parity_type;
typedef enum{
	transmit,
	recieve,
	transmit_and_recieve,
}usart_transmitting_type;

typedef struct{
	usart_async_data_size data_size :3;
	usart_async_stop_bits stop_bits:1;
	usart_async_parity_type parity:2;
	uint8 reserved:2;
	}usart_async_frame_config;


	
	typedef struct{
		uint8 data;
		uint16 baud_rate;
		uint16 ubrr_value;
		usart_async_frame_config frame;
		usart_transmitting_type transfer;
		}usart_async;
		
	typedef struct{
		uint8 data;
		uint16 ubrr_value;
		usart_transmitting_type transfer;
	}usart_sync;
		
/*******functions decleration********/
std_return_type mcal_usart_async_calculate_baud_rate (usart_async*);
std_return_type mcal_usart_async_transmit_data_blocking(uint8 data);
std_return_type mcal_usart_async_transmit_recieve_intiallize(usart_async*my_usart);
std_return_type mcal_usart_async_recieve_data_blocking(uint8*data);
void USART_Init(unsigned int baud_rate);
void USART_Transmit(unsigned char data);
void USART_TransmitString(const char* str);
//ISR(USART_RXC_vect)
#endif
 /* USART_H_ */