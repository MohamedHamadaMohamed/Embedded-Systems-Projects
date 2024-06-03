 /******************************************************************************
 *
 * Module: data types
 *
 * File Name: Data_Types.h
 *
 * Description: data types definations
 *
 * Author: Mohamed Hamada
 *
 *******************************************************************************/
 #ifndef DATA_TYPES_H
 #define DATA_TYPES_H
 /*     NULL pointer    */
 #ifndef NULL
 #define NULL   ((void*)0)
 #endif
 
 /*boolean data type*/
 typedef unsigned char bool;
 
 #ifndef TRUE 
 #define TRUE (1U)
 #endif 
 #ifndef FALSE 
 #define FALSE (0U)
 #endif 
 
 #ifndef HIGH 
 #define HIGH (1U)
 #endif 
 #ifndef LOW 
 #define LOW (0U)
 #endif 
 
 
 
 
 
 
 typedef unsigned char		    Uint8;
 typedef signed char   			Sint8;
 typedef unsigned short int 	Uint16;
 typedef signed short int   	Sint16;
 typedef unsigned long int 		Uint32;
 typedef signed long int   		Sint32;
 typedef float   				float32;
 typedef double   				float64;
 
 #endif