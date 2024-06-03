/*
 * decoder.c
 *
 *  Created on: Dec 25, 2021
 *      Author: Mohamed Hamada
 */

#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"

#include "../../01.MCAL/00.DIO/DIO.h"

#include <math.h>

#include "decoder_config.h"
#include "decoder.h"

#if NUM_OF_INPUT == 1
	extern Dio_ConfigType  decoder_input_1_Config ;
#elif NUM_OF_INPUT == 2
	extern Dio_ConfigType  decoder_input_1_Config ;
	extern Dio_ConfigType  decoder_input_2_Config ;
#elif NUM_OF_INPUT == 3
	extern Dio_ConfigType  decoder_input_1_Config ;
	extern Dio_ConfigType  decoder_input_2_Config ;
	extern Dio_ConfigType  decoder_input_3_Config ;

#elif NUM_OF_INPUT == 4
	extern Dio_ConfigType  decoder_input_1_Config ;
	extern Dio_ConfigType  decoder_input_2_Config ;
	extern Dio_ConfigType  decoder_input_3_Config ;
	extern Dio_ConfigType  decoder_input_4_Config ;
#elif NUM_OF_INPUT == 5
extern Dio_ConfigType  decoder_input_1_Config ;
	extern Dio_ConfigType  decoder_input_2_Config ;
	extern Dio_ConfigType  decoder_input_3_Config ;
	extern Dio_ConfigType  decoder_input_4_Config ;
	extern Dio_ConfigType  decoder_input_5_Config ;

#elif NUM_OF_INPUT == 6
	extern Dio_ConfigType  decoder_input_1_Config ;
	extern Dio_ConfigType  decoder_input_2_Config ;
	extern Dio_ConfigType  decoder_input_3_Config ;
	extern Dio_ConfigType  decoder_input_4_Config ;
	extern Dio_ConfigType  decoder_input_5_Config ;
	extern Dio_ConfigType  decoder_input_6_Config ;

#endif
void decoder_init(void)
{
#if NUM_OF_INPUT == 1
	Dio_Init(&decoder_input_1_Config);
#elif NUM_OF_INPUT == 2
	Dio_Init(&decoder_input_1_Config);
	Dio_Init(&decoder_input_2_Config);

#elif NUM_OF_INPUT == 3
	Dio_Init(&decoder_input_1_Config);
	Dio_Init(&decoder_input_2_Config);
	Dio_Init(&decoder_input_3_Config);

#elif NUM_OF_INPUT == 4
	Dio_Init(&decoder_input_1_Config);
	Dio_Init(&decoder_input_2_Config);
	Dio_Init(&decoder_input_3_Config);
	Dio_Init(&decoder_input_4_Config);

#elif NUM_OF_INPUT == 5
	Dio_Init(&decoder_input_1_Config);
	Dio_Init(&decoder_input_2_Config);
	Dio_Init(&decoder_input_3_Config);
	Dio_Init(&decoder_input_4_Config);
	Dio_Init(&decoder_input_5_Config);

#elif NUM_OF_INPUT == 6
	Dio_Init(&decoder_input_1_Config);
	Dio_Init(&decoder_input_2_Config);
	Dio_Init(&decoder_input_3_Config);
	Dio_Init(&decoder_input_4_Config);
	Dio_Init(&decoder_input_5_Config);
	Dio_Init(&decoder_input_6_Config);

#endif
}
void decoder_input(uint8 input)
{
#if NUM_OF_INPUT == 1

	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );

#elif NUM_OF_INPUT == 2
	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( DECODER_INPUT_2_PORT,DECODER_INPUT_2_PIN, GET_BIT(input,1) );

#elif NUM_OF_INPUT == 3
	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( DECODER_INPUT_2_PORT,DECODER_INPUT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( DECODER_INPUT_3_PORT,DECODER_INPUT_3_PIN, GET_BIT(input,2) );

#elif NUM_OF_INPUT == 4
	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( DECODER_INPUT_2_PORT,DECODER_INPUT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( DECODER_INPUT_3_PORT,DECODER_INPUT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( DECODER_INPUT_4_PORT,DECODER_INPUT_4_PIN, GET_BIT(input,3) );

#elif NUM_OF_INPUT == 5
	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( DECODER_INPUT_2_PORT,DECODER_INPUT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( DECODER_INPUT_3_PORT,DECODER_INPUT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( DECODER_INPUT_4_PORT,DECODER_INPUT_4_PIN, GET_BIT(input,3) );
	Dio_WriteChannel( DECODER_INPUT_5_PORT,DECODER_INPUT_5_PIN, GET_BIT(input,4) );

#elif NUM_OF_INPUT == 6
	Dio_WriteChannel( DECODER_INPUT_1_PORT,DECODER_INPUT_1_PIN, GET_BIT(input,0) );
	Dio_WriteChannel( DECODER_INPUT_2_PORT,DECODER_INPUT_2_PIN, GET_BIT(input,1) );
	Dio_WriteChannel( DECODER_INPUT_3_PORT,DECODER_INPUT_3_PIN, GET_BIT(input,2) );
	Dio_WriteChannel( DECODER_INPUT_4_PORT,DECODER_INPUT_4_PIN, GET_BIT(input,3) );
	Dio_WriteChannel( DECODER_INPUT_5_PORT,DECODER_INPUT_5_PIN, GET_BIT(input,4) );
	Dio_WriteChannel( DECODER_INPUT_6_PORT,DECODER_INPUT_6_PIN, GET_BIT(input,5) );

#endif


}
