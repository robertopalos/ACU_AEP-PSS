/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %ACU.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Gacia %
* %date_created:    31/08/15%
*=============================================================================*/
/* DESCRIPTION : Header file for the ACU module                               */
/*============================================================================*/
/* FUNCTION COMMENT : contains only the definitions and variables used in the */
/* 						ACU module 											  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15    |                | Alexis Garcia					  */
/* Creation of the module file, first version                                 */
/*============================================================================*/

#ifndef ACU_H                               /* To avoid double inclusion */
#define ACU_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
#define BUCKLED 		1
#define	UNBUCKELD		0
#define	UNOCCUPIED		0
#define	OCCUPIED		1
#define	UNDETERMINED	2

#define FASTENED 	0
#define	UNFASTENED	1
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */
extern T_UBYTE rub_ModeConfig;

/* WORD constants */


/* LONG and STRUCTURE constants */
enum{
	Basic_Mode = 0,
	Enhanced_Mode,
	Euro_Mode
};


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
extern void ACU_StateMachinePass(void);
extern void ACU_StateMachineDriver(void);

/* Functions macros */


/* Exported defines */


#endif

