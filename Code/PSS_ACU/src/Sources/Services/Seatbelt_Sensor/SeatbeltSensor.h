/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %SeatbeltSensor.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    29/08/2015 %
*=============================================================================*/
/* DESCRIPTION : Header file for seat sensor driver                           */
/*============================================================================*/
/* FUNCTION COMMENT : contains only the defines and variables neeeded in the  */
/*                    seat sensor module 									  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 29/08/2015 | 			              | Alexis Garcia		  */
/* Creation of the header file, fisrt version                                 */
/*============================================================================*/

#ifndef SEATBELTSENSOR_H                               /* To avoid double inclusion */
#define SEATBELTSENSOR_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */

#define 	VALID_BUCKLED		5
#define  	VALID_UNBUCKLED		5
#define		VALID_UNDETERMINED	5

/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */
typedef enum
{
	UNBUCKLED = 0,
	BUCKLED,
	UNDETERMINED
}E_SeatbeltStatusType;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern T_UBYTE SBS_GetSeatbeltStatusDriver(void);
extern T_UBYTE SBS_GetSeatbeltStatusPass(void);
extern void SBS_ReadVoltLevelDriver(void);
extern void SBS_ReadVoltLevelPass(void);

/* Functions macros */


/* Exported defines */


#endif

