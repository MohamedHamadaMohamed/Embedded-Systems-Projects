/*
 * DC_Motor.c
 *
 * Created: 9/28/2020 10:17:01 PM
 *  Author: Mohamed Hamada
 */ 
#include "GPIO.h"
#include "DC_Motor.h"

 void DC_Motor_RotateClockWise(void)
 {
	 
	 SET_BIT(DC_Motor_PORT , IN1);
	 CLEAR_BIT(DC_Motor_PORT , IN2);
 }
 void DC_Motor_RotateAntiClockWise(void)
 {
	 
		SET_BIT(DC_Motor_PORT , IN2);
		CLEAR_BIT(DC_Motor_PORT , IN1);
 }
 void DC_Motor_stop(void)
 {
		CLEAR_BIT(DC_Motor_PORT , IN1);
		CLEAR_BIT(DC_Motor_PORT , IN2);
 }