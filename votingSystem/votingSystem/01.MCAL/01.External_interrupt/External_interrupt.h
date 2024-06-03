/*
 * External_interrupt.h
 *
 *  Created on: Sep 20, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

void EXTI_init(EXTI_configType *config);
void EXTI_EnableExtInterrupt(EXTI Line);
void EXTI_DisableExtInterrupt(EXTI Line);


#endif /* ATMEGA16_01_MCAL_01_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
