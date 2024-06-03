/*
 * LCD_config.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_03_LCD_LCD_CONFIG_H_
#define ATMEGA16_02_HAL_03_LCD_LCD_CONFIG_H_

#define DATA_BITS_MODE        8




#define RS       PIN_4
#define RW       PIN_5
#define EN       PIN_7

#define LCD_CTRL_PORT       PORT_D

#define LCD_DATA_PIN0       PIN_0
#define LCD_DATA_PIN1       PIN_1
#define LCD_DATA_PIN2       PIN_2
#define LCD_DATA_PIN3       PIN_3
#define LCD_DATA_PIN0       PIN_4
#define LCD_DATA_PIN1       PIN_5
#define LCD_DATA_PIN2       PIN_6
#define LCD_DATA_PIN3       PIN_7

#define LCD_DATA_PORT       PORT_C


#endif /* ATMEGA16_02_HAL_03_LCD_LCD_CONFIG_H_ */
