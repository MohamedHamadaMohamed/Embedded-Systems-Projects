/*
 * keypad.c
 *
 * Created: 9/29/2020 11:26:17 AM
 *  Author: Mohamed Hamada
 */ 
#include "keypad.h"
#if N_col==3
static Uint8 keypad_3x4_adjustKeyNumber(Uint8 number);
#elif N_col==4
static Uint8 keypad_4x4_adjustKeyNumber(Uint8 number);
#endif
Uint8 keypad_getPressedKey(void)
{
	Uint8 row =0;
	Uint8 col=0;
	while(1)
	{
		for(col=0;col<N_col;col++)
		{
			KEYPAD_PORT_DIR =0b00010000<<col;
			KEYPAD_PORT_OUT = (~(0b00010000<<col));
			for (row=0;row<N_row;row++)
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_IN,row))
				{
					#if N_col==3
					return keypad_3x4_adjustKeyNumber((row*N_col)+col+1);
					
					#elif N_col==4
					return keypad_4x4_adjustKeyNumber((row*N_col)+col+1);
					
					#endif
				}
			}
		}
		
	}
}
#if N_col==3
static Uint8 keypad_3x4_adjustKeyNumber(Uint8 number)
{
	switch(number)
	{
				case 10: return '*'; // ASCII Code of *
				break;
				case 11: return 0;
				break;
				case 12: return '#'; // ASCII Code of #
				break;
				default: return number;
	}
}
#elif N_col==4
static Uint8 keypad_4x4_adjustKeyNumber(Uint8 number)
{
	switch(number)
	{
				case 1: return 7;
				break;
				case 2: return 8;
				break;
				case 3: return 9;
				break;
				case 4: return '%'; // ASCII Code of %
				break;
				case 5: return 4;
				break;
				case 6: return 5;
				break;
				case 7: return 6;
				break;
				case 8: return '*'; /* ASCII Code of '*' */
				break;
				case 9: return 1;
				break;
				case 10: return 2;
				break;
				case 11: return 3;
				break;
				case 12: return '-'; /* ASCII Code of '-' */
				break;
				case 13: return 13;  /* ASCII of Enter */
				break;
				case 14: return 0;
				break;
				case 15: return '='; /* ASCII Code of '=' */
				break;
				case 16: return '+'; /* ASCII Code of '+' */
				break;
				default: return number;
	}
}
#endif