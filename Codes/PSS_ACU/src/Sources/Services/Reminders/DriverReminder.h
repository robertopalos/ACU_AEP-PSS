/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %template.h%
* Instance:         RPL_1
* %version:         1 %
* %created_by:      uid02495 %
* %date_created:    Fri Feb 28 13:41:01 2003 %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | DD/MM/YYYY  | SAR/SIF/SCN_xxx               | Mr. Template     */
/* Integration under Continuus CM                                             */
/*============================================================================*/

#ifndef DRIVERREM_H                               /* To avoid double inclusion */
#define DRIVERREM_H

/* Includes */
/* -------- */
#include "typedefs.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
/* typedef */


/*==================================================*/ 
/* Declaration of exported constants                */
/*==================================================*/ 
/* BYTE constants */
extern T_UBYTE rub_TimerD;
extern T_UWORD rub_Speed;
extern T_UBYTE rub_EngineStatus;
extern T_UWORD rub_Distance;
extern T_UBYTE rub_DoorStatus;

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
	ENHANCED_1D = 0,
	ENHANCED_2D, 
	ENHANCED_3D 
}E_DRStateListTypeEn;

typedef enum
{
	EURO_1D = 0,
	EURO_2D, 
	EURO_3D 
}E_DRStateListTypeEu;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void DR_BasicRem (void);
extern void DR_StateMachineEn (void);
extern void DR_StateMachineEu (void);
/* Functions macros */


/* Exported defines */


#endif

