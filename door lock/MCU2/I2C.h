/*
 * I2C.h
 *
 * Created: 10/1/2020 6:42:34 PM
 *  Author: Mohamed Hamada
 */ 


#ifndef I2C_H_
#define I2C_H_



#include "micro_config.h"
#include "Data_Types.h"
#include "Common_Macros.h"


/* I2C Status Bits in the TWSR Register */
#define TW_START         0x08 // start has been sent
#define TW_REP_START     0x10 // repeated start
#define TW_MT_SLA_W_ACK  0x18 // Master transmit ( slave address + Write request ) to slave + Ack received from slave
#define TW_MT_SLA_R_ACK  0x40 // Master transmit ( slave address + Read request ) to slave + Ack received from slave
#define TW_MT_DATA_ACK   0x28 // Master transmit data and ACK has been received from Slave.
#define TW_MR_DATA_ACK   0x50 // Master received data and send ACK to slave
#define TW_MR_DATA_NACK  0x58 // Master received data but doesn't send ACK to slave





void TWI_init(void);
void TWI_start(void);
void TWI_stop(void);
void TWI_write(Uint8 data);
Uint8 TWI_read_with_ACK(void);
Uint8 TWI_read_with_NACK(void);
Uint8 TWI_getStatus(void);
#endif /* I2C_H_ */