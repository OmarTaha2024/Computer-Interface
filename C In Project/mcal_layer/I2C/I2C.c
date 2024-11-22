/*
 * I2C.c
 *
 * Created: 9/25/2023 2:18:53 PM
 *  Author: 20115
 */ 
#include "I2C.h"

static std_return_type mcal_i2c_bit_rate_calculation(uint8* bit_rate, uint16* clock_freq);
static std_return_type mcal_i2c_prescalar_choose(i2c_prescalar);

std_return_type mcal_i2c_master_mode_send_start_condition()
{
	/*
	after enable two wire communication
		1.      Clear TWINT flag by writing a logic one to it.
		2.      Set TWSTA bit to send start condition.
		3.      Set TWEN bit to initialize the TWI.
		4.      Monitor the status of TWINT flag.
		5.      Check the ACK byte (using while condition since the SCL frequency is very small as compared to micro controller clock frequency). The ACK byte can be compared by monitoring the status of TWSR.
	*/
	std_return_type ret=OK;

		TWO_WIRE_COMMUNICATION_ENABLE();
		I2C_INTERRUPT_FLAG_CLEAR_FUN();
		I2C_MASTER_MODE_START_CONDITION();
		//while(!(I2C_BUS_CHECK()));
		while(!(TWCR & (1<<TWINT)));
		while((TWSR & I2C_STATUS_REGISTER_MASK)!=I2C_START_CONDITION_SENT);
	return ret;
	
}
std_return_type mcal_i2c_master_mode_send_slave_address_master_tansmitter(uint8 add)
{
	std_return_type ret=OK;
	I2C_TANSMIT_DATA(add);
	TWO_WIRE_COMMUNICATION_ENABLE();
	I2C_INTERRUPT_FLAG_CLEAR_FUN();
	while(!(TWCR & (1<<TWINT)));
	 while((TWSR & I2C_STATUS_REGISTER_MASK)!= I2C_SLAVE_ADDRESS_AND_WRITE_AND_ACK_RECIVED);
	return ret;
}
std_return_type mcal_i2c_master_mode_send_slave_address_master_reciever(uint8 add)
{
	std_return_type ret=OK;
	I2C_TANSMIT_DATA(add);
	TWO_WIRE_COMMUNICATION_ENABLE();
	I2C_INTERRUPT_FLAG_CLEAR_FUN();
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & I2C_STATUS_REGISTER_MASK)!= I2C_SLAVE_ADDRESS_AND_READ_AND_ACK_RECIVED);
	return ret;
}

std_return_type mcal_i2c_master_mode_send_stop_condition()
{
	std_return_type ret=OK;
		I2C_INTERRUPT_FLAG_CLEAR_FUN();
		TWO_WIRE_COMMUNICATION_ENABLE();
		I2C_MASTER_MODE_STOP_CONDITION();
		while(!(TWCR & (1<<TWSTO)));  // Wait till stop condition is transmitted
	return ret;
}

std_return_type mcal_i2c_slave_mode_intiallize(uint8 slave_address)
{
	std_return_type ret=OK;
	I2C_SLAVE_MODE_WRITE_ADDRESS(slave_address);
	TWO_WIRE_COMMUNICATION_ENABLE();
	//I2C_ENABLE_ACK_IN_RECIEVER_MODE_FUN();
	I2C_INTERRUPT_FLAG_CLEAR_FUN();
	return ret;
}

std_return_type mcal_i2c_slave_mode_match_address(uint8* slave_add_ack)
{
	std_return_type ret=OK;
	if(NULL==slave_add_ack)
	{
		ret=NOT_OK;
	}
	else{
		while(!(TWCR & (1<<TWINT)));
		uint8 status= TWSR & I2C_STATUS_REGISTER_MASK;
	}
	
	return ret;
}

std_return_type mcal_i2c_send_data(uint8 sender_data){
	std_return_type ret=OK;
	I2C_TANSMIT_DATA(sender_data);
	TWO_WIRE_COMMUNICATION_ENABLE();
	I2C_INTERRUPT_FLAG_CLEAR_FUN();
	//I2C_ENABLE_ACK_IN_RECIEVER_MODE_FUN();
	while(!(TWCR & (1<<TWINT)));
	while((TWSR & I2C_STATUS_REGISTER_MASK)!= I2C_DATA_TANSMITTED_AND_ACK_RECIVED);
	return ret;
}

std_return_type mcal_i2c_read_data(uint8* recived_data)
{
	std_return_type ret=OK;
	if(NULL==recived_data)
	{
		ret=NOT_OK;
	}
	else{
		TWO_WIRE_COMMUNICATION_ENABLE();
		I2C_INTERRUPT_FLAG_CLEAR_FUN();
		I2C_ENABLE_ACK_IN_RECIEVER_MODE_FUN();
		while(!(TWCR & (1<<TWINT)));
		while((TWSR & I2C_STATUS_REGISTER_MASK)!=I2C_DATA_RECIEVED_AND_ACK_RECIVED);
		*recived_data=TWDR;
	}
	return ret;
}

static std_return_type mcal_i2c_prescalar_choose(i2c_prescalar prescalar_value){
	std_return_type ret=OK;
	switch(prescalar_value){
		case i2c_prescalar_1:
		I2C_PRESCALAR_1();
		break;
		case i2c_prescalar_4:
		I2C_PRESCALAR_1();
		break;
		case i2c_prescalar_16:
		I2C_PRESCALAR_16();
		break;
		case i2c_prescalar_64:
		I2C_PRESCALAR_64();
		break;
		default:
		I2C_PRESCALAR_1();
		break;
	}
	return ret;
}


static std_return_type mcal_i2c_bit_rate_calculation(uint8* bit_rate, uint16* clock_freq){
	std_return_type ret=OK;
	if ((NULL==bit_rate) || (NULL==clock_freq))
	{
		ret=NOT_OK;
	} 
	else
	{
		(*bit_rate) = ((F_CPU/(*clock_freq))-16)/(2*(4^(TWSR&((1<<TWPS0)|(1<<TWPS1))))); 	
		I2C_MASTER_MODE_WRITE_BIT_RATE(*bit_rate);
	}
	return ret;
}
