/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %ChimeManager.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15%
*=============================================================================*/
/* DESCRIPTION : Header file for chime manager                                */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15    | 				               | Alexis Garcia    */
/* Creation of the header file	                                              */
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/15    | 				               | Roberto Palos    */
/* Header update functions prototypes.                                        */
/*============================================================================*/

#ifndef CHIMEMANAGER_H                               /* To avoid double inclusion */
#define CHIMEMANAGER_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
#define TIME_EXPIRED 8
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */

extern T_UBYTE rub_Time;

/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTES */


/* WORDS */


/* LONGS and STRUCTURES */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void CM_ChimeMsgDriver(T_UBYTE lub_Tone, T_UBYTE lub_Cadence_Period, T_UBYTE lub_Repetitions, T_UBYTE lub_Duty_Cycle);
extern void CM_ChimeMsgPass(T_UBYTE Tone, T_UBYTE Cadence_Period, T_UBYTE Repetitions, T_UBYTE Duty_Cycle);
extern void CM_ChimeMsgOff(T_UBYTE Driver_Ind_Aux, T_UBYTE Passenger_Ind_Aux);

/* Functions macros */


/* Exported defines */


#endif

