/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SeatSensor.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    29 de agosto de 2015 %
*=============================================================================*/
/* DESCRIPTION :                                     */
/*============================================================================*/
/* FUNCTION COMMENT :  */
/* */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 29/08/2015  |                               | Alexis Garcia    */
/* Creation of the module                                             		  */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SeatbeltSensor.h"

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
static T_UBYTE rub_UnbuckledPass = 0;
static T_UBYTE rub_BuckledPass = 0;
static T_UBYTE rub_UndeterminedPass = 0;

static T_UBYTE rub_UnbuckledDriver = 0;
static T_UBYTE rub_BuckledDriver = 0;
static T_UBYTE rub_UndeterminedDriver = 0;


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
static E_SeatbeltStatusType re_SeatbeltStatusPass = UNBUCKLED;
static E_SeatbeltStatusType re_SeatbeltStatusDriver = UNBUCKLED;

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

void STS_StateMachineDriver(void)
{
	
	switch(re_SeatbeltStatusDriver)
	{
		
		case UNBUCKLED:
			if(rub_BuckledDriver == VALID_BUCKLED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = BUCKLED;
			}
			else if(rub_UndeterminedDriver == VALID_UNDETERMINED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case BUCKLED:
			if(rub_UnbuckledDriver == VALID_UNBUCKLED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = UNBUCKLED;
			}
			else if(rub_UndeterminedDriver == VALID_UNDETERMINED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNDETERMINED:
			if(rub_BuckledDriver == VALID_BUCKLED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = BUCKLED;
			}
			else if(rub_UnbuckledDriver == VALID_UNBUCKLED)
			{
				SBS_ResetCounterDriver();
				re_SeatbeltStatusDriver = UNBUCKLED;
			}
			else{ /*do nothing*/ }
		break;
		
		default:
			/*error message */
		break;
	
	}
}

/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

void STS_StateMachinePass(void)
{
	
	switch(re_SeatbeltStatusPass)
	{
		
		case UNBUCKLED:
			if(rub_BuckledPass >= VALID_BUCKLED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = BUCKLED;
			}
			else if(rub_UndeterminedPass >= VALID_UNDETERMINED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case BUCKLED:
			if(rub_UnbuckledPass >= VALID_UNBUCKLED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = UNBUCKLED;
			}
			else if(rub_UndeterminedPass >= VALID_UNDETERMINED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNDETERMINED:
			if(rub_BuckledPass >= VALID_BUCKLED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = BUCKLED;
			}
			else if(rub_UnbuckledPass >= VALID_UNBUCKLED)
			{
				SBS_ResetCounterPass();
				re_SeatbeltStatusPass = UNBUCKLED;
			}
			else{ /*do nothing*/ }
		break;
		
		default:
			/*error message */
		break;
	
	}
}



/**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
 void SBS_ResetCounterDriver(void)
 {
 	rub_BuckledDriver = 0;
	rub_UnbuckledDriver = 0;
	rub_UndeterminedDriver = 0;
 }
 
 /**************************************************************
 *  Name                 : private_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 void SBS_ResetCountersPass(void)
 {
 	rub_BuckledDriver = 0;
	rub_UnbuckledDriver = 0;
	rub_UndeterminedDriver = 0;
 }



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void STS_ReadVoltLevelDriver(void)
{
	T_UBYTE lub_VoltValue;	
	
	/*This is where the function gets voltage from ADC and converts into a integer number*/
	
	
	if((lub_VoltValue >= 12) && (lub_VoltValue <= 20) )
	{
		rub_UnbuckledDriver++;  
	}
	else if((lub_VoltValue >= 2) && (lub_VoltValue <= 10) )
	{
		rub_BuckledDriver++;
	}
	else if((lub_VoltValue > 10) && (lub_VoltValue < 12) )
	{
		rub_UndeterminedDriver++;
	}
	else
	{
		/*do nothing*/	
	}
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void STS_ReadVoltLevelPass(void)
{
	T_UBYTE lub_VoltValue;	
	
	/*This is where the function gets voltage from ADC and converts into a integer number*/
	
	
	if((lub_VoltValue >= 12) && (lub_VoltValue <= 20) )
	{
		rub_UnbuckledPass++;  
	}
	else if((lub_VoltValue >= 2) && (lub_VoltValue <= 10) )
	{
		rub_BuckledPass++;
	}
	else if((lub_VoltValue > 10) && (lub_VoltValue < 12) )
	{
		rub_UndeterminedPass++;
	}
	else
	{
		/*do nothing*/	
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
 T_UBYTE STS_GetSeatbeltStatusDriver(void)
 {
 	return (T_UBYTE) re_SeatbeltStatusDriver;
 }
 
 
 /**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 T_UBYTE SBS_GetSeatbeltStatusPass(void)
 {
 	return (T_UBYTE) re_SeatbeltStatusPass;
 }
 
 