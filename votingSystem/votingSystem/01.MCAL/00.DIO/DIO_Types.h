/*
 * DIO_Types.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

#include "../../00.LIB/Std_types.h"


typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef bool Dio_LevelType;
typedef uint8 Dio_PortLevelType;

typedef enum{ INPUT , OUTPUT }Dio_PinDirectionType;

typedef enum{ OFF,PULL_DOWN , PULL_UP }Dio_InternalResistor;

typedef enum{PORT_A,PORT_B,PORT_C,PORT_D}PORT;
typedef enum{
	    PIN_0=0,
		PIN_1=1,
		PIN_2=2,
		PIN_3=3,
		PIN_4=4,
		PIN_5=5,
		PIN_6=6,
		PIN_7=7
}PIN;


typedef struct {
	Dio_PortType Port_Num;
	Dio_ChannelType Channel_Num;
	Dio_PinDirectionType direction;
	Dio_InternalResistor resistor;
	bool initial_value;
}Dio_ConfigType;


#endif /* ATMEGA16_01_MCAL_DIO_DIO_TYPES_H_ */
