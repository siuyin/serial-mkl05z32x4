/* ###################################################################
 **     Filename    : main.c
 **     Project     : serial-mkl05z32x4
 **     Processor   : MKL05Z32VLF4
 **     Version     : Driver 01.01
 **     Compiler    : GNU C Compiler
 **     Date/Time   : 2020-07-25, 00:26, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.01
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "AS1.h"
#include "SysTick.h"
#include "Bit1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include <stdbool.h>

LDD_TDeviceData* uart0;
void SendHelloTask(void) {
	static unsigned int nrt;
	if (tick != nrt) {
		return;
	}
	nrt += 500;

	static bool sentFirst;
	if (!sentFirst) {
		AS1_SendBlock(uart0, "Hello", 5);
	}
	if (AS1_GetTxCompleteStatus(uart0) == true) {
		AS1_SendBlock(uart0, "Hello", 5);
	}
}

LDD_TDeviceData* redLED;
void BlinkLEDTask(void) {
	static nrt;
	if (tick != nrt) {
		return;
	}
	nrt += 500;

	Bit1_NegVal(redLED);
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */

	uart0 = AS1_Init(NULL);
	redLED = Bit1_Init(NULL);

	while (1) {
		SendHelloTask();
		BlinkLEDTask();
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;) {
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
 ** @}
 */
/*
 ** ###################################################################
 **
 **     This file was created by Processor Expert 10.5 [05.21]
 **     for the Freescale Kinetis series of microcontrollers.
 **
 ** ###################################################################
 */
