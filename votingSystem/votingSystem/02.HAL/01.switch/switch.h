/*
 * switch.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_01_SWITCH_SWITCH_H_
#define ATMEGA16_02_HAL_01_SWITCH_SWITCH_H_
#include "../../00.LIB/Std_types.h"


void switch_init();
bool switch_readSwitch(uint8 SwitchNum);
#endif /* ATMEGA16_02_HAL_01_SWITCH_SWITCH_H_ */
