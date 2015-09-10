/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %TelltaleManager.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia%
* %date_created:    31/08/15 %
*=============================================================================*/
/* DESCRIPTION : Header file for the telltale driver                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/2015  | 					           | Alexis Garcia    */
/* Creation of the module 		                                              */
/*============================================================================*/

#ifndef TELLTALEMAN_H                               /* To avoid double inclusion */
#define TELLTALEMAN_H

/* Includes */
/* -------- */
#include "typedefs.h"
/* Exported types and constants */
/* ---------------------------- */

/* Types definition */

#define 	TIME_EXPIRED 	20
#define 	TIMEOUT			55
#define 	TIME_EXPIRED_EU	8
#define 	TIMEOUT_EU		100


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


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void TM_TelltaleMsgDriver(T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period);
extern void TM_TelltaleMsgPass(T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period);
extern void TM_AirbagPass (void);
extern void TM_TelltaleMsgDriverEu (void);
extern void TM_TelltaleMsgOff (void);

/* Functions macros */


/* Exported defines */


#endif

