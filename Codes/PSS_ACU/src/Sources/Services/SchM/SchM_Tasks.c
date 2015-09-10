/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM_Tasks.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 									                                          */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               |Alexis Garcia     */
/* 									                                          */
/*----------------------------------------------------------------------------*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia   */
/* 								                                              */
/*----------------------------------------------------------------------------*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.1      | 27/07/2015  | Minor function name changes |Alexis Garcia       */
/* 								                                              */
/*----------------------------------------------------------------------------*/
/*  REVISION |   DATE      |                                 |    AUTHOR      */
/*  2.2      | 01/10/2015  |								 |Roberto Palos   */
/*	Update functions names.													  */
/*============================================================================*/
/* Includes */
/* -------- */
#include "euro_test.h"
#include "MPC5606B.h"
#include "ADC.h"
#include "SeatbeltSensor.h"
#include "ACU.h"
#include "GPIO.h"
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



/* Private functions */
/* ----------------- */



/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	task_3P125MS
 *  Description          :	call of the function every 3.125 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
void Sch_Task31P25MS(void){
}
 
 
 /**************************************************************
 *  Name                 :	task_6P25MS
 *  Description          :	call of the function every 6.25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
void Sch_Task62P5MS(void){
	SBS_ReadVoltLevelDriver();
	SBS_StateMachineDriver();
	STS_ReadVoltLevel();
	STS_StateMachine();
	SBS_ReadVoltLevelPass();
	SBS_StateMachinePass();
	
}
 
 
 /**************************************************************
 *  Name                 :	task_12P5MS
 *  Description          :	call of the function every 12.5 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
void Sch_Task125MS(void){
	
}
 
 
 /**************************************************************
 *  Name                 :	task_25MS
 *  Description          :	call of the function every 25 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
void Sch_Task250MS(void){
		ACU_StateMachineDriver();
		ACU_StateMachinePass();
}
 
 
 /**************************************************************
 *  Name                 :	task_50MS
 *  Description          :	call of the function every 50 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  [No]
 **************************************************************/
void Sch_Task500MS(void){

}
 
 
 /**************************************************************
 *  Name                 :	task_100MS
 *  Description          :	call of the function every 100 milliseconds
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation : 	[No]
 **************************************************************/
void Sch_Task1S(void){

}