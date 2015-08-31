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
/*============================================================================*/

/* Includes */
/* -------- */
#include "PassengerReminder.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */
T_UBYTE rub_TimerP = 0;

/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
static E_PSStateListTypeEn rub_PSStateEn;
static E_PSStateListTypeEn rub_PSStateEu;

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
 void PR_BasicRem (void)
 {
 	CM_ChimeMsgPass();
	TM_TelltaleMsgPass();
 }


/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/


void PR_StateMachineEn(void)
{
	switch(rub_PSStateEn)
	{
		case ENHANCED_1:
			CM_ChimeMsgPass();
			TM_TelltaleMsgPass();
			if(rub_TimerP > 85 && rub_Speed > 22)
			{
				rub_PSStateEn = ENHANCED_2;
			}
		break;
		
		case ENHANCED_2:
			CM_ChimeMsgPass();
			TM_TelltaleMsgPass();
			if(rub_TimerP > 235 && rub_Speed > 22)
			{
				rub_PSStateEn = ENHANCED_3;
			}
		break;
		
		case ENHANCED_3:
			CM_ChimeMsgPass();
			TM_TelltaleMsgPass();
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
 void PR_StateMachineEu(void)
 {
	switch(rub_PSStateEu)
	{
		case EURO_1:
			TM_TelltaleMsgPassEu(0);
			if(rub_Engine ==  ACTIVE)
			{
				rub_DRStateEu = EURO_2;
			}
		break;
		
		case EURO_2:
			TM_TelltaleMsgPassEu(1);
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

 