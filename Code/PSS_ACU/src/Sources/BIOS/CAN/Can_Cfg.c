/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %Can_Cfg.c%
* Instance:         CAN_1
* %version:         1.1 %
* %created_by:      Alicia Alvarez %
* %date_created:     %
*=============================================================================*/
/* DESCRIPTION : Can configuration file.                                      */
/*============================================================================*/
/* FUNCTION COMMENT : Can baudrate and messages configuration.				  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | xx/xx/xx    |                               | Alicia Alvarez   */
/* Creation of file.			                                              */
/*----------------------------------------------------------------------------*/
/*  1.1      | 07/09/2015  |                               | Roberto Palos    */
/* Changed documentation format for the templates used in our projects.       */
/*        */
/*============================================================================*/
/* Includes */
/* -------- */

#include "Can_Cfg.h"
#include "Can_Manager.h"
/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */
#define MAX_NUM_RX_FILTERS  (4)
#define MAX_NUM_TX_FILTERS  (2)
/* Exported functions prototypes */
/* ----------------------------- */
extern uint8_t CAN_SendFrameInt(uint8_t can_eng, uint8_t can_channel, uint8_t *can_msg_buf, uint8_t len);
/*~+:CAN Baudrate Configuration*/
CAN_DevBaudrateType bios_cnf_can_baudrate_options[] = {
/***********************************************************************************/
/* Propagation Segment------------------------------+                              */
/* Phase Segment 2-------------------------------+  |                              */
/* Phase Segment 1----------------------------+  |  |                              */
/* Resync Jump Width-----------------------+  |  |  |                              */
/* Baudrate Prescaler------------------+   |  |  |  |                              */
/* Clock Source ------------+          |   |  |  |  |                              */
/*                          |          |   |  |  |  |                              */
                     {CNF_CAN_OSC_CLK, 1,  2, 2, 2, 3},     /* BR 1Mbps            */
                     {CNF_CAN_OSC_CLK, 2,  2, 2, 2, 3},     /* BR 500kbps          */
                     {CNF_CAN_OSC_CLK, 4,  2, 2, 2, 3},     /* BR 250kbps          */
                     {CNF_CAN_OSC_CLK, 8,  2, 2, 2, 3}      /* BR 125kbps          */
};



/*~E*/
/*~A*/
/*~+:CAN Messages Configuration*/
CAN_ConfigMsgType bios_cnf_can_messages[] = {
/*Eng_RPM	ECM	ACU	0x100	2	RPM_MSB	RPM_LSB	Engine_Active_Status*/
{0,	CNF_CAN_CH_RX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x100,	0x1FF,	Can_Manager_Eng_RPM},
/*Veh_Speed	SIM/AVT	ID/ACU	0x201	2	ACTENG_MSB	ACTENG_LSB*/
{1,	CNF_CAN_CH_RX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x201,	0x1FF,	Can_Manager_Veh_Speed},
/*Odometer	SIM/AVT	ID/ACU	0x202	2	Increase_ACK	Odometer_Value*/
{2,	CNF_CAN_CH_RX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x202,	0x1FF,	Can_Manager_Odometer},
/*Indication	BCM	ID/ACU	0x204	5	Door_Status	High_Beams_Status	Brake_Status*/
{3,	CNF_CAN_CH_RX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x204,	0x1FF,	Can_Manager_Indication},
/*SeatBeltIndicator	ACU	ID	0x601	7	Driver_Indication	Driver_Ind_Duty	Driver_Ind_Period	Passenger_Indication	Passenger_Ind_Duty	Passenger_Ind_Period	Driver_Auxiliary_Request*/
{4,	CNF_CAN_CH_TX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x601,	0x1FF,	NULL},
/*Chime_Request	ACU	ID	0x602	6	Sound_Tone	Sound_Cadence_Period	Repetitions	Duty Cycle	SoundLocation_Driver	SoundLocation_Passenger*/
{5,	CNF_CAN_CH_TX,	CNF_CAN_DATA_FRAME,	CNF_CAN_IDE_STD,	0x602,	0x1FF,	NULL}
};

/*~E*/
/*~A*/
/*~+:CAN Device Configuration*/
CAN_ConfigDeviceType bios_cnf_can_dev[] = {
	{CANB,                                           /* CAN Device */
	(sizeof(bios_cnf_can_messages)
	/sizeof(bios_cnf_can_messages[0]) ),			/* Number of channels */
	CNF_CAN_BOFF_DIS,                               /* Automatic Recovery OFF */
	CNF_CAN_LBUF_ON,                                /* Lower buffer is transmitted first */
	CNF_CAN_FIFO_DIS,                               /* FIFO Disabled */
	CNF_CAN_IND_MASK,                               /* Filter mode Individual Mask */
	/*0 1Mbps, 1 500kbps, 2 250kbps, 3 125kbps*/
	&bios_cnf_can_baudrate_options[1],              /* CAN Baud rate Configuration */
	bios_cnf_can_messages,                  /* Configured channels for this CAN Engine */
	}
};

/*~E*/
/*~A*/
/*~+:CAN Driver Configuration*/
CAN_ConfigType can_driver_config = {
	(sizeof(bios_cnf_can_dev)/sizeof(bios_cnf_can_dev[0]) ),   /* Number of devices */
	bios_cnf_can_dev                                            /* Pointer to devices configuration */
};

/*~E*/
/*~E*/