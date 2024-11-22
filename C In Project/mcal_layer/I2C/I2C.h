/*
 * I2C.h
 *
 * Created: 9/25/2023 2:19:09 PM
 *  Author: 20115
 */ 


#ifndef I2C_H_
#define I2C_H_

/*******Includes********/
#include "../interrupt/interrupt_module.h"
#include "../mcal_layer_header_files/mcal_std_types.h"
#include <util/delay.h>

/*********Macro defintions****/
#define I2C_SLAVE_MODE					0
#define I2C_MASTER_MODE					1
#define I2C_MASTER_OR_SLAVE_MODE		2
#define I2C_MODE  I2C_MASTER_MODE

#define I2C_NOT_RECIEVED_ACK	(TWSR & 0xF8)!= 0x08

#define I2C_STATUS_REGISTER_MASK								(uint8)0xF8

/************master status***********/
#define I2C_ERROR_BUS											(uint8)0x00
#define I2C_START_CONDITION_SENT								(uint8)0x08
#define I2C_REPEATED_START_CONDITION_SENT						(uint8)0x10
#define I2C_SLAVE_ADDRESS_AND_WRITE_AND_ACK_RECIVED				(uint8)0x18 //master is transmitter
#define I2C_SLAVE_ADDRESS_AND_WRITE_AND_NACK_RECIVED			(uint8)0x20
#define I2C_DATA_TANSMITTED_AND_ACK_RECIVED						(uint8)0x28
#define I2C_DATA_TANSMITTED_AND_NACK_RECIVED					(uint8)0x30
#define I2C_SLAVE_ADDRESS_AND_READ_AND_ACK_RECIVED				(uint8)0x40 //master is receiver
#define I2C_SLAVE_ADDRESS_AND_READ_AND_NACK_RECIVED				(uint8)0x48
#define I2C_DATA_RECIEVED_AND_ACK_RECIVED						(uint8)0x50
#define I2C_DATA_RECIEVED_AND_NACK_RECIVED						(uint8)0x58
#define I2C_STOP_CONDITION_SENT									(uint8)0x60

/************slave status***********/



#define I2C_BUS_IS_BUSY			1
#define I2C_BUS_IS_FREE			0
/*******macro functions********/

//to enable two wire communication
#define TWO_WIRE_COMMUNICATION_ENABLE()					TWCR|=(1<<TWEN)
//to enable two wire communication interrupt enable
#define TWO_WIRE_COMMUNICATION_INTERRUPT_ENABLE()		TWCR|=(1<<TWIE)
#define I2C_BUS_CHECK()									TWCR&(1<<TWINT)//1 free
#define I2C_INTERRUPT_FLAG_CLEAR_FUN()					TWCR|=(1<<TWINT)
#define I2C_ENABLE_ACK_IN_RECIEVER_MODE_FUN()			TWCR|=(1<<TWEA)
#define I2C_DISABLE_ACK_IN_TRANSMIT_MODE_FUN()			TWCR&=~(1<<TWEA)

#if ((I2C_MODE==I2C_MASTER_MODE)||(I2C_MODE==I2C_MASTER_OR_SLAVE_MODE))

//to generate start condition in master mode
#define I2C_MASTER_MODE_START_CONDITION()				TWCR|=(1<<TWSTA)
//to generate stop condition in master mode
#define I2C_MASTER_MODE_STOP_CONDITION()				TWCR|=(1<<TWSTO)
//write collision flag set when bus is busy  flag=1 -> busy , flag=0 -> free
#define I2C_CHECK_MASTER_MODE_WRITE_COLLISION_FLAG()				UCSRA&(1<<RXC)
#define I2C_MASTER_MODE_WRITE_BIT_RATE(bit_rate_value)				TWBR=(uint8)(bit_rate_value)
//in first frame sent it will be the slave address
#define I2C_MASTER_MODE_WRITE_DATE(master_data)						TWDR=(uint8)(master_data)

#define I2C_SLAVE_MODE_WRITE_ADDRESS(slave_add)						TWAR=(uint8)(slave_add)
#endif


//enable address register to be in general call
#define I2C_GENERAL_CALL_ENABLE_FUN()					TWAR|=(1<<TWGCE)

#define I2C_TANSMIT_DATA(data)							TWDR=(data) //to call it TWINT must be set
				
//to configure prescalar value
#define I2C_PRESCALAR_1()								TWSR&=~(1<<TWPS1);\
														TWSR&=~(1<<TWPS0)
#define I2C_PRESCALAR_4()								TWSR&=~(1<<TWPS1);\
														TWSR|=(1<<TWPS0)
#define I2C_PRESCALAR_16()								TWSR|=(1<<TWPS1);\
														TWSR&=~(1<<TWPS0)
#define I2C_PRESCALAR_64()								TWSR|=(1<<TWPS1);\
														TWSR|=(1<<TWPS0)
/*******user data types decleration********/
typedef enum{
	i2c_prescalar_1=0,
	i2c_prescalar_4,
	i2c_prescalar_16,
	i2c_prescalar_64,
}i2c_prescalar;

typedef enum{
	i2c_slave_address_match_and_reciver,
	i2c_slave_address_match_and_transmitter,
	i2c_slave_general_call_adress,
	}i2c_address_match;

#if (I2C_MODE==I2C_MASTER_OR_SLAVE_MODE)

typedef enum{
	i2c_master_mode=0,
	i2c_slave_mode,
}i2c_mode;

typedef struct{
	i2c_prescalar prescalar;
	uint16 clock_frequency;
	uint8 bit_rate_value;
	i2c_mode
}i2c_config;

#endif

#if (I2C_MODE==I2C_MASTER_MODE)
typedef struct{
	i2c_prescalar prescalar;
	uint16 clock_frequency;
	uint8 bit_rate_value;
}i2c_master_config;
#endif

#if (I2C_MODE==I2C_MASTER_MODE)
typedef struct{
	i2c_prescalar prescalar;
	uint16 clock_frequency;
	uint8 bit_rate_value;
	uint8 address_ack;
}i2c_slave_config;
#endif




/*******functions decleration********/
std_return_type mcal_i2c_master_mode_send_start_condition();
std_return_type mcal_i2c_master_mode_send_slave_address_master_tansmitter(uint8);
std_return_type mcal_i2c_master_mode_send_slave_address_master_reciever(uint8);
std_return_type mcal_i2c_master_mode_send_stop_condition();
std_return_type mcal_i2c_slave_mode_intiallize(uint8);
std_return_type mcal_i2c_slave_mode_match_address();
std_return_type mcal_i2c_send_data(uint8);
std_return_type mcal_i2c_read_data(uint8*);

#endif /* I2C_H_ */