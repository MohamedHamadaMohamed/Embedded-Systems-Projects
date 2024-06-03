/*
 * DC_Motor.h
 *
 * Created: 9/28/2020 10:17:12 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Micro_Config.h"
#include "Data_Types.h"
#include "Common_Macros.h"


 /********************************************************************************/
 /********************		    Functions prototypes 		**********************/
 /********************************************************************************/
 
 #define  DC_Motor_PORT			PORTD
 #define  IN1					PD6
 #define  IN2                   PD7
 /*	----------------------------------------------------------------------------------------------			           				 
		function name : DC_Motor_RotateClockWise
        Description   : this function is response to rotate DC motor in clockwise
		[Arguments]   : void
		[return]      : void    
    -----------------------------------------------------------------------------------------------*/
 
 void DC_Motor_RotateClockWise(void);
 
 /*	----------------------------------------------------------------------------------------------			           				 
		function name : DC_Motor_RotateAntiClockWise
        Description   : this function is response to rotate DC motor in anti clockwise
		[Arguments]   : void
		[return]      : void    
    -----------------------------------------------------------------------------------------------*/
 void DC_Motor_RotateAntiClockWise(void);

/*	----------------------------------------------------------------------------------------------			           				 
		function name : DC_Motor_stop
        Description   : this function is response to stop motor
		[Arguments]   : void
		[return]      : void    
    -----------------------------------------------------------------------------------------------*/
 void DC_Motor_stop(void);
#endif /* DC_MOTOR_H_ */