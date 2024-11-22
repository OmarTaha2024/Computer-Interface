/*
 * intiallization.h
 *
 * Created: 12/13/2023 11:18:07 PM
 *  Author: omara
 */ 


#ifndef INTIALLIZATION_H_
#define INTIALLIZATION_H_
#include "ecu_layer/push_button/ecu_push_button.h"
#include "mcal_layer/interrupt/interrupt_module.h"
#include "mcal_layer/ADC/ADC_module.h"
#include "mcal_layer/timer0/timer0.h"
#include "mcal_layer/USART/USART.h"
#include "mcal_layer/I2C/I2C.h"
#include "mcal_layer/PWM/PWM.h"

void intiallize_temp_sensor();
void intiallize_DC_fan();



#endif /* INTIALLIZATION_H_ */