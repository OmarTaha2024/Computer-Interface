/*
 * mcal_std_types.h
 *
 * Created: 8/31/2023 5:08:32 PM
 *  Author: 20115
 */ 


#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_

/*******Includes********/
#include "compiler.h"
#include "std_libraries.h"

/*******macro decerations and defintions********/

#define  NOT_OK (std_return_type) 0
#define OK (std_return_type) 1
#define LOGIC_LOW (uint8) 0
#define LOGIC_HIGH (uint8) 1
/*******data types declerations********/
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long sint64;
typedef  uint8 std_return_type;

#define NULL 0

#endif /* MCAL_STD_TYPES_H_ */