/*
 * External_interrupt.c
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "External_interrupt_Types.h"
#include "External_interrupt.h"

static void (*EXTI_callBack[3])(void)= {NULL ,NULL ,NULL};

void EXTI_init(EXTI_configType* config)
{
	switch(config->EXTI_type)
	{
	case EXTI0 :
		EXTI_callBack[0] = config->EXTI_callBackPtr;
		MCUCR &= 0b11111100;
		MCUCR |= config->SenseControl;
		break;

	case EXTI1 :
		EXTI_callBack[1] = config->EXTI_callBackPtr;
		MCUCR &= 0b11110011;
		MCUCR |= (config->SenseControl<<2);
		break;

	case EXTI2:
		EXTI_callBack[2] = config->EXTI_callBackPtr;
		switch(config->SenseControl )
		{
		case EXTI_FALLING_EDGE : CLEAR_BIT(MCUCSR,ISC2);  break;
		case EXTI_RISING_EDGE  : SET_BIT(MCUCSR,ISC2);    break;

		}

		break;


	}


}
void EXTI_EnableExtInterrupt(EXTI Line)
{
	switch(Line)
	{
	case EXTI0:SET_BIT(GICR,INT0); break;
	case EXTI1:SET_BIT(GICR,INT1); break;
	case EXTI2:SET_BIT(GICR,INT2); break;

	}
}
void EXTI_DisableExtInterrupt(EXTI Line)
{
	switch(Line)
	{
	case EXTI0:CLEAR_BIT(GICR,INT0); break;
	case EXTI1:CLEAR_BIT(GICR,INT1); break;
	case EXTI2:CLEAR_BIT(GICR,INT2); break;

	}

}

ISR(INT0_vect)
{
	if(EXTI_callBack[0]!= NULL)
	{
		EXTI_callBack[0]();
	}
}

ISR(INT1_vect)
{
	if(EXTI_callBack[1]!= NULL)
	{
		EXTI_callBack[1]();
	}
}

ISR(INT2_vect)
{
	if(EXTI_callBack[2]!= NULL)
	{
		EXTI_callBack[2]();
	}

}

