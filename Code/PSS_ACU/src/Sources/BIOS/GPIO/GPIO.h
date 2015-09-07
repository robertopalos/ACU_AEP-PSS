/*============================================================================*/
/*                        SV C BC SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Include:        %GPIO.h%
* Instance:         PSS_ACU
* %version:         .3 %
* %created_by:      %
* %date_created:    %
*=============================================================================*/
/* DESCRIPTION : Header file template                                         */
/*============================================================================*/
/* FUNCTION COMMENT : contains only symbols which are exported to internal    */
/* platform modules. This will not be delivered with the library              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  0.1      | 09/05/2013  |                               | Abraham Tezmol   */
/* Macro definitions for registers access and I/O handling                    */
/*----------------------------------------------------------------------------*/
/*  0.2      | 07/09/2015  |                               | Roberto Palos    */
/* Template for header files.                                                 */
/*============================================================================*/


#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"

/*-- Variables ---------------------------------------------------------------*/

/*-- Types Definitions -------------------------------------------------------*/

/*-- Defines -----------------------------------------------------------------*/

#define LED1      					68
#define LED2       					69
#define LED3       					70
#define LED4        				71

#define GPIO_INPUT					0
#define GPIO_OUTPUT					1

#define GPIO_OPEN_DRAIN_DISABLE		0
#define GPIO_OPEN_DRAIN_ENABLE		1


#define INPUT_ON					0
#define INPUT_OFF					1


#define PUSH1						64
#define PUSH2						65
#define PUSH3						66
#define PUSH4						67


/*-- Macros ------------------------------------------------------------------*/
/* Indicator LEDs handling */

/** Set LED */ 
#define LED_ON(channel)                     (SIU.GPDO[channel].B.PDO =  0)
/** Clear LED */ 
#define LED_OFF(channel)                    (SIU.GPDO[channel].B.PDO =  1)
/** Toggle LED */ 
#define LED_TOGGLE(channel)                 (SIU.GPDO[channel].B.PDO ^= 1) 
/*Read Input value*/
#define INPUT(channel)						SIU.GPDI[channel].B.PDI


/*-- Function Prototypes -----------------------------------------------------*/

extern void vfnGPIO_Init_channel(uint8_t channel, uint8_t input_output, uint8_t Open_drain);
extern void vfnGPIO_Output(uint8_t channel, uint8_t logical_value);
extern void vfnGPIO_LED_Init(void);


#endif /* _GPIO_H */

/*******************************************************************************/
