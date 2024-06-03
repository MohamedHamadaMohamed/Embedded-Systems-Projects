/*
 * Common_Macros.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


#define SET_BIT(REG,BIT)		(REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT)		(REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT)		(REG^=(1<<BIT))
#define GET_BIT(REG,BIT)        ((REG>>BIT)&0X01)


#define BIT_IS_CLEAR(REG,BIT)    (!((REG)&(1<<BIT)))
#define BIT_IS_SET(REG,BIT)      (((REG)&(1<<BIT)))

 /* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )


#endif /* ATMEGA16_00_LIB_COMMON_MACROS_H_ */
