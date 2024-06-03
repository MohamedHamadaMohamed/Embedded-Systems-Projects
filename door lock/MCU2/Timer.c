/*
 * Timer.c
 *
 * Created: 9/24/2020 4:26:33 PM
 *  Author: Mohamed Hamada
 */ 
#include "Timer.h"
static volatile void (*g_callBackptr0)(void)=NULL;
static volatile void (*g_callBackptr1)(void)=NULL;
static volatile void (*g_callBackptr2)(void)=NULL;

void Timer0_SetCallBack(void(*a_ptr)(void))
{
	g_callBackptr0 =a_ptr;
}
void Timer1_SetCallBack(void(*a_ptr)(void))
{
	g_callBackptr1 =a_ptr;
}
void Timer2_SetCallBack(void(*a_ptr)(void))
{
	g_callBackptr2 =a_ptr;
}
/*Timer 0 interrupt service routine , overflow mode */
ISR(TIMER0_OVF_vect)
{
	if (g_callBackptr0 != NULL)
	{
		(*g_callBackptr0)();
	}
}
/*Timer 0 interrupt service routine , compare  mode */
ISR(TIMER0_COMP_vect)
{
	if (g_callBackptr0 != NULL)
	{
		(*g_callBackptr0)();
	}
}
/*Timer 1 interrupt service routine , overflow mode */
ISR(TIMER1_OVF_vect)
{
	if (g_callBackptr1 != NULL)
	{
		(*g_callBackptr1)();
	}
}
/*Timer 1 interrupt service routine , compare mode */
ISR(TIMER1_COMPB_vect)
{
	if (g_callBackptr1 != NULL)
	{
		(*g_callBackptr1)();
	}
}
/*Timer 2 interrupt service routine , overflow mode */
ISR(TIMER2_OVF_vect)
{
	if (g_callBackptr2 != NULL)
	{
		(*g_callBackptr2)();
	}
}

/*Timer 2 interrupt service routine , compare mode */
ISR(TIMER2_COMP_vect)
{
	if (g_callBackptr2 != NULL)
	{
		(*g_callBackptr2)();
	}
}


/***************************************function defination *************************************/

void Timer_Init(const TIMER_ConfigType* config_ptr)
{  
	
	switch (config_ptr->timerType)
	{
		case TIMER0 : 
					SET_BIT(TCCR0,FOC0);
					TCCR0 |=config_ptr->prescalar;
					TCNT0 =config_ptr->Timer_InitValue;
					switch(config_ptr->mode)
					{
						case OVERFLOW : 
										SET_BIT(TIMSK,TOIE0);
										break;
						case COMPARE  : SET_BIT(TIMSK,OCIE0);
										OCR0=config_ptr->Timer_ComValue;
										SET_BIT(TCCR0,WGM01);
									    break;
					}
					break;
		case TIMER1 :
					SET_BIT(TCCR1A,FOC1A);
					SET_BIT(TCCR1A,FOC1B);
					TCCR1B |=config_ptr->prescalar;
					TCNT1 =config_ptr->Timer_InitValue;
					switch(config_ptr->mode)
					{
						case OVERFLOW :
										SET_BIT(TIMSK,TOIE1);
										break;
						case COMPARE  : 
										SET_BIT(TIMSK,OCIE1B);
										OCR1B=config_ptr->Timer_ComValue;
										SET_BIT(TCCR0,WGM12);
										break;
					}
					break;
		case TIMER2 :
					SET_BIT(TCCR2,FOC2);
					TCCR2 |=config_ptr->prescalar;
					TCNT2 =config_ptr->Timer_InitValue;
					switch(config_ptr->mode)
					{
						case OVERFLOW :
										SET_BIT(TIMSK,TOIE2);
										break;
						case COMPARE  : 
										SET_BIT(TIMSK,OCIE2);
										OCR2=config_ptr->Timer_ComValue;
										SET_BIT(TCCR2,WGM21);
										break;
					}
					break;
	}
}