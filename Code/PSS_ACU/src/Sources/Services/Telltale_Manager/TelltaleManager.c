/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %TelltaleManager.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15%
*=============================================================================*/
/* DESCRIPTION : C source for the telltale driver                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the C source template according to  */
/* the new software platform                                                  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15	   |                               | Alexis Garcia    */
/* Creation of the module , first version                                     */
/*============================================================================*/

/* Includes */
/* -------- */
#include "TelltaleManager.h"

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
	void TM_TelltaleMsgDriver (void)
	{
		if(rub_Time < TIME_EXPIRED)
		{
			/*send can message*/
		}
		else if(rub_Time < TIMEOUT)
		{
			/*send can message continous*/
		}
		else
		{
			/*no indication*/
		}
	}
	
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
	void TM_TelltaleMsgPass (void)
	{
		if(rub_Time < TIME_EXPIRED)
		{
			/*send can message*/
		}
		else if(rub_Time < TIMEOUT)
		{
			/*send can message continous*/
		}
		else
		{
			/*no indication*/
		}
	}
	
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
	void TM_AirbagPass (void)
	{
		if((SBS_GetSeatbeltStatusPass == BUCKLED) && (STS_GetSeatStatus == OCCUPIED))
		{
			/*send can message for ON*/
		}
		
		else
		{
			/*no indication*/
		}
	}
	
	
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
	void TM_TelltaleMsgDriverEu (T_UBYTE mode)
	{
		if(mode == 0)
		{
			if(rub_Time > TIME_EXPIRED_EU)
			{
				/*send continous*/
			}
			else
			{
				/*no indication*/
			}
		}
		else
		{
			if(rub_Time < TIMEOUT_EU)
			{
				/*send flashing*/
			}
			else
			{
				/*send continous*/
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
	void TM_TelltaleMsgPassEu (T_UBYTE mode)
	{
		if(mode == 0)
		{
			if(rub_Time > TIME_EXPIRED_EU)
			{
				/*send continous*/
			}
			else
			{
				/*no indication*/
			}
		}
		else
		{
			if(rub_Time < TIMEOUT_EU)
			{
				/*send flashing*/
			}
			else
			{
				/*send continous*/
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
 void TM_TelltaleMsgOff (void)
 {
 	/*send message for message off*/
 }