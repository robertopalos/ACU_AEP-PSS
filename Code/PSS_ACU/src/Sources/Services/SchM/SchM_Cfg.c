/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:         %SchM_Cfg.c%
* Instance:         1
* %version:         1 %
* %created_by:      Alexis Garcia %
* %date_created:    13/07/2015%
*=============================================================================*/
/* DESCRIPTION : 					                                          */
/*============================================================================*/
/* FUNCTION COMMENT : 														  */
/* 								                                              */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 13/07/2015  |                               |Alexis Garcia     */
/* 								                                              */
/*----------------------------------------------------------------------------*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  2.0      | 17/07/2015  | Correction of naming convention |Alexis Garcia   */
/*----------------------------------------------------------------------------*/
/*  REVISION |   DATE      |                                 |    AUTHOR      */
/*  2.1      | 01/10/2015  |								 |Roberto Palos   */
/*	Update table task config with the new names (1second max task.			  */
/*============================================================================*/
/* Includes */
/* -------- */
#include "SchM_Cfg.h"
#include "SchM_Tasks.h"




/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */
const S_SchTaskTableType cas_SchTaskTableConfig [] =
{
	/*Offset, Mask, TaskID, Function Pointer*/
	{0,	MASK_31P25MS,	TASK_31P25MS,	&Sch_Task31P25MS},
	{1,	MASK_62P5MS,	TASK_62P5MS,	&Sch_Task62P5MS},
	{2,	MASK_125MS,		TASK_125MS,		&Sch_Task125MS},
	{3,	MASK_250MS,		TASK_250MS,		&Sch_Task250MS},
	{5,	MASK_500MS,		TASK_500MS,		&Sch_Task500MS},
	{6,	MASK_1S,		TASK_1S,		&Sch_Task1S}
};

const S_SchConfigType cs_SchConfig = 
{
	(sizeof(cas_SchTaskTableConfig)/sizeof(cas_SchTaskTableConfig[0])),
	cas_SchTaskTableConfig	
};


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