/*
 * avrapp1.c
 *
 * Created: 8/31/2023 2:41:38 PM
 * Author : 20115
 */ 

#include "main.h"


adc_config temp_sensor;
gpio_pin_config dc_fan1;
gpio_pin_config dc_fan2;
gpio_pin_config ac_lamp;
pwm_config dc_fan_pwm;
timer0_config timer;
uint8 auto_mode[3];
uint8 x ;

uint8 receivedData;
uint8 index;
//frame: @  M  L  v  v  v  H  v  v  v   F  v  v   v   B   ; 
//frame: 0  1  2  3  4  5  6  7  8  9  10 11 12  13  14  15
uint8 recieved_frame[16];
uint16 lower_temp;
uint16 upper_temp;
uint16 fan_speed;
uint16 temp_val ;
uint8 isr_count;
uint8 temp_status;
uint8 temp_str[3]="000";

int main(void)
{
	
	intiallize_temp_sensor();
	intiallize_DC_fan();
	intiallize_ac_lamp();
	LCD_init();
	// Set baud rate to 9600 bps
	USART_Init(9600);
	DDRA=0b11110000;
    while (1) 
    {	sei();	
		temp_status_display();
		LCD_goToRowColumn(1,0);
		mcal_adc_read_poilling_value(&temp_sensor,&temp_val);
		temp_to_string(temp_str,temp_val);
		LCD_displayStringRowColumn(1,0,"temperature=");
		LCD_displayStringRowColumn(1,12,temp_str);
		if(receivedData == 'A' ){
			SET_BIT(PORTA ,7);
			_delay_ms(20);
			CLEAR_BIT(PORTA ,7);
			recieved_frame[1] ='A';
			while(1){
				sei();
				if(receivedData == 'n'){
					SET_BIT(PORTA ,7);
					_delay_ms(50);
					CLEAR_BIT(PORTA ,7);
					while(1){
						sei();
						if(receivedData != 'n'){SET_BIT(PORTA ,7);
							_delay_ms(20);
							CLEAR_BIT(PORTA ,7);lower_temp=receivedData-48;
							lower_temp*=10; break; }}}
							
							
							if(receivedData == 'x'){
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								while(1){
									sei();
									if(receivedData != 'x'){
										SET_BIT(PORTA ,7);
										_delay_ms(50);
										CLEAR_BIT(PORTA ,7);upper_temp=receivedData-48;
									upper_temp*=10; _delay_ms(20); auto_mode_handle_and_lcd_status_update();temp_status_display();break; }}}
						if(receivedData == 'Z'){
							SET_BIT(PORTA ,7);
							_delay_ms(50);
							CLEAR_BIT(PORTA ,7);
							break;
						}
			}
		}
		if(receivedData == 'M' ){
		SET_BIT(PORTA ,7);
		_delay_ms(20);
		CLEAR_BIT(PORTA ,7);
		recieved_frame[1] ='M';
		while(1){
			sei();
			if(receivedData == 'n'){
				SET_BIT(PORTA ,7);
				_delay_ms(50);
				CLEAR_BIT(PORTA ,7);
				while(1){
					sei();
					if(receivedData != 'n'){SET_BIT(PORTA ,7);
						_delay_ms(20);
						CLEAR_BIT(PORTA ,7);lower_temp=receivedData-48;
					lower_temp*=10; break; }}}
					
					
					if(receivedData == 'x'){
						SET_BIT(PORTA ,7);
						_delay_ms(50);
						CLEAR_BIT(PORTA ,7);
						while(1){
							sei();
							if(receivedData != 'x'){
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);upper_temp=receivedData-48;
							upper_temp*=10; _delay_ms(20); auto_mode_handle_and_lcd_status_update();temp_status_display();break; }}}
						
							
						if (receivedData=='B')
						{
							SET_BIT(PORTA ,7);
							_delay_ms(50);
							CLEAR_BIT(PORTA ,7);
							recieved_frame[index]=='B';
							mcal_gpio_pin_output_write_logic(&ac_lamp,high);
							receivedData='z';
							
						}
						if (receivedData=='X')
							{
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								recieved_frame[index]=='X';
								mcal_gpio_pin_output_write_logic(&ac_lamp,low);
								receivedData='z';
							}
							if(receivedData=='H'){
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								mcal_gpio_pin_output_write_logic(&ac_lamp,low);
								receivedData='z';
							}
							if (receivedData=='F')
							{
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								while(1){
									if (receivedData!='F'){
										fan_speed=(receivedData-48);
										fan_speed*=50;
										if (fan_speed>=OCR0)
										{mcal_PWM0_start_to_end(OCR0,fan_speed);}
										else{mcal_PWM0_start_to_end(fan_speed,OCR0);}
										break;
									}
								}
							}
							if(receivedData=='N'){
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								mcal_PWM0_decrease_from_value(OCR0);
								receivedData='z';
							}
							if(receivedData == 'Z'){
								SET_BIT(PORTA ,7);
								_delay_ms(50);
								CLEAR_BIT(PORTA ,7);
								break;
							}
						}
			}
		
		if (receivedData=='I')
		{
// 			SET_BIT(PORTA ,7);
// 			_delay_ms(50);
// 			CLEAR_BIT(PORTA ,7);
			if (temp_status==0)
			{
				USART_Transmit('N');
			}
			else if (temp_status==1)
			{
				USART_Transmit('L');
			}
			else if (temp_status==2)
			{
				USART_Transmit('H');
			}
			receivedData='z';
		}
			
			
		
		
	}
}

