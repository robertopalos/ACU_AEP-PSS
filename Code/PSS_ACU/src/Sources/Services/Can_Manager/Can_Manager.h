/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %Can_Manager.h%
* Instance:         PSS_ACU%
* %version:         1.2%
* %created_by:       %
* %date_created:     %
*=============================================================================*/
/* DESCRIPTION : CanManaer header.                                            */
/*============================================================================*/
/* FUNCTION COMMENT : Can Manager header with function prototypes to be       */
/*  exported to the ACU                                                       */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 16/08/2015 |                              | Francisco Martinez */
/* Provide Can Services.                                                      */
/*----------------------------------------------------------------------------*/
/*  1.2      | 16/08/2015 |                              |   Roberto Palos    */
/* Removed old prototypes and update with the used in sources.                */
/* Added variable to be exported to modify and then send in Can Messages.     */
/*============================================================================*/
/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.h
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
#ifndef __CAN_MANAGER
#define __CAN_MANAGER
/*~A*/
/*~+:Imports*/
#include "Can.h"
/*~E*/
/*~A*/

extern uint8_t SeatBeltIndicator[7];
extern uint8_t ChimeRequest[6];
/*~+:Exported Interfaces*/
extern void Can_Manager_Eng_RPM(CAN_MessageDataType CanMessage);
extern void Can_Manager_Veh_Speed(CAN_MessageDataType CanMessage);
extern void Can_Manager_Odometer(CAN_MessageDataType CanMessage);
extern void Can_Manager_Indication(CAN_MessageDataType CanMessage);

extern void Can_Manager_Send_SeatbeltIndicator(void);
extern void Can_Manager_Send_Chime_Request(void);


/*~E*/
#endif /* __CAN_MANAGER */
