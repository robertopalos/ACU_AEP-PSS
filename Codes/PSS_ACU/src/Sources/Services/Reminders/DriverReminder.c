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
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/2015  |                               | Alexis Garcia    */
/* Modification of functionality                             Roberto Palos    */
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
T_UWORD rub_Speed = 0;
T_UBYTE rub_EngineStatus = 0;
T_UWORD rub_Distance = 0;
T_UBYTE rub_DoorStatus = 0;
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
/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	DR_BasicRem
 *  Description          :	driver reminder basic mode of functionality
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/
 
 void DR_BasicRem (void){
 	CM_ChimeMsgDriver(0x20, 0x10,0x05);
	TM_TelltaleMsgDriver(0x20, 0x24, 0x10);
 }


/**************************************************************
 *  Name                 :	DR_StateMachineEn
 *  Description          :	driver reminder  enhanced moed of functionality
 *  Parameters           :	void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/


void DR_StateMachineEn(void)
{
	switch(rub_DRStateEn)
	{
		case ENHANCED_1D:
		//	CM_ChimeMsgDriver();
		//	TM_TelltaleMsgDriver();
			if(rub_TimerD > 85 && rub_Speed > 22)
			{
				rub_DRStateEn = ENHANCED_2D;
			}
		break;
		
		case ENHANCED_2D:
		//	CM_ChimeMsgDriver();
		//	TM_TelltaleMsgDriver();
			if(rub_TimerD > 235 && rub_Speed > 22)
			{
				rub_DRStateEn = ENHANCED_3D;
			}
		break;
		
		case ENHANCED_3D:
		//	CM_ChimeMsgDriver();
		//	TM_TelltaleMsgDriver();
		break;
		
		default:
			/* Error Message */
		break;
	}	
}


/**************************************************************
 *  Name                 :	DR_StateMachineEu
 *  Description          :	driver reminder europen mode of functionality
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/
 void DR_StateMachineEu(void)
 {
	switch(rub_DRStateEu)
	{
		case EURO_1D:
			TM_TelltaleMsgDriverEu(0);
			if(rub_EngineStatus ==  1)
			{
				rub_DRStateEu = EURO_2D;
			}
		break;
		
		case EURO_2D:
			TM_TelltaleMsgDriverEu(1);
			if(rub_Speed > 22 || rub_Distance > 250)
			{
				rub_DRStateEu = EURO_3D;
			}
		break;
		
		case EURO_3D:
			CM_ChimeMsgDriverEu(1);
			TM_TelltaleMsgDriverEu();
		break;
		
		default:
			/* Error Message */
		break;
	}	
 }

 