void intiallize_temp_sensor()
{
	adc_config temp_sensor={
		.refrence=adc_AVCC_pin,
		.adjust=adc_right_adjust,
		.channel=adc_CH0,
		.prescalar=adc_divide_by_64//125 kHz
	};
	
	mcal_adc_intiallize(&temp_sensor);
	//mcal_adc_read_interrupt_value();
}

void intiallize_DC_fan()
{
	gpio_pin_config dc_fan1={
		.port=portB,
		.pin=pin4,
		.direction=output,
		.logic=low,
	};
	mcal_gpio_pin_direction_intiallize(&dc_fan1);
	mcal_gpio_pin_output_write_logic(&dc_fan1,dc_fan1.logic);
	
	gpio_pin_config dc_fan2={
		.port=portB,
		.pin=pin5,
		.direction=output,
		.logic=high,
	};
	mcal_gpio_pin_direction_intiallize(&dc_fan2);
	mcal_gpio_pin_output_write_logic(&dc_fan2,dc_fan2.logic);
	
	pwm_config dc_fan_pwm={
		.mode=fast_pwm_mode,
		.clock_prescale=prescalar_divide_by_64,
	};
	mcal_PWM0_intiallize(&dc_fan_pwm);
	OCR0=0;
}

void intiallize_ac_lamp()
{
	ac_lamp.direction=output;
	ac_lamp.port=portB;
	ac_lamp.pin=pin6;
	ac_lamp.logic=high;
	mcal_gpio_pin_direction_intiallize(&ac_lamp);
}


// Interrupt service routine for USART Receive Complete
ISR(USART_RXC_vect) {
	cli();
	receivedData = UDR;
}

void auto_mode_handle_and_lcd_status_update()
{
	SET_BIT(PORTA ,7);
	_delay_ms(20);
	CLEAR_BIT(PORTA ,7);
	if(recieved_frame[1]=='A')	{
		
	//high
	if(temp_val > upper_temp)
	{
		PWM0_CLEAR_ON_UP_COUNTING();
		mcal_PWM0_increase_to_value(200);
		mcal_gpio_pin_output_write_logic(&ac_lamp,low);
		USART_TransmitString("H%");
		temp_status=2;
	}
	//low
	if(temp_val < lower_temp)
	{
		if(OCR0==200)
		{
			mcal_PWM0_decrease_from_value(200);
		}
		else{OCR0=0;}
		mcal_gpio_pin_output_write_logic(&ac_lamp,high);
		USART_TransmitString("L%");
		temp_status=1;
	}
	
	if ((temp_val>=lower_temp)&&(temp_val<=upper_temp))
	{
		if (OCR0>0)
		{
			mcal_PWM0_decrease_from_value(OCR0);
		}
		mcal_gpio_pin_output_write_logic(&ac_lamp,low);
		USART_TransmitString("N%");
		temp_status=0;
	}
	}
	else if(recieved_frame[1]=='M')
	{
		if(temp_val > upper_temp)
		{
			temp_status=2;
			USART_TransmitString("H%");
		}
		if(temp_val < lower_temp)
		{
			temp_status=1;
			USART_TransmitString("L%");
		}
		if ((temp_val>=lower_temp)&&(temp_val<=upper_temp))
		{
			temp_status=0;
			USART_TransmitString("N%");
		}
	}
}




void temp_status_display()
{
	if(isr_count>0)
	{
		if(temp_val > upper_temp)
		{
			temp_status=2;
		}
		if(temp_val < lower_temp)
		{
			temp_status=1;
		}
		if ((temp_val>=lower_temp)&&(temp_val<=upper_temp))
		{
			temp_status=0;
		}
	}
	switch(temp_status)
	{
		case 0:
		LCD_displayStringRowColumn(0,0,"normal");
		break;
		case 1:
		LCD_displayStringRowColumn(0,0,"cold  ");
		break;
		case 2:
		LCD_displayStringRowColumn(0,0,"hot   ");
		break;
	}
}

void temp_to_string(uint8 str[], uint16 temp_int)
{
	 uint8 i, rem, len = 0, n;
	 
	 n = temp_int;
	/* while (n != 0)
	 {
		 len++;
		 n /= 10;
	 }*/
	 for (i = 0; i < 3; i++)
	 {
		 rem = temp_int % 10;
		 temp_int = temp_int / 10;
		 str[3 - (i + 1)] = rem + '0';
	 }
	 str[3] = '\0';
}
