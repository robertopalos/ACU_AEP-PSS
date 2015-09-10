/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %SeatSensor.h%
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

#ifndef SEATSENSOR_H                               /* To avoid double inclusion */
#define SEATSENSOR_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */

#define 	VALID_SIGNAL_OC		6
#define  	VALID_SIGNAL_UNOC	6
#define		VALID_SIGNAL_UNK	6

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
	NO_OCUPANCY = 0,
	OCUPANCY,
	UNKNOWN2
}E_SeatStatusType;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void STS_StateMachine();
extern T_UBYTE STS_GetSeatStatus(void);
extern void STS_ReadVoltLevel(void);

/* Functions macros */


/* Exported defines */


#endif

