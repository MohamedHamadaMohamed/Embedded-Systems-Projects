/*
 * External_interrupt_Types.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_
#define ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_


typedef enum {EXTI_LOW_LEVEL,EXTI_LOGICAL_CHANGE,EXTI_FALLING_EDGE,EXTI_RISING_EDGE}Sense_Control;
typedef enum {EXTI0,EXTI1,EXTI2}EXTI;

typedef struct
{
	EXTI EXTI_type;
	Sense_Control SenseControl;
	void (*EXTI_callBackPtr)(void);
}EXTI_configType;

#endif /* ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_TYPES_H_ */
