/*
 * switch_config.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_01_SWITCH_SWITCH_CONFIG_H_
#define ATMEGA16_02_HAL_01_SWITCH_SWITCH_CONFIG_H_

#define NUM_OF_SWITCHS		3

#define SWITCH_PULL_UP    1

#if NUM_OF_SWITCHS==1
#define SWITCH_1_PORT       PORT_A
#define SWITCH_1_PIN        PIN1
#elif NUM_OF_SWITCHS==2

#define SWITCH_1_PORT       PORT_A
#define SWITCH_1_PIN        PIN1

#define SWITCH_2_PORT       PORT_A
#define SWITCH_2_PIN        PIN1

#elif NUM_OF_SWITCHS==3

#define SWITCH_1_PORT       PORT_D
#define SWITCH_1_PIN        PIN3

#define SWITCH_2_PORT       PORT_D
#define SWITCH_2_PIN        PIN4

#define SWITCH_3_PORT       PORT_D
#define SWITCH_3_PIN        PIN5
#endif
#endif /* ATMEGA16_02_HAL_01_SWITCH_SWITCH_CONFIG_H_ */
