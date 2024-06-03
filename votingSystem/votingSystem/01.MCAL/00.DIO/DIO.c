/*
 * DIO.c
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */




#include "../../00.LIB/Std_types.h"
#include "../../00.LIB/Common_Macros.h"
#include "../../00.LIB/micro_config.h"


#include "DIO.h"




void Dio_Init( const Dio_ConfigType* ConfigPtr )
{
	switch(ConfigPtr->Port_Num)
	{

	/*******************************   PORT A   ***********************************/
	case PORT_A :
		switch(ConfigPtr->direction)
		{
		case INPUT :
			CLEAR_BIT(DDRA,ConfigPtr->Channel_Num);
		    switch(ConfigPtr->resistor)
		    {
		    case OFF :      CLEAR_BIT(PORTA,ConfigPtr->Channel_Num); break;
		    case PULL_DOWN :CLEAR_BIT(PORTA,ConfigPtr->Channel_Num); break;
		    case PULL_UP :  SET_BIT(PORTA,ConfigPtr->Channel_Num); break;

		    }

			break;
		case OUTPUT :
			SET_BIT(DDRA,ConfigPtr->Channel_Num);
		    switch(ConfigPtr->initial_value )
		    {
		    case HIGH : SET_BIT(PORTA,ConfigPtr->Channel_Num); break;
		    case LOW : CLEAR_BIT(PORTA,ConfigPtr->Channel_Num); break;

		    }
		    break;

		}
		break;


		/*******************************   PORT C   ***********************************/
		case PORT_B :
			switch(ConfigPtr->direction)
			{
			case INPUT :
				CLEAR_BIT(DDRB,ConfigPtr->Channel_Num);
			    switch(ConfigPtr->resistor)
			    {
			    case OFF :      CLEAR_BIT(PORTB,ConfigPtr->Channel_Num); break;
			    case PULL_DOWN :CLEAR_BIT(PORTB,ConfigPtr->Channel_Num); break;
			    case PULL_UP :  SET_BIT(PORTB,ConfigPtr->Channel_Num); break;

			    }

				break;
			case OUTPUT :
				SET_BIT(DDRB,ConfigPtr->Channel_Num);
			    switch(ConfigPtr->initial_value )
			    {
			    case HIGH : SET_BIT(PORTB,ConfigPtr->Channel_Num); break;
			    case LOW : CLEAR_BIT(PORTB,ConfigPtr->Channel_Num); break;

			    }
			    break;

			}
			break;


			/*******************************   PORT C   ***********************************/
			case PORT_C :
				switch(ConfigPtr->direction)
				{
				case INPUT :
					CLEAR_BIT(DDRC,ConfigPtr->Channel_Num);
				    switch(ConfigPtr->resistor)
				    {
				    case OFF :      CLEAR_BIT(PORTC,ConfigPtr->Channel_Num); break;
				    case PULL_DOWN :CLEAR_BIT(PORTC,ConfigPtr->Channel_Num); break;
				    case PULL_UP :  SET_BIT(PORTC,ConfigPtr->Channel_Num); break;

				    }

					break;
				case OUTPUT :
					SET_BIT(DDRC,ConfigPtr->Channel_Num);
				    switch(ConfigPtr->initial_value )
				    {
				    case HIGH : SET_BIT(PORTC,ConfigPtr->Channel_Num); break;
				    case LOW : CLEAR_BIT(PORTC,ConfigPtr->Channel_Num); break;

				    }
				    break;

				}
				break;


				/*******************************   PORT D  ***********************************/
				case PORT_D :
					switch(ConfigPtr->direction)
					{
					case INPUT :
						CLEAR_BIT(DDRD,ConfigPtr->Channel_Num);
					    switch(ConfigPtr->resistor)
					    {
					    case OFF :      CLEAR_BIT(PORTD,ConfigPtr->Channel_Num); break;
					    case PULL_DOWN :CLEAR_BIT(PORTD,ConfigPtr->Channel_Num); break;
					    case PULL_UP :  SET_BIT(PORTD,ConfigPtr->Channel_Num); break;

					    }

						break;
					case OUTPUT :
						SET_BIT(DDRD,ConfigPtr->Channel_Num);
					    switch(ConfigPtr->initial_value )
					    {
					    case HIGH : SET_BIT(PORTD,ConfigPtr->Channel_Num); break;
					    case LOW : CLEAR_BIT(PORTD,ConfigPtr->Channel_Num); break;

					    }
					    break;

					}
					break;

	}


}

void Dio_SetPinDirection( Dio_PortType PortId,Dio_ChannelType Pin, Dio_PinDirectionType Direction )
{
	switch(PortId)
	{
	case PORT_A :
		switch(Direction)
		{
		case INPUT  : CLEAR_BIT(DDRA,Pin);    break;
		case OUTPUT : SET_BIT(DDRA,Pin);      break;
		}
		break;

	case PORT_B :
		switch(Direction)
		{
		case INPUT : CLEAR_BIT(DDRB,Pin);    break;
		case OUTPUT :  SET_BIT(DDRB,Pin);    break;
		}
		break;

	case PORT_C :
		switch(Direction)
		{
		case INPUT : CLEAR_BIT(DDRC,Pin);    break;
		case OUTPUT :  SET_BIT(DDRC,Pin);    break;
		}
		break;

	case PORT_D :
		switch(Direction)
		{
		case INPUT : CLEAR_BIT(DDRD,Pin);    break;
		case OUTPUT : SET_BIT(DDRD,Pin);     break;
		}
		break;
	}


}
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{

	switch(PortId)
	{
	case PORT_A : PORTA =Level;    break;

	case PORT_B : PORTB =Level;    break;

	case PORT_C : PORTC =Level;    break;

	case PORT_D : PORTD =Level;    break;
	}


}
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
	switch(PortId)
	{

	case PORT_A : return PINA;
	case PORT_B : return PINB;
	case PORT_C : return PINC;
	case PORT_D : return PIND;


	}
	return 0;


}
void Dio_WriteChannel( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_LevelType Level )
{

	switch(PortId)
	{
	case PORT_A :
		switch(Level)
		{
		case LOW  : CLEAR_BIT(PORTA,ChannelId);    break;
		case HIGH : SET_BIT(PORTA,ChannelId);      break;
		}
		break;

	case PORT_B :
		switch(Level)
		{
	     case LOW  : CLEAR_BIT(PORTB,ChannelId);    break;
		 case HIGH : SET_BIT(PORTB,ChannelId);      break;
		}
		break;

	case PORT_C :
		switch(Level)
		{
		case LOW  : CLEAR_BIT(PORTC,ChannelId);    break;
		case HIGH : SET_BIT(PORTC,ChannelId);      break;
		}
		break;

	case PORT_D :
		switch(Level)
		{
		case LOW  : CLEAR_BIT(PORTD,ChannelId);    break;
		case HIGH : SET_BIT(PORTD,ChannelId);      break;
		}
		break;
	}



}
Dio_LevelType Dio_ReadChannel( Dio_PortType PortId,Dio_ChannelType ChannelId )
{
	switch(PortId)
	{
	case PORT_A : return GET_BIT(PINA,ChannelId);
	case PORT_B : return GET_BIT(PINB,ChannelId);
	case PORT_C : return GET_BIT(PINC,ChannelId);
	case PORT_D : return GET_BIT(PIND,ChannelId);



	}
	return 0;


}

