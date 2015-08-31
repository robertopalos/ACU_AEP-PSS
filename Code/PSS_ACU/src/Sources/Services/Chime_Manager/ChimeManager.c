/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %ChimeManager.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15%
*=============================================================================*/
/* DESCRIPTION : C source for the chime manager                               */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
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
#include "ChimeManager.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */

T_UBYTE rub_Time = 0; 
/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */


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
void CM_ChimeMsgDriver (T_UBYTE lub_state)
{
	
	/*if(rub_PowerUpTimer > 8 && lub_state == 1)
	{
		rub_state = 2;
	}
	
	switch(rub_state)
	{
		case 1:
			if(rub_ChimeSend == 0)
			{
				
				rub_ChimeSend = 1;
			}
			if(ChimeTimer >=  6)
			{
				rub_state = 2;
			}	
		break;
		case 2;
			
		break;
	}*/
	
	
	if(rub_PowerUpTimer < 8 && lub_state != 1)
	{
			if(rub_ChimeSend == 0)
			{
				/*send chime msg*/
				rub_ChimeSend = 1;
			}
	}
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void CM_ChimeMsgPass (T_UBYTE lub_state)
{
	if(rub_PowerUpTimer > 8 && lub_state == 1)
	{
		rub_state = 2;
	}
	
	switch(rub_state)
	{
		case 1:
			if(rub_ChimeSend == 0)
			{
				/*send chime msg*/
				rub_ChimeSend = 1;
			}
			if(ChimeTimer >=  6)
			{
				rub_state = 2;
			}	
		break;
		case 2;
			/*no chime*/
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
 void CM_ChimeMsgOff (void)
 {
 	/*send message for chime off*/
 }