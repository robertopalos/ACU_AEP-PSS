/*~A*/
/*~+:Module Header*/
/*******************************************************************************/
/**
\file       Can_Manager.c
\brief      Provide Can Services
\author     Francisco Martinez
\version    1.0
\date       16/08/2015
*/
/*******************************************************************************/
/*~E*/
/*~A*/
/*~+:Import*/
#include "Can_Manager.h"
#include "GPIO.h"

/*~E*/
/*~A*/
/*~+:Defines*/

/*~E*/
/*~A*/
/*~+:Variables*/
struct CanTest
{
uint8_t     can_test_enable;
}CanTestStruct;
/* Temporary CAN Messages */
uint8_t dummy_msg0[8] = {0xCA,0x83,0x15,0x77,0x19,0x56,0x65,0x00};
uint8_t dummy_msg1[8] = {0x00,0x65,0x56,0x19,0x77,0x15,0x83,0xCA};
uint8_t dummy_msg2[8] = {0x33,0x44,0x55,0x66,0x88,0x89,0x45,0x4C};
CAN_PduType    pdu_handler4 = { 4, 8, dummy_msg0};
CAN_PduType    pdu_handler5 = { 5, 6, dummy_msg1};
CAN_PduType    pdu_handler6 = { 6, 2, dummy_msg2};
CAN_PduType    pdu_handler1 = { 7, 4, dummy_msg2};
uint32_t PduHandlerCnt0 = 0;
uint32_t PduHandlerCnt6 = 0;
/*~E*/
/*~A*/
/*~+:Private Operations*/

/*~E*/
/*~A*/
/*~+:Public Operations*/
/*~A*/
/*~+:Can Manager Callbacks*/
CAN_MessageDataType CanMessage_PduHandler0;
CAN_MessageDataType CanMessage_PduHandler6;
void Can_Manager_PduHandler0(CAN_MessageDataType CanMessage)
{
CanMessage_PduHandler0 = CanMessage;
LED_TOGGLE(LED1);

}

void Can_Manager_PduHandler6(CAN_MessageDataType CanMessage)
{
CanMessage_PduHandler6 = CanMessage;
LED_TOGGLE(LED2);
}
/*~E*/
/*~A*/
/*~+:Can Manager Periodic Functions*/
/*~A*/
/*~+:CanManager_SendMesage_12p5ms*/
void CanManager_SendMessage_12p5ms(void)
{
CAN_SendFrame(pdu_handler4);
CAN_SendFrame(pdu_handler5);
if (CanTestStruct.can_test_enable)
{
CanTestStruct.can_test_enable = 0;
}
}
/*~E*/
/*~A*/
/*~+:CanManager_SendMesage_25ms*/
void CanManager_SendMessage_25ms(void)
{
CAN_SendFrame(pdu_handler6);
}
/*~E*/
/*~E*/
/*~E*/
