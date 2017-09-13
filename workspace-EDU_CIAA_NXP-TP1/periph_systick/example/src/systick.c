/*
 * @brief Blinky example using sysTick
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/


#if defined (BOARD_EDU_CIAA_NXP)
#define TP1_1 (1)	/* Test IDE LPCXpresso */
#define TP1_2 (2)	/* Test periph_systick LPCOpen */
#define TP1_3 (3)	/* Test LEDs & RGB-LEDs EDU-CIAA-NXP */
#define TP1_4 (4)	/* Test Push Buttons LPCOpen */
#define TP1_5 (5)	/* Test LEDs & RGB-LEDs & Push Buttons EDU-CIAA-NXP */
#define TP1_6 (6)	/* Test State Machines for LEDs & RGB-LEDs & Push Buttons EDU-CIAA-NXP */
#define TEST (TP1_2)
#endif


#define TICKRATE_HZ (1000)	/* 1000 ticks per second */

#if TEST==TP1_2
#define TICKRATE_10HZ (10)				/* 10 ticks per second */
#define TICKRATE_100HZ (100)			/* 100 ticks per second */
#define TICKRATE_1000HZ (1000)			/* 1000 ticks per second */
#define TICKRATE_HZ1 (TICKRATE_1000HZ)

#define LED_TOGGLE_250MS (250)
#define LED_TOGGLE_500MS (500)
#define LED_TOGGLE_MS1 (LED_TOGGLE_250MS * 1000 / TICKRATE_1000HZ)
#endif

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

#if TEST==TP1_2
volatile bool LED_Time_Flag = false;
#endif

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* TESTEO DE LA PLACA (TP1_1): */
#if TEST==TP1_1
/**
 * @brief	Handle interrupt from SysTick timer
 * @return	Nothing
 */
static uint32_t tick_ct = 0;
void SysTick_Handler(void)
{
	tick_ct += 1;
	if ((tick_ct % 50) == 0) {
		Board_LED_Toggle(0);
	}
}

int main(void)
{

	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ);

	while (1) {
		__WFI();
	}
}
#endif


/* CAMBIO DE PERÍODO DE PARPADEO DEL LED (TP1_2): */
#if TEST==TP1_2
void SysTick_Handler(void)
{
	LED_Time_Flag = true;
}


/**
 * @brief	main routine for blinky example
 * @return	Function should not exit.
 */
int main(void)
{
	uint32_t LED_Toggle_Counter = 0;

	SystemCoreClockUpdate();
	Board_Init();

	/* Enable and setup SysTick Timer at a periodic rate */
	SysTick_Config(SystemCoreClock / TICKRATE_HZ1);

	while (1) {
		__WFI();


		if (LED_Time_Flag == true) {
			LED_Time_Flag = false;

			if (LED_Toggle_Counter == 0) {
				LED_Toggle_Counter = LED_TOGGLE_MS1;
				Board_LED_Toggle(0);
			}
			else
				LED_Toggle_Counter--;
		}
	}
}

#endif
