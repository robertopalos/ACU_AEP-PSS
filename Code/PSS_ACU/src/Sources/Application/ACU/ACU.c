/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Alexis Garcia.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    31/08/15 %
*=============================================================================*/
/* DESCRIPTION : C source for the ACU unit                                    */
/*============================================================================*/
/* FUNCTION COMMENT : This file describes the main functionality of the ACU module*/
/* checks for seatbelts and occupancy and calls the reminders                 */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 31/08/15    |                               | Alexis Garcia    */
/* Creation of the module file, first version                                 */
/*============================================================================*/
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/15    |                               | Alexis Garcia    */
/* Addition of selector of mode funcionality                                 */
/*============================================================================*/

/* Includes */
/* -------- */
#include "ACU.h"
#include "GPIO.h"
#include "SeatbeltSensor.h"
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
static T_UBYTE rub_PassState = FASTENED;
static T_UBYTE rub_DriverState = FASTENED;

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

/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	ACU_StateMachineDriver
 *  Description          :	ACU state machine for driver
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :   
 **************************************************************/
void ACU_StateMachineDriver(void){
	T_UBYTE lub_ReadStatusDriver;
	lub_ReadStatusDriver = (T_UBYTE) SBS_GetSeatbeltStatusDriver();
	switch(rub_DriverState){
		case FASTENED:
			/*reset timer for telltale, and turn off chime and telltale*/
			if(lub_ReadStatusDriver == UNFASTEN || lub_ReadStatusDriver == UNKNOWN){
				rub_DriverState = UNFASTENED;
			}
			LED_ON(LED1);
		break;
		
		case UNFASTENED:
			/*call for the driver reminder corresponding*/
			if(lub_ReadStatusDriver == FASTEN){
				rub_DriverState = FASTENED;
			}
			else{
				switch(rub_ModeConfig){
					case Basic_Mode:
						DR_BasicRem();
					break;
					case Enhanced_Mode:
						
					break;
					case Euro_Mode:
					break;
					default:
					break;
				}
				
				LED_OFF(LED1);	
			}
		break;
		
		default:
			/*error message*/
		break;
	}
}

/**************************************************************
 *  Name                 :	ACU_StateMachinePass
 *  Description          :	ACU state machine for passenger
 *  Parameters           :  void
 *  Return               :	void
 *  Critical/explanation :  
 **************************************************************/
void ACU_StateMachinePass(void){
	T_UBYTE lub_ReadStatusPass;
	T_UBYTE lub_ReadStatusPassOcp;
	lub_ReadStatusPass = (T_UBYTE) SBS_GetSeatbeltStatusPass();
	lub_ReadStatusPassOcp =  (T_UBYTE) STS_GetSeatStatus();
	if(lub_ReadStatusPassOcp == OCUPANCY){
		LED_ON(LED3);
		switch(rub_PassState){
			case FASTENED:
				/*reset timer for telltale, and turn off chime and telltale*/
				//TM_TelltaleMsgOff();
				
				if(lub_ReadStatusPass == UNFASTEN || lub_ReadStatusPass == UNKNOWN){
					rub_PassState = UNFASTENED;
				}
				else{
					LED_ON(LED4);
				}
			break;
			
			case UNFASTENED:
				if(lub_ReadStatusPass == FASTEN || lub_ReadStatusPass == UNKNOWN){
					rub_PassState = FASTENED;
				}
				else{
					LED_OFF(LED4);
					/*call for the driver reminder corresponding*/	
				}
			break;
			
			default:
				/*error message*/
			break;
		}		
	}
	else{
		LED_OFF(LED4);
		LED_OFF(LED3);
		/*do nothing*/
	}
	
}

