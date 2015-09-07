/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %ADC.c%
* Instance:         ADC
* %version:         1 %
* %created_by:      uid734106 %
* %date_created:    Mon Sep  7 12:34 2015 %
*=============================================================================*/
/* DESCRIPTION : ADC Driver.			                                      */
/*============================================================================*/
/* FUNCTION COMMENT :	This file contains the function to read the ADC		  */
/*						channel 											  */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 07/09/2015  |                               | Roberto Palos    */
/* Partial creation and test function of the ADC function.					  */
/*============================================================================*/

/* Includes */
/* -------- */
#include	"MPC5606B.h"
#include	"ADC.h"
#include	"typedefs.h"

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
 *  Name                 :	export_func
 *  Description          :
 *  Parameters           :  [Input, Output, Input / output]
 *  Return               :
 *  Critical/explanation :    [yes / No]
 **************************************************************/

T_ULONG ADC_ReadPad(T_UBYTE ADC_ANS){
	while(ADC_0.CDR[32 + ADC_ANS].B.VALID != 1) {};					/* Wait for last scan to complete */
	return (uint16_t)(5000*ADC_0.CDR[32 + ADC_ANS].B.CDATA/0x3FF);	/* Converted result in mv */
  }