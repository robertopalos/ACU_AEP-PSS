/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Can_Manager.c%
* Instance:         RPL_1
* %version:         2 %
* %created_by:      uid02495 %
* %date_created:    Sun Aug  16 2015 %
*=============================================================================*/
/* DESCRIPTION : Provide Can Services.                                       */
/*============================================================================*/
/* FUNCTION COMMENT : Can Driver Adapted to AEP Final Practice.               */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 16/08/2015  |                               |Francisco Martinez*/
/* Can Driver provider by Francisco Martinez                                  */
/*----------------------------------------------------------------------------*/
/*  1.1      | 08/09/2015  |                               |  Roberto Palos   */
/*	Adapted CAN IDs, CAN function to response and Pdu_Handlers to read datas. */
/*============================================================================*/

/* Includes */
/* -------- */
#include "Can_Manager.h"
#include "GPIO.h" 
#include "DriverReminder.h"
#include "PassengerReminder.h"
/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 

/* LONG and STRUCTURE RAM variables */
struct CanTest{
	uint8_t     can_test_enable;
}CanTestStruct;

/* Temporary CAN Messages */
uint8_t SeatBeltIndicator[7] = {10, 20, 30, 40 ,60, 70, 50};
uint8_t ChimeRequest[6];

CAN_PduType	 pdu_handlerSeatbelt = { 4, 7, SeatBeltIndicator};
CAN_PduType	pdu_handlerChime = { 5, 6, ChimeRequest};


/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_Eng_RPM;
CAN_MessageDataType CanMessage_Veh_Speed;
CAN_MessageDataType CanMessage_Odometer;
CAN_MessageDataType CanMessage_Indication;

/* Exported functions */
/* ------------------ */

/*Can Receive*/


/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
/*Message	Transmitter	Receiver	ID		DLC	B0		B1		B2						SendType	Cycle
Eng_RPM		ECM			ACU			0x100	2	RPM_MSB	RPM_LSB	Engine_Active_Status	Periodic	10 ms*/
void Can_Manager_Eng_RPM(CAN_MessageDataType CanMessage){
	CanMessage_Eng_RPM = CanMessage;
	rub_EngineStatus = CanMessage_Eng_RPM.msg_data_field[2];
}
/**************************************************************
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/
/*Message	Transmitter	Receiver	ID		DLC	B0			B1			SendType	Cycle
Veh_Speed	SIM/AVT		ID/ACU		0x201	2	ACTENG_MSB	ACTENG_LSB	Periodic	50 ms*/
void Can_Manager_Veh_Speed(CAN_MessageDataType CanMessage){
	CanMessage_Veh_Speed = CanMessage;
	rub_Speed = 0;
	rub_Speed =CanMessage_Veh_Speed.msg_data_field[0];
	rub_Speed = rub_Speed << 8;
	rub_Speed =(T_UWORD) (rub_Speed + CanMessage_Veh_Speed.msg_data_field[1]);
	DR_StateMachineEn();
}

/*Message	Transmitter	Receiver	ID		DLC	B0				B1				SendType	Cycle
Odometer	SIM/AVT		ID/ACU		0x202	2	Increase_ACK	Odometer_Value	Periodic	100 ms*/
void Can_Manager_Odometer(CAN_MessageDataType CanMessage){
	CanMessage_Odometer = CanMessage;
	rub_Distance = CanMessage_Odometer.msg_data_field[1];
}

/*Odometer register the traveled distance*/


/*Message	Transmitter	Receiver	ID		DLC	B0			B1					B2				SendType	Cycle
			BCM			ID/ACU		0x204	5	Door_Status	High_Beams_Status	Brake_Status	Periodic	100 ms*/
void Can_Manager_Indication(CAN_MessageDataType CanMessage){
	CanMessage_Indication = CanMessage;
	rub_DoorStatus = CanMessage_Indication.msg_data_field[0];
}


/* CAN Send*/

/*Message	Transmitter	Receiver	ID		DLC	B0					B1				B2					B3						B4					B5						B6								SendType	Cycle
			ACU			ID			0x601	7	Driver_Indication	Driver_Ind_Duty	Driver_Ind_Period	Passenger_Indication	Passenger_Ind_Duty	Passenger_Ind_Period	Driver_Auxiliary_Request		Periodic	200ms
												0 / 1				Duty Cycle		Period				0 / 1					Duty Cycle			Period					*/

void Can_Manager_Send_SeatbeltIndicator(void){
	CAN_SendFrame(pdu_handlerSeatbelt);
}

void Can_Manager_Send_Chime_Request(void){
	CAN_SendFrame(pdu_handlerChime);
}


