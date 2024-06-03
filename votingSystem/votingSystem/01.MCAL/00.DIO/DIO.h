/*
 * DIO.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef DIO_H_
#define DIO_H_

#include "../00.DIO/DIO_Types.h"


void Dio_Init( const Dio_ConfigType *ConfigPtr );
void Dio_SetPinDirection( Dio_PortType PortId,Dio_ChannelType Pin, Dio_PinDirectionType Direction );
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
void Dio_WriteChannel( Dio_PortType PortId,Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_LevelType Dio_ReadChannel( Dio_PortType PortId,Dio_ChannelType ChannelId );

#endif /* ATMEGA16_01_MCAL_DIO_DIO_H_ */
