/*
 * USART.c
 *
 * Created: 9/18/2023 5:32:38 PM
 *  Author: 20115
 */ 
#include "USART.h"
static mcal_usart_async_write_baud_rate(uint16 value);
static std_return_type mcal_usart_frame_intaillize (usart_async_frame_config*my_frame);

std_return_type mcal_usart_async_calculate_baud_rate (usart_async* my_usart)
{
	std_return_type ret=OK;
	if(NULL==my_usart)
	{
		ret=NOT_OK;
	}
	else{
		if(USART_ASYNC_DOUBLE_BAUD_RATE_CHECK())
		{
			my_usart->ubrr_value*=2;
		}
		my_usart->ubrr_value=(uint16)((F_CPU/(my_usart->baud_rate*16))-1);
		mcal_usart_async_write_baud_rate(my_usart->ubrr_value);
	}
	return ret;
}
std_return_type mcal_usart_async_transmit_recieve_intiallize(usart_async*my_usart){
	std_return_type ret=OK;
	if(NULL==my_usart)
	{
		ret=NOT_OK;
	}
	else{
		USART_TRANSMIT_ENABLE();
		USART_RECIEVE_ENABLE();
		mcal_usart_async_write_baud_rate(my_usart->ubrr_value);
		//mcal_usart_async_calculate_baud_rate(my_usart);
		mcal_usart_frame_intaillize(&(my_usart->frame));
		
	}
	return ret;
}

std_return_type mcal_usart_async_transmit_intiallize(usart_async*my_usart){
		std_return_type ret=OK;
		if(NULL==my_usart)
		{
			ret=NOT_OK;
		}
		else{
			USART_TRANSMIT_ENABLE();
			mcal_usart_async_write_baud_rate(my_usart->ubrr_value);
			//mcal_usart_async_calculate_baud_rate(my_usart);
			mcal_usart_frame_intaillize(&(my_usart->frame));
			
		}
		return ret;
}

// after calling transmit initialize call this function and send (my_usart.data) as its argument
std_return_type mcal_usart_async_transmit_data_blocking(uint8 data){
	std_return_type ret=OK;	
	while (USART_NOT_READY_TO_TRANSMIT());
	USART_ASYNC_SEND_VALUE(data);
	return ret;
}

std_return_type mcal_usart_async_recieve_intiallize(usart_async*my_usart){
	std_return_type ret=OK;
	if(NULL==my_usart)
	{
		ret=NOT_OK;
	}
	else{
		USART_RECIEVE_ENABLE();
		mcal_usart_async_write_baud_rate(my_usart->ubrr_value);
		//mcal_usart_async_calculate_baud_rate(my_usart);
		mcal_usart_frame_intaillize(&(my_usart->frame));
	}
	return ret;
}

std_return_type mcal_usart_async_recieve_data_blocking(uint8*data){
		std_return_type ret=OK;
		while (USART_NOT_READY_TO_RECIEVE());
		//recieve data in UDR register
		data=UDR;
		return ret;
}

 static mcal_usart_async_write_baud_rate(uint16 value){
	std_return_type ret=OK;
	UBRRL=value;
	value=(value>>8);
	value&=0x0f;
	UBRRH=value;
	return ret;
}

static std_return_type mcal_usart_frame_intaillize (usart_async_frame_config*my_frame){
	std_return_type ret=OK;
	if(NULL==my_frame)
	{
		ret=NOT_OK;
	}
	else{
		switch(my_frame->data_size)
		{
			case data_size_5_bits:
			USART_ASYNC_5_BITS_DATA();
			break;
			
			case data_size_6_bits:
			USART_ASYNC_6_BITS_DATA();
			break;
			
			case data_size_7_bits:
			USART_ASYNC_7_BITS_DATA();
			break;
			
			case data_size_8_bits:
			USART_ASYNC_8_BITS_DATA();
			break;
			
			case data_size_9_bits:
			USART_ASYNC_9_BITS_DATA();
			break;
			
			default:
			USART_ASYNC_8_BITS_DATA();
			break;
			
		}
		switch(my_frame->parity)
		{
			case no_parity:
			USART_ASYNC_NO_PARITY();
			break;
			case even:
			USART_ASYNC_EVEN_PARITY();
			break;
			case odd:
			USART_ASYNC_ODD_PARITY();
			break;
			default:
			USART_ASYNC_NO_PARITY();
			break;
		}
		switch(my_frame->stop_bits)
		{
			case stop_bit_1:
			USART_ASYNC_1_STOP_BIT();
			break;
			case stop_bit_2:
			USART_ASYNC_2_STOP_BIT();
			break;
			default:
			USART_ASYNC_1_STOP_BIT();
			break;
		}
	}
	return ret;
}

void USART_Init(unsigned int baud_rate) {
	// Set baud rate
// 	UBRRL=51;
// 	// 	UBRRH = (unsigned char)(baud_rate >> 8);
// 	// 	UBRRL = (unsigned char)baud_rate;
// 	// Enable receiver and transmitter, and enable RX interrupt
// 	UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
// 	// Set frame format: 8 data bits, 1 stop bit, no parity
// 	UCSRC = (1 << UCSZ1) | (1 << UCSZ0);
	  UCSRB = (1<<RXEN)|(1<<RXCIE)|(1<<TXEN); //enable receive and RXC int.
	  UCSRC = (1<<UCSZ1)|(1<<UCSZ0)|(1<<URSEL);
	  UBRRL = 51;
}

// Function to transmit data
void USART_Transmit(unsigned char data) {
	// Wait for empty transmit buffer
	while (!(UCSRA & (1 << UDRE)));
	// Put data into buffer, sends the data
	UDR = data;
}
/*
// Interrupt service routine for USART Receive Complete
ISR(USART_RXC_vect) {
	receivedData = UDR;
	rec[index]=receivedData;
	index++;
	if (index==11)
	{
		if (rec[0]=='@')
		{
			switch(rec[1])
			{
				case 'A'
				
			}
		}
	}
	_delay_ms(1000);
}*/
void USART_TransmitString(const char* str) {
	while (*str != '\0') {
		USART_Transmit(*str);
		str++;
	}
}