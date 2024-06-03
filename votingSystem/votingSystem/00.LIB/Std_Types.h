/*
 * Std_Types.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Mohamed Hamada
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef unsigned char                uint8;
typedef signed char                  sint8;

typedef unsigned short int           uint16;
typedef signed short int             sint16;

typedef unsigned long int            uint32;
typedef signed long int              sint32;


typedef unsigned long long int        uint64;
typedef signed long long int          sint64;


typedef float                         float32;
typedef double                        float64;


/************************* Boolean ****************************/
typedef uint8    bool;


#ifndef TRUE
#define TRUE           1
#endif

#ifndef FALSE
#define FALSE          0
#endif


#ifndef HIGH
#define HIGH           1
#endif

#ifndef LOW
#define LOW            0
#endif

#ifndef ENABLE
#define ENABLE         1
#endif

#ifndef DISABLE
#define DISABLE         1
#endif


#ifndef NULL
#define NULL            ((void*)0)
#endif



#endif /* ATMEGA16_00_LIB_STD_TYPES_H_ */
