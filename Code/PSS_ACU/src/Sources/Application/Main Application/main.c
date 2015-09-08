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
/*	0.1			|	01/09/2015	|						|	Roberto Palos	*/
/*	This first version re-use code from previous practices, and call for the*/
/*	functions. This is our template to start working in the final practice.	*/
/*==========================================================================*/
/*	0.2			|	08/09/2015	|						|	Roberto Palos	*/
/*	Added to test code to improve the functionality of the main file with   */
/*	the development board dip switch, also corrected date from past rev.    */
/*==========================================================================*/
#include    "MemAlloc_Cfg.h"
#include    "Can.h"
#include    "Can_Cfg.h"
#include    "sysinit.h"
#include	"SchM.h"
#include	"GPIO.h"
#include	"ACU.h"

#define		BASIC_MODE_ENABLE		SIU.GPDI[102].B.PDI == 1
#define		ENHANCED_MODE_ENABLE	SIU.GPDI[103].B.PDI == 1
#define		EURO_MODE_ENABLE		SIU.GPDI[104].B.PDI == 1

T_UBYTE rub_ModeConfig = 0;



void MN_ModeConfig(void){
	if(BASIC_MODE_ENABLE){
		rub_ModeConfig = Basic_Mode;
	}
	else if(ENHANCED_MODE_ENABLE){
		rub_ModeConfig = Enhanced_Mode;
	}
	else if(EURO_MODE_ENABLE){
		rub_ModeConfig = Euro_Mode;
	}
}

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
	SchM_Init(&cs_SchConfig);
	/* Enable External Interrupts*/
	enableIrq();
	
  SIU.PCR[24].R = 0x2000;         /* MPC56xxB: Initialize PB[8] as ANS0 */
  SIU.PCR[25].R = 0x2000;         /* MPC56xxB: Initialize PB[9] as ANS1 */
  SIU.PCR[26].R = 0x2000;         /* MPC56xxB: Initialize PB[10] as ANS2 */
  
vfnGPIO_LED_Init();

vfnGPIO_Init_channel(102,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);
vfnGPIO_Init_channel(103,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);
vfnGPIO_Init_channel(104,GPIO_INPUT,GPIO_OPEN_DRAIN_ENABLE);

  ADC_0.MCR.R = 0x20000000;         /* Initialize ADC0 for scan mode */
  ADC_0.NCMR1.R = 0x00000007;     /* Select ANS0:2 inputs for conversion */
  ADC_0.CTR1.R = 0x00008606;      /* Conversion times for 32MHz ADClock */
  ADC_0.MCR.B.NSTART=1;             /* Trigger normal conversions for ADC0 */
  
  
  
  
	SchM_Start();
	for (;;) {
		
	}
}
