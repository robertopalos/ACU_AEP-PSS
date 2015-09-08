/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %PassengerReminder.c%
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
/* Added Euro Enumearation. E_PRStateListTypeEu                               */
/*============================================================================*/

#ifndef PASSRREM_H                               /* To avoid double inclusion */
#define PASSRREM_H

/* Includes */
/* -------- */
#include "typedefs.h"
#include "DriverReminder.h"

/* Exported types and constants */
/* ---------------------------- */

/* Types definition */
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
	ENHANCED_1 = 0,
	ENHANCED_2, 
	ENHANCED_3 
}E_PSStateListTypeEn;

typedef enum
{
	EURO_1 = 0,
	EURO_2, 
	EURO_3 
}E_PRStateListTypeEu;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Exported functions prototypes and macros */
/* ---------------------------------------- */

/* Functions prototypes */
extern void PR_BasicRem (void);
extern void PR_StateMachineEn (void);
extern void PR_StateMachineEu(void);

/* Functions macros */


/* Exported defines */


#endif

