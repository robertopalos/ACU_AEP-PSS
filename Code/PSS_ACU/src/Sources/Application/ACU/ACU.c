/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Alexis Garcia.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15 %
*=============================================================================*/
/* DESCRIPTION : C source for the ACU unit                                    */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the main functionality of the ACU module*/
/* checks for seatbelts and occupancy and calls the reminders                 */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15    |                               | Alexis Garcia    */
/* Creation of the module file, first version                                 */
/*============================================================================*/

/* Includes */
/* -------- */
#include "ACU.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
static T_UBYTE rub_PassState;
static T_UBYTE rub_DriverState;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */

/* Inline functions */
/* ---------------- */
/**************************************************************
 *  Name                 : inline_func	2
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void ACU_StateMachineDriver(void)
{
	T_UBYTE lub_ReadStatusDriver;
	lub_ReadStatusDriver = STS_GetSeatbeltStatusDriver();
	switch(rub_DriverState)
	{
		case FASTENED:
			/*reset timer for telltale, and turn off chime and telltale*/
			if(lub_ReadStatusDriver == UNBUCKLED || lub_ReadStatusDriver == UNDETERMINED)
			{
				rub_DriverState = UNFASTENED;
			}
		break;
		
		case UNFASTENED:
			/*call for the driver reminder corresponding*/
		break;
		
		default:
			/*error message*/
		break;
	}
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void ACU_StateMachinePass(void)
{
	T_UBYTE lub_ReadStatusPass, lub_ReadStatusPassOcp;
	lub_ReadStatusPass = STS_GetSeatbeltStatusPass();
	lub_ReadStatusOcp =  STS_GetSeatStatus();
	if(lub_ReadStatusOcp == OCCUPIED)
	{
		switch(rub_PassState)
		{
			case FASTENED:
				/*reset timer for telltale, and turn off chime and telltale*/
				TM_TelltaleMsgOff();
				
				if(lub_ReadStatusPass == UNBUCKLED || lub_ReadStatusPass == UNDETERMINED)
				{
					rub_DriverState = UNFASTENED;
				}
			break;
			
			case UNFASTENED:
				/*call for the driver reminder corresponding*/
			break;
			
			default:
				/*error message*/
			break;
		}		
	}
	else
	{
		/*do nothing*/
	}
	
}

