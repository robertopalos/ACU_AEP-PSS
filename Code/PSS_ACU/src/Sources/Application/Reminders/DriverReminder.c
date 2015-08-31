/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %DriverReminder.c%
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
/*============================================================================*/

/* Includes */
/* -------- */
#include "DriverReminder.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */
T_UBYTE rub_TimerD = 0;

/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
static E_DRStateListTypeEn rub_DRStateEn;
static E_DRStateListTypeEu rub_DRStateEu;

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
 
 void DR_BasicRem (void)
 {
 	CM_ChimeMsgDriver();
	TM_TelltaleMsgDriver();
 }


/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


void DR_StateMachineEn(void)
{
	switch(rub_DRStateEn)
	{
		case ENHANCED_1:
			CM_ChimeMsgDriver();
			TM_TelltaleMsgDriver();
			if(rub_TimerD > 85 && rub_Speed > 22)
			{
				rub_DRStateEn = ENHANCED_2;
			}
		break;
		
		case ENHANCED_2:
			CM_ChimeMsgDriver();
			TM_TelltaleMsgDriver();
			if(rub_TimerD > 235 && rub_Speed > 22)
			{
				rub_DRStateEn = ENHANCED_3;
			}
		break;
		
		case ENHANCED_3:
			CM_ChimeMsgDriver();
			TM_TelltaleMsgDriver();
		break;
		
		default:
			/* Error Message */
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
 void DR_StateMachineEu(void)
 {
	switch(rub_DRStateEu)
	{
		case EURO_1:
			TM_TelltaleMsgDriverEu(0);
			if(rub_Engine ==  ACTIVE)
			{
				rub_DRStateEu = EURO_2;
			}
		break;
		
		case EURO_2:
			TM_TelltaleMsgDriverEu(1);
			if(rub_Speed > 22 || rub_Distance > 250)
			{
				rub_DRStateEu = EURO_3;
			}
		break;
		
		case EURO_3:
			CM_ChimeMsgDriverEu(1);
			TM_TelltaleMsgDriverEu();
		break;
		
		default:
			/* Error Message */
		break;
	}	
 }

 