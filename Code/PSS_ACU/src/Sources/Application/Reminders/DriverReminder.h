/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %DriverReminder.h%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15%
*=============================================================================*/
/* DESCRIPTION :                                        */
/*============================================================================*/
/* FUNCTION COMMENT : */
/*                                                   */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15  |                               | Alexis Garcia      */
/* Creation of the module, first version                                      */
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/15  |                               | Alexis Garcia      */
/* Renamed enumeration to implement en DriverReminder.c   Roberto Palos       */
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

