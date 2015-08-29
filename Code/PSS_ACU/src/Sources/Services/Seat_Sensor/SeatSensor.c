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
#include "SeatSensor.h"

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
static T_UBYTE rub_Occupied = 0;
static T_UBYTE rub_Unoccupied = 0;
static T_UBYTE rub_Undetermined = 0;


/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */
static E_SeatStatusType re_SeatStatus = UNOCCUPIED;

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

void STS_StateMachine(void)
{
	
	switch(re_SeatStatus)
	{
		
		case UNOCCUPIED:
			if(rub_Occupied >= VALID_OCCUPIED)
			{
				SBS_ResetCounters();
				re_SeatStatus = OCCUPIED;
			}
			else if(rub_Undetermined >= VALID_UNDETERMINED)
			{
				SBS_ResetCounters();
				re_SeatStatus = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case OCCUPIED:
			if(rub_Unoccupied >= VALID_UNOCCUPIED)
			{
				SBS_ResetCounters();
				re_SeatStatus = UNOCUPPIED;
			}
			else if(rub_Undetermined >= VALID_UNDETERMINED)
			{
				SBS_ResetCounters();
				re_SeatStatus = UNDERTERMINED;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNDETERMINED:
			if(rub_Occupied >= VALID_OCCUPIED)
			{
				SBS_ResetCounters();
				re_SeatStatus = OCCUPIED;
			}
			else if(rub_Unoccupied >= VALID_UNOCCUPIED)
			{
				SBS_ResetCounters();
				re_SeatStatus = UNOCUPPIED;
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
 
 void SBS_ResetCounters(void)
 {
 	rub_Occupied = 0;
	rub_Unoccupied = 0;
	rub_Undetermined = 0;
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
void STS_ReadVoltLevel(void)
{
	T_UBYTE lub_VoltValue;	
	
	/*This is where the function gets voltage from ADC and converts into a integer number*/
	
	
	if((lub_VoltValue >= 12) && (lub_VoltValue <= 20) )
	{
		rub_Unoccupied++;  
	}
	else if((lub_VoltValue >= 2) && (lub_VoltValue <= 10) )
	{
		rub_Occupied++;
	}
	else if((lub_VoltValue > 10) && (lub_VoltValue < 12) )
	{
		rub_Undetermined++;
	}
	else
	{
		/*do nothing*/	
	}
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
 T_UBYTE STS_GetSeatStatus(void)
 {
 	return (T_UBYTE) re_SeatStatus;
 }
 