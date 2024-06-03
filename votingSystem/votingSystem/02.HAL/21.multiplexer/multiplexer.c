/*
 * multiplexer.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Mohamed Hamada
 */
#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include <math.h>
#include "multiplexer_config.h"
#include "multiplexer.h"

#if NUM_OF_SELECT == 1
	extern Dio_ConfigType  multiplexer_select_input_1_Config ;
#elif NUM_OF_SELECT == 2
	extern Dio_ConfigType  multiplexer_select_input_1_Config ;
	extern Dio_ConfigType  multiplexer_select_input_2_Config ;
#elif NUM_OF_SELECT == 3
	extern Dio_ConfigType  multiplexer_select_input_1_Config ;
	extern Dio_ConfigType  multiplexer_select_input_2_Config ;
	extern Dio_ConfigType  multiplexer_select_input_3_Config ;

#elif NUM_OF_SELECT == 4
	extern Dio_ConfigType  multiplexer_select_input_1_Config ;
	extern Dio_ConfigType  multiplexer_select_input_2_Config ;
	extern Dio_ConfigType  multiplexer_select_input_3_Config ;
	extern Dio_ConfigType  multiplexer_select_input_4_Config ;
#elif NUM_OF_SELECT == 5
    extern Dio_ConfigType  multiplexer_select_input_1_Config ;
	extern Dio_ConfigType  multiplexer_select_input_2_Config ;
	extern Dio_ConfigType  multiplexer_select_input_3_Config ;
	extern Dio_ConfigType  multiplexer_select_input_4_Config ;
	extern Dio_ConfigType  multiplexer_select_input_5_Config ;

#elif NUM_OF_SELECT == 6
	extern Dio_ConfigType  multiplexer_select_input_1_Config ;
	extern Dio_ConfigType  multiplexer_select_input_2_Config ;
	extern Dio_ConfigType  multiplexer_select_input_3_Config ;
	extern Dio_ConfigType  multiplexer_select_input_4_Config ;
	extern Dio_ConfigType  multiplexer_select_input_5_Config ;
	extern Dio_ConfigType  multiplexer_select_input_6_Config ;

#endif
void multiplexer_init(void)
{
#if NUM_OF_SELECT == 1
	Dio_Init(&multiplexer_select_input_1_Config);
#elif NUM_OF_SELECT == 2
	Dio_Init(&multiplexer_select_input_1_Config);
	Dio_Init(&multiplexer_select_input_2_Config);

#elif NUM_OF_SELECT == 3
	Dio_Init(&multiplexer_select_input_1_Config);
	Dio_Init(&multiplexer_select_input_2_Config);
	Dio_Init(&multiplexer_select_input_3_Config);

#elif NUM_OF_SELECT == 4
	Dio_Init(&multiplexer_select_input_1_Config);
	Dio_Init(&multiplexer_select_input_2_Config);
	Dio_Init(&multiplexer_select_input_3_Config);
	Dio_Init(&multiplexer_select_input_4_Config);

#elif NUM_OF_SELECT == 5
	Dio_Init(&multiplexer_select_input_1_Config);
	Dio_Init(&multiplexer_select_input_2_Config);
	Dio_Init(&multiplexer_select_input_3_Config);
	Dio_Init(&multiplexer_select_input_4_Config);
	Dio_Init(&multiplexer_select_input_5_Config);

#elif NUM_OF_SELECT == 6
	Dio_Init(&multiplexer_select_input_1_Config);
	Dio_Init(&multiplexer_select_input_2_Config);
	Dio_Init(&multiplexer_select_input_3_Config);
	Dio_Init(&multiplexer_select_input_4_Config);
	Dio_Init(&multiplexer_select_input_5_Config);
	Dio_Init(&multiplexer_select_input_6_Config);

#endif
}
void multiplexer_input(uint8 input)
{
#if NUM_OF_SELECT == 1

	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );

#elif NUM_OF_SELECT == 2
	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_2_PORT,MULTOPLEXER_SELECT_2_PIN, GET_BIT(input,1) );

#elif NUM_OF_SELECT == 3
	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_2_PORT,MULTOPLEXER_SELECT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_3_PORT,MULTOPLEXER_SELECT_3_PIN, GET_BIT(input,2) );

#elif NUM_OF_SELECT == 4
	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_2_PORT,MULTOPLEXER_SELECT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_3_PORT,MULTOPLEXER_SELECT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_4_PORT,MULTOPLEXER_SELECT_4_PIN, GET_BIT(input,3) );

#elif NUM_OF_SELECT == 5
	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_2_PORT,MULTOPLEXER_SELECT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_3_PORT,MULTOPLEXER_SELECT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_4_PORT,MULTOPLEXER_SELECT_4_PIN, GET_BIT(input,3) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_5_PORT,MULTOPLEXER_SELECT_5_PIN, GET_BIT(input,4) );

#elif NUM_OF_SELECT == 6
	Dio_WriteChannel( MULTOPLEXER_SELECT_1_PORT,MULTOPLEXER_SELECT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_2_PORT,MULTOPLEXER_SELECT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_3_PORT,MULTOPLEXER_SELECT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_4_PORT,MULTOPLEXER_SELECT_4_PIN, GET_BIT(input,3) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_5_PORT,MULTOPLEXER_SELECT_5_PIN, GET_BIT(input,4) );
	Dio_WriteChannel( MULTOPLEXER_SELECT_6_PORT,MULTOPLEXER_SELECT_6_PIN, GET_BIT(input,5) );

#endif


}
