/*
 * Timer.h
 *
 * Created: 9/24/2020 4:25:57 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"

/********************************************************************************/
/********************		    Preprocessor Macros 		**********************/
/********************************************************************************/


#define NORMAL_MODE       0
#define COMPARE_MODE      1


/********************************************************************************/
/********************		    Functions prototype 		*********************/
/********************************************************************************/
typedef enum{NO_CLOCK,CLOCK,CLOCK_8,CLOCK_64,CLOCK_256,CLOCK_1024}TIMER_Prescalar;
typedef enum {OVERFLOW,COMPARE}TIMER_Mode;
typedef enum {TIMER0,TIMER1,TIMER2}TIMER_TYPE;

typedef struct  
{
	TIMER_TYPE timerType;
	TIMER_Mode mode;
	TIMER_Prescalar prescalar ;
	Uint16 Timer_InitValue;
	Uint16 Timer_ComValue;
}TIMER_ConfigType;

void Timer_Init(const TIMER_ConfigType* config_ptr);


void Timer0_SetCallBack(void(*a_ptr)(void));
void Timer1_SetCallBack(void(*a_ptr)(void));
void Timer2_SetCallBack(void(*a_ptr)(void));


#endif /* TIMER_H_ */