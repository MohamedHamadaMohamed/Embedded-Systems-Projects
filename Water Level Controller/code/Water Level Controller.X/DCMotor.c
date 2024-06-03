/*
 * File:   DCMotor.c
 * Author: Mohamed Hamada
 *
 * Created on September 30, 2020, 4:04 PM
 */


#include "DCMotor.h"


void DCMotor_rotateClockwise()
{
    /*CLEAR_BIT(DCMotor_port,IN2);
    SET_BIT(DCMotor_port,IN1);*/
    IN1=0;
    IN2=1;
    
}
void DCMotor_rotateAntiClockwise()
{
    /*CLEAR_BIT(DCMotor_port,IN1);
    SET_BIT(DCMotor_port,IN2);*/
    IN1=1;
    IN2=0;
}
void DCMotor_stop()
{
    CLEAR_BIT(DCMotor_port,IN1);
    CLEAR_BIT(DCMotor_port,IN2);
}