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
#include "Can_Manager.h"

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
 
/*Sound_Tone	Sound_Cadence_Period	Repetitions	Duty Cycle	SoundLocation_Driver	SoundLocation_Passenger*/
void CM_ChimeMsgDriver(T_UBYTE lub_Tone, T_UBYTE lub_Cadence_Period, T_UBYTE lub_Repetitions, T_UBYTE lub_Duty_Cycle){
	ChimeRequest[0] = lub_Tone;	//Sound_Tone
	ChimeRequest[1] = lub_Cadence_Period;	//Sound_Cadence_Period
	ChimeRequest[2] = lub_Repetitions;	//Repetitions
	ChimeRequest[3] = lub_Duty_Cycle;	//Duty Cycle
	ChimeRequest[4] = 0x01;	//SoundLocation_Driver
	Can_Manager_Send_Chime_Request();
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 /*Sound_Tone	Sound_Cadence_Period	Repetitions	Duty Cycle	SoundLocation_Driver	SoundLocation_Passenger*/

void CM_ChimeMsgPass(T_UBYTE lub_Tone, T_UBYTE lub_Cadence_Period, T_UBYTE lub_Repetitions, T_UBYTE lub_Duty_Cycle){
	ChimeRequest[0] = lub_Tone;	//Sound_Tone
	ChimeRequest[1] = lub_Cadence_Period;	//Sound_Cadence_Period
	ChimeRequest[2] = lub_Repetitions;	//Repetitions
	ChimeRequest[3] = lub_Duty_Cycle;	//Duty Cycle
	ChimeRequest[5] = 0x01;	//SoundLocation_Passenger
	Can_Manager_Send_Chime_Request();
}

/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
void CM_ChimeMsgOff(T_UBYTE Driver_Sound_Aux, T_UBYTE Passenger_Sound_Aux){
 	/*send message for chime off*/
	if(Driver_Sound_Aux == 1){
		ChimeRequest[4] = 0x00;	//SoundLocation_Driver
	}
	else{
	
	}
	if(Passenger_Sound_Aux == 1){
		ChimeRequest[5] = 0x00;	//SoundLocation_Driver
	}
	else{
	
	}
	Can_Manager_Send_Chime_Request();
}