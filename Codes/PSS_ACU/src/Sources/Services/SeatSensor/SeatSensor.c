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
static E_SeatStatusType re_SeatStatus = NO_OCUPANCY;

/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
void STS_ResetCounters();


/* Exported functions prototypes */
/* ----------------------------- */



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : STS_ResetCounters
 *  Description          :	reset the counters of the state of the seat
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/
 
void STS_ResetCounters(){
	rub_Occupied = 0;
	rub_Unoccupied = 0;
	rub_Undetermined = 0;
}



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 : STS_StateMachine
 *  Description          :	state machine for the seat sensor control
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/

void STS_StateMachine(void){
	switch(re_SeatStatus){
		case NO_OCUPANCY:
			if(rub_Occupied >= VALID_SIGNAL_OC){
				STS_ResetCounters();
				re_SeatStatus = OCUPANCY;
			}
			else if(rub_Undetermined >= VALID_SIGNAL_UNK){
				STS_ResetCounters();
				re_SeatStatus = UNKNOWN2;
			}
			else{ /*do nothing*/ }
		break;
		
		case OCUPANCY:
			if(rub_Unoccupied >= VALID_SIGNAL_UNOC){
				STS_ResetCounters();
				re_SeatStatus = NO_OCUPANCY;
			}
			else if(rub_Undetermined >= VALID_SIGNAL_UNK){
				STS_ResetCounters();
				re_SeatStatus = UNKNOWN2;
			}
			else{ /*do nothing*/ }
		break;
		
		case UNKNOWN2:
			if(rub_Occupied >= VALID_SIGNAL_OC){
				STS_ResetCounters();
				re_SeatStatus = OCUPANCY;
			}
			else if(rub_Unoccupied >= VALID_SIGNAL_UNOC){
				STS_ResetCounters();
				re_SeatStatus = NO_OCUPANCY;
			}
			else{ /*do nothing*/ }
		break;
		
		default:
			re_SeatStatus = UNKNOWN2;
		break;
	
	}
}

/**************************************************************
 *  Name                 :	STS_ReadVoltLevel
 *  Description          :	read the volt of adc to detemine the counters for the SM 
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/
void STS_ReadVoltLevel(void){
	T_ULONG lub_SeatVoltValue;	
	
	/*This is where the function gets voltage from ADC and converts into a integer number*/
	
	lub_SeatVoltValue = (T_ULONG) ADC_ReadPad(2) * 4;
	if((lub_SeatVoltValue >= 12000) && (lub_SeatVoltValue <= 20000) ){
		rub_Unoccupied++;  
		rub_Occupied = 0;
		rub_Undetermined = 0;
	}
	else if((lub_SeatVoltValue >= 2000) && (lub_SeatVoltValue <= 10000) ){
		rub_Occupied++;
		rub_Unoccupied = 0;
		rub_Undetermined = 0;
	}
	else if((lub_SeatVoltValue > 10000) && (lub_SeatVoltValue < 12000) ){
		rub_Undetermined++;
		rub_Occupied = 0;
		rub_Unoccupied = 0;
	}
	else if((lub_SeatVoltValue >= 0) && (lub_SeatVoltValue < 2000) ){
		rub_Undetermined++;
		rub_Occupied = 0;
		rub_Unoccupied = 0;	
	}
	else
	{/*do nothing*/	}
}


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	STS_GetSeatStatus
 *  Description          :	retunrns the actual state of the machine for other modules
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :    
 **************************************************************/
T_UBYTE STS_GetSeatStatus(void){
 	return re_SeatStatus;
}
 