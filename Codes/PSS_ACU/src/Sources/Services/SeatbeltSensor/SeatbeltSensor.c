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
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/2015  |                               | Alexis Garcia    */
/* Modification of functionality                             Roberto Palos    */
/*============================================================================*/

/* Includes */
/* -------- */
#include "SeatbeltSensor.h"
#include "GPIO.h"
#include "ADC.h"

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
static E_SeatbeltStatusType re_SeatbeltStatusPass = FASTEN;
static E_SeatbeltStatusType re_SeatbeltStatusDriver = FASTEN;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
 void SBS_ResetCountersPass (void);
 void SBS_ResetCountersDriver (void);


/* Exported functions prototypes */
/* ----------------------------- */



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : SBS_ResetCountersDriver
 *  Description          :	resets to 0 the counters for the state determination of driver
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
 
 void SBS_ResetCountersDriver (void)
 {
 	rub_BuckledDriver = 0;
	rub_UnbuckledDriver = 0;
	rub_UndeterminedDriver = 0;
 }
 
 /**************************************************************
 *  Name                 : SBS_ResetCountersPass
 *  Description          :	resets to 0 the counters for the state determination of passenger
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
 void SBS_ResetCountersPass (void)
 {
 	rub_BuckledPass = 0;
	rub_UnbuckledPass = 0;
	rub_UndeterminedPass = 0;
 }



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 : SBS_StateMachineDriver
 *  Description          :	controls the state of the seatbelt of driver
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/

void SBS_StateMachineDriver(void)
{
	
	switch(re_SeatbeltStatusDriver)
	{
		
		case UNFASTEN:
			if(rub_BuckledDriver == VALID_BUCKLED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = FASTEN;
			}
			else if(rub_UndeterminedDriver == VALID_UNDETERMINED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = UNKNOWN;
			}
			else{ /*do nothing*/ }
		break;
		
		case FASTEN:
			if(rub_UnbuckledDriver == VALID_UNBUCKLED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = UNFASTEN;
			}
			else if(rub_UndeterminedDriver == VALID_UNDETERMINED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = UNKNOWN;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNKNOWN:
			if(rub_BuckledDriver == VALID_BUCKLED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = FASTEN;
			}
			else if(rub_UnbuckledDriver == VALID_UNBUCKLED)
			{
				SBS_ResetCountersDriver();
				re_SeatbeltStatusDriver = UNFASTEN;
			}
			else{ /*do nothing*/ }
		break;
		
		default:
			re_SeatbeltStatusDriver = UNKNOWN;
		break;
	
	}
}

/**************************************************************
 *  Name                 : SBS_StateMachinePass
 *  Description          :	controls the state of the seatbelt of passenger
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/

void SBS_StateMachinePass(void)
{
	
	switch(re_SeatbeltStatusPass)
	{
		
		case UNFASTEN:
			if(rub_BuckledPass >= VALID_BUCKLED)
			{
				SBS_ResetCountersPass();
				re_SeatbeltStatusPass = FASTEN;
			}
			else if(rub_UndeterminedPass >= VALID_UNDETERMINED)
			{
				SBS_ResetCountersPass();
				re_SeatbeltStatusPass = UNKNOWN;
			}
			else{ /*do nothing*/ }
		break;
		
		case FASTEN:
			if(rub_UnbuckledPass >= VALID_UNBUCKLED)
			{
				SBS_ResetCountersPass();
				re_SeatbeltStatusPass = UNFASTEN;
			}
			else if(rub_UndeterminedPass >= VALID_UNDETERMINED)
			{
				SBS_ResetCountersPass();
				re_SeatbeltStatusPass = UNKNOWN;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNKNOWN:
			SBS_ResetCountersPass();
			re_SeatbeltStatusPass = FASTEN;
		break;
		default:
			re_SeatbeltStatusPass = FASTEN;
		break;
	
	}
}

/**************************************************************
 *  Name                 :	SBS_ReadVoltLevelDriver
 *  Description          :	reads the adc to change the states of driver sm
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
void SBS_ReadVoltLevelDriver(void)
{
	T_ULONG lub_VoltValue = 0;	
	lub_VoltValue = ADC_ReadPad(0) * 4;
	if((lub_VoltValue >= 12000) && (lub_VoltValue <= 20000) )
	{
		rub_UnbuckledDriver++;
		rub_BuckledDriver = 0;
		rub_UndeterminedDriver = 0;  
	}
	else if((lub_VoltValue >= 2000) && (lub_VoltValue <= 10000) )
	{
		rub_BuckledDriver++;
		rub_UnbuckledDriver = 0;
		rub_UndeterminedDriver = 0;
	}
	else if((lub_VoltValue > 10000) && (lub_VoltValue < 12000) )
	{
		rub_UndeterminedDriver++;
		rub_BuckledDriver = 0;
		rub_UnbuckledDriver = 0;
	}
	else if((lub_VoltValue >= 0) && (lub_VoltValue < 2000) )
	{
		rub_UndeterminedDriver++;
		rub_BuckledDriver = 0;
		rub_UnbuckledDriver = 0;
	}
	else
	{/*do nothing*/}
}

/**************************************************************
 *  Name                 :	SBS_ReadVoltLevelPass
 *  Description          :	reads the adc to change the states of passenger sm
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
void SBS_ReadVoltLevelPass(void)
{
	T_ULONG lub_VoltValuePass;	
	lub_VoltValuePass = ADC_ReadPad(1) * 4;
	if((lub_VoltValuePass >= 12000) && (lub_VoltValuePass <= 20000) )
	{
		rub_UnbuckledPass++;  
		rub_BuckledPass = 0;
		rub_UndeterminedPass = 0;
	}
	else if((lub_VoltValuePass >= 2000) && (lub_VoltValuePass <= 10000) )
	{
		rub_BuckledPass++;
		rub_UnbuckledPass = 0;
		rub_UndeterminedPass = 0;
	}
	else if((lub_VoltValuePass > 10000) && (lub_VoltValuePass < 12000) )
	{
		rub_UndeterminedPass++;
		rub_BuckledPass = 0;
		rub_UnbuckledPass = 0;
	}
	else if((lub_VoltValuePass >= 0) && (lub_VoltValuePass < 2000) )
	{
		rub_UndeterminedPass++;
		rub_BuckledPass = 0;
		rub_UnbuckledPass = 0;	
	}
	else
	{/*do nothing*/}
}

/* ------------------ */
/**************************************************************
 *  Name                 :	SBS_GetSeatbeltStatusDriver
 *  Description          :	retunrs the actul state of the seatbelt SM for driver
 *  Parameters           : 	void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
 T_UBYTE SBS_GetSeatbeltStatusDriver(void)
 {
 	return  re_SeatbeltStatusDriver;
 }
 
 
/**************************************************************
 *  Name                 :	SBS_GetSeatbeltStatusPass
 *  Description          :	retunrs the actul state of the seatbelt SM for passenger
 *  Parameters           : 	void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
 T_UBYTE SBS_GetSeatbeltStatusPass(void)
 {
 	return re_SeatbeltStatusPass;
 }
 
 