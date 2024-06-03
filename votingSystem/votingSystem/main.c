/*
 * main.c
 *
 *  Created on: Dec 20, 2021
 *      Author: Mohamed Hamada
 */

#include "00.LIB/Common_Macros.h"
#include "00.LIB/Std_Types.h"
#include "00.LIB/micro_config.h"


#include "01.MCAL/00.DIO/DIO_Types.h"

#include "01.MCAL/00.DIO/DIO.h"

#include "01.MCAL/01.External_interrupt/External_interrupt_Types.h"

#include "01.MCAL/01.External_interrupt/External_interrupt.h"

#include "02.HAL/01.switch/switch.h"

#include "02.HAL/02.seven_segment/seven_segment.h"


void EnableGolbalInetrrupt(void);


uint8 num1 =0;
uint8 num2 =0;
uint8 num3 =0;
void fun()
{
	if(switch_readSwitch(1))
	{
		num1++;
	}
	else if (switch_readSwitch(2))
	{
		num2++;

	}
	else if (switch_readSwitch(3))
	{
		num3++;

	}
}
int main()
{
	EnableGolbalInetrrupt();
	EXTI_configType  configType1 ={EXTI0,EXTI_RISING_EDGE,fun};



	Dio_ConfigType  LED1_Config ={PORT_A,PIN_0,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED2_Config ={PORT_A,PIN_1,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED3_Config ={PORT_A,PIN_2,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED4_Config ={PORT_A,PIN_3,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED5_Config ={PORT_A,PIN_4,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED6_Config ={PORT_A,PIN_5,OUTPUT,OFF,LOW};
	Dio_ConfigType  LED7_Config ={PORT_A,PIN_6,OUTPUT,OFF,LOW};

	Dio_Init(&LED1_Config);
	Dio_Init(&LED2_Config);
	Dio_Init(&LED3_Config);
	Dio_Init(&LED4_Config);
	Dio_Init(&LED5_Config);
	Dio_Init(&LED6_Config);
	Dio_Init(&LED7_Config);

    EXTI_init(&configType1);
	switch_init();
	seven_segment_init();
	EXTI_EnableExtInterrupt(EXTI0);

	while(1)
	{
		Dio_WriteChannel( PORT_A,PIN_4, HIGH );
		Dio_WriteChannel( PORT_A,PIN_5, LOW );
		Dio_WriteChannel( PORT_A,PIN_6, LOW );
		seven_segment_write_number(num1);
		_delay_ms(3);
		Dio_WriteChannel( PORT_A,PIN_4,  LOW);
		Dio_WriteChannel( PORT_A,PIN_5,  HIGH);
		Dio_WriteChannel( PORT_A,PIN_6, LOW );
		seven_segment_write_number(num2);
		_delay_ms(3);
		
	}

}
void EnableGolbalInetrrupt(void)
{
	SREG |=(1<<7);

}
