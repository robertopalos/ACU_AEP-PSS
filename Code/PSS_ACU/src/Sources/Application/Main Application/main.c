/*==========================================================================*/
/*							SV C CE SOFTWARE GROUP							*/
/*==========================================================================*/
/*							OBJECT SPECIFICATION							*/
/*==========================================================================*/
/*	C Source:			%main.c%											*/
/*	Instance:																*/
/*	%version:			0.1%												*/
/*	%created_by:		734106 %											*/
/*	%date_created:		Mon Aug 31 14:14:22 2015 %							*/
/*==========================================================================*/
/*	DESCRIPTION :	C Main file. New peoject with CAN driver, scheduler,	*/
/*					MemAlloc, Interrupts, System Initialization.			*/
/*==========================================================================*/
/*	FUNCTION COMMENT :	Call for the initialization of all the modules and	*/
/*						cycle in the scheduler.								*/
/*==========================================================================*/
/*							OBJECT HISTORY									*/
/*==========================================================================*/
/*	REVISION	|	DATE		|						|	AUTHOR			*/
/*==========================================================================*/
/*	0.1			|	01/10/2015	|						|	Roberto Palos	*/
/*	This first version re-use code from previous practices, and call for the*/
/*	functions. This is our template to start working in the final practice.	*/
/*==========================================================================*/
#include    "MemAlloc_Cfg.h"
#include    "Can.h"
#include    "Can_Cfg.h"
#include    "sysinit.h"
#include	"SchM.h"
#include	"GPIO.h"
#include	"SchM_Cfg.h"


int main(void) {
	/* Mode initializations */
	sysinit_InitMode();
	/* Clock initializations */
	sysinit_InitSysClock();
	/* Memory Allcoation Initialization */
	MemAllocInit(&MemAllocConfig);
	/* SBC dependencies */
	InitDSPI_1();
	ConfigureMZC33905DSPI_1();
	/* CAN Initialization */
	CAN_Initialization(&can_driver_config);
	/* Initialize Interrupts */
	INTC_InitINTCInterrupts();
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	/* SchM Initialization */
	SchM_Init(&SchMConfig);
	/* Enable External Interrupts*/
	enableIrq();
	SchM_Start();
	for (;;) {
		
	}
}
