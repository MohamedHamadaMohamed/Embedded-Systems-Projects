 /******************************************************************************
 *
 * Module: common macros
 *
 * File Name: Common_Macros.h
 *
 * Description: 
 *
 * Author: Mohamed Hamada
 *
 ********************************************************************************/
 #ifndef COMMON_MACROS_H
 #define COMMON_MACROS_H 

	/*set bit in certain bit in any register*/
 #define SET_BIT(REG,BIT)   		((REG)|=(1<<BIT))

 	/*clear bit in certain bit in any register*/
 #define CLEAR_BIT(REG,BIT)  	    ((REG)&=(~(1<<BIT)))

 	/*toggle bit in certain bit in any register*/
 #define TOGGLE_BIT(REG,BIT)  	    ((REG)^=(1<<BIT))

	/*get bit in certain bit in any register*/
 #define GET_BIT(REG,BIT)          ((REG)&=(1<<BIT))

 	/*check bit if it is clear in certain bit in any register*/
 #define BIT_IS_CLEAR(REG,BIT)     (!((REG)&(1<<BIT)))
 
 /*check bit if it is set in certain bit in any register*/
 #define BIT_IS_SET(REG,BIT)  	    ((REG)&(1<<BIT))
 
 /* Rotate right the register value with specific number of rotates */
#define ROR(REG,num) ( REG= (REG>>num) | (REG<<(8-num)) )

/* Rotate left the register value with specific number of rotates */
#define ROL(REG,num) ( REG= (REG<<num) | (REG>>(8-num)) )
 #endif