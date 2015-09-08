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
/*----------------------------------------------------------------------------*/
/*  2.0      | 08/09/15	   |                               | Alexis Garcia    */
/* Major update to file, this one include new functions and removed old       */
/* functions.																  */

/*============================================================================*/

/* Includes */
/* -------- */
#include "TelltaleManager.h"
#include "typedefs.h"
#include "Can_Manager.h"

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
 *  Name                 :	TM_TelltaleMsgDriver
 *  Description          :	fills the CAN message for the telltale indicator driver
 *  Parameters           :  T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
 
 /*
 Driver_Indication			[0]		//
 Driver_Ind_Duty			[1]
 Driver_Ind_Period			[2]
 Passenger_Indication		[3]
 Passenger_Ind_Duty			[4]
 Passenger_Ind_Period		[5]
 Driver_Auxiliary_Request	[6]
 */

void TM_TelltaleMsgDriver(T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period){
	SeatBeltIndicator[0] = lub_Indication;	//Driver_Indication
	SeatBeltIndicator[1] = lub_Duty;		//Driver_Ind_Duty
	SeatBeltIndicator[2] = lub_Period;		// Driver_Ind_Period in seconds
	Can_Manager_Send_SeatbeltIndicator();
}
	
/**************************************************************
 *  Name                 :	TM_TelltaleMsgPass
 *  Description          :	fills the CAN message for the telltale indicator passenger
 *  Parameters           :  T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
void TM_TelltaleMsgPass(T_UBYTE lub_Indication, T_UBYTE lub_Duty, T_UBYTE lub_Period){
	SeatBeltIndicator[3] = lub_Indication;	//Passenger_Indication
	SeatBeltIndicator[4] = lub_Duty;		//Passenger_Ind_Duty
	SeatBeltIndicator[5] = lub_Period;		//Passenger_Ind_Period
	Can_Manager_Send_SeatbeltIndicator();
}
	
/* ------------------ */
/**************************************************************
 *  Name                 :	TM_AirbagPass
 *  Description          :	not applicable	
 *  Parameters           :  not applicable
 *  Return               :	not applicable
 *  Critical/explanation :  not applicable
 **************************************************************/
void TM_AirbagPass(void){
	
}
	
	
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void TM_TelltaleMsgDriverEu(void){
		
}
	
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
void TM_TelltaleMsgPassEu(void){
	
}
	
	
/**************************************************************
 *  Name                 :	TM_TelltaleMsgOff
 *  Description          :	sends Can message for turning down the telltale indicator
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
void TM_TelltaleMsgOff (void){
	
}