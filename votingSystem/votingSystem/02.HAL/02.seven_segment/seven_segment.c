/*
 * seven_segment.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "../../01.MCAL/00.DIO/DIO.h"

#include "../02.seven_segment/seven_segment_config.h"
#include "../02.seven_segment/seven_segment.h"

extern Dio_ConfigType seven_segment_pin0_Config;
extern Dio_ConfigType seven_segment_pin1_Config;
extern Dio_ConfigType seven_segment_pin2_Config;
extern Dio_ConfigType seven_segment_pin3_Config;


void seven_segment_init()
{

	Dio_Init(&seven_segment_pin0_Config);
	Dio_Init(&seven_segment_pin1_Config);
	Dio_Init(&seven_segment_pin2_Config);
	Dio_Init(&seven_segment_pin3_Config);




}
void seven_segment_write_number(uint8 num)
{

	Dio_WriteChannel(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN0, GET_BIT(num,0));
	Dio_WriteChannel(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN1, GET_BIT(num,1));
	Dio_WriteChannel(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN2, GET_BIT(num,2));
	Dio_WriteChannel(SEVEN_SEGMENT_PORT,SEVEN_SEGMENT_PIN3, GET_BIT(num,3));


}
