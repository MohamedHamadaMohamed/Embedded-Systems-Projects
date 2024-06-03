/*
 * switch.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Mohamed Hamada
 */


#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "../../01.MCAL/00.DIO/DIO.h"

#include "../01.switch/switch_config.h"
#include "../01.switch/switch.h"

#if NUM_OF_SWITCHS==1
extern Dio_ConfigType switch_1_Config ;

#elif NUM_OF_SWITCHS==2
extern Dio_ConfigType switch_1_Config ;
extern Dio_ConfigType switch_2_Config ;
#elif NUM_OF_SWITCHS==3
extern Dio_ConfigType switch_1_Config ;
extern Dio_ConfigType switch_2_Config ;
extern Dio_ConfigType switch_3_Config ;
#endif

void switch_init()
{
#if NUM_OF_SWITCHS==1
	Dio_Init(&switch_1_Config);
#elif NUM_OF_SWITCHS==2
	Dio_Init(&switch_1_Config);
	Dio_Init(&switch_2_Config);
#elif NUM_OF_SWITCHS==3
	Dio_Init(&switch_1_Config);
	Dio_Init(&switch_2_Config);
	Dio_Init(&switch_3_Config);
#endif


}
bool switch_readSwitch(uint8 SwitchNum)
{

bool pressed = 0;
#if SWITCH_PULL_UP == 0

switch(SwitchNum)
{
case 1:    pressed =(! Dio_ReadChannel( SWITCH_1_PORT,SWITCH_1_PIN) );  break;
case 2:    pressed =(! Dio_ReadChannel( SWITCH_2_PORT,SWITCH_2_PIN) );  break;
case 3:    pressed =(! Dio_ReadChannel( SWITCH_3_PORT,SWITCH_3_PIN) );  break;
default : /* error*/  break;
}
#else

switch(SwitchNum)
{
case 1:    pressed =( Dio_ReadChannel( SWITCH_1_PORT,SWITCH_1_PIN) );  break;
case 2:    pressed =( Dio_ReadChannel( SWITCH_2_PORT,SWITCH_2_PIN) );  break;
case 3:    pressed =( Dio_ReadChannel( SWITCH_3_PORT,SWITCH_3_PIN) );  break;
default : /* error*/  break;
}
#endif

return pressed;
}
