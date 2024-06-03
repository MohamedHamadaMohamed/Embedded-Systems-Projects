/*
 * seven_segment.h
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#ifndef ATMEGA16_02_HAL_02_SEVEN_SEGMENT_SEVEN_SEGMENT_H_
#define ATMEGA16_02_HAL_02_SEVEN_SEGMENT_SEVEN_SEGMENT_H_

typedef enum
{

	ZERO = 0b00111111,
	ONE  = 0b00000110,
	TWO  = 0b01011011,
	THREE =0b01001111,
	FOUR = 0b01100110,
	FIVE = 0b01101101,
	SIX  = 0b01111101,
	SEVEN= 0b00000111,
	EIGHT= 0b01111111,
	NINE = 0b01101111
}seven_segment_numbers;

void seven_segment_init();
void seven_segment_write_number(uint8 num);

#endif /* ATMEGA16_02_HAL_02_SEVEN_SEGMENT_SEVEN_SEGMENT_H_ */
