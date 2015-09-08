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
/*  1.1      | 08/09/2015  |                               | Alexis Garcia    */
/* Modification of functionality                             Roberto Palos    */
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
static E_PRStateListTypeEu rub_PSStateEu;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */



/* Exported functions prototypes */
/* ----------------------------- */
/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	PR_BasicRem
 *  Description          :	passenger reminder basic mode of functionality
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
 void PR_BasicRem (void)
 {
	TM_TelltaleMsgPass(01,75,05);
	CM_ChimeMsgPass(75,250,24,100);
 }


/**************************************************************
 *  Name                 :	PR_StateMachineEn
 *  Description          :	passenger reminder enhanced mode of functionality
 *  Parameters           :  void	
 *  Return               :	void
 *  Critical/explanation :    
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
 *  Name                 :	PR_StateMachineEu
 *  Description          :	passenger reminder european mode of functionality
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
 void PR_StateMachineEu(void)
 {
	switch(rub_PSStateEu)
	{
		case EURO_1:
			TM_TelltaleMsgPassEu(0);
			if(rub_EngineStatus ==  1)
			{
				rub_PSStateEu = EURO_2;
			}
		break;
		
		case EURO_2:
			TM_TelltaleMsgPassEu(1);
			if(rub_Speed > 22 || rub_Distance > 250)
			{
				rub_PSStateEu = EURO_3;
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

 