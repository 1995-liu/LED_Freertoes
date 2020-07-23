/******************************************************************************
* @file    BSP_LED_HARDWARE.h
* $Author: ericwong
* $Revision: V1.0
* $Date:: 2016-08-26 00:37:48 +0800
* @brief   BSP_LED_HARDWARE
*******************************************************************************
* @attention
*
*<h3><center>&copy; Copyright 2009-2012, EmbedNet</center>
*<center><a href="http:\\www.embed-net.com">http://www.embed-net.com</a></center>
*<center>All Rights Reserved</center></h3>
*
*******************************************************************************/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_LED_HARDWARE_H__
#define __BSP_LED_HARDWARE_H__
/* Includes ------------------------------------------------------------------*/
#include <includes.h>
/* BSP_LED_HARDWARE Define -----------------------------------------------------------*/
#undef BSP_LED_HARDWARE
#undef LOCAL_GLOBAL
#ifdef __BSP_LED_HARDWARE_C__
  #define BSP_LED_HARDWARE
  #define LOCAL_GLOBAL
#else
  #define BSP_LED_HARDWARE extern
#endif

#define Debug_BSP_LED_HARDWARE
#ifdef Debug_BSP_LED_HARDWARE
#define DebugTrace_BSP_LED_HARDWARE(...)       {moc_printf(__VA_ARGS__);}
#else
#define DebugTrace_BSP_LED_HARDWARE(...)
#endif

/* GLOBAL Define -------------------------------------------------------------*/
/*
*********************************************************************************************************
*                                          GLOBAL EXCEPTION DEFINES
*********************************************************************************************************
*/
/*SW-K1*/
#define Key_1_GPIO_PORT GPIOB
#define Key_1_GPIO_PIN 	LL_GPIO_PIN_15
#define Key_1_Read() 	LL_GPIO_IsInputPinSet(Key_1_GPIO_PORT, Key_1_GPIO_PIN)
/*LED*/
#define LED_1_GPIO_PORT GPIOB
#define LED_1_GPIO_PIN 	LL_GPIO_PIN_5
#define LED_1_ON()		LL_GPIO_SetOutputPin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
#define LED_1_OFF()		LL_GPIO_ResetOutputPin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
#define LED_1_Toggle()	LL_GPIO_TogglePin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
/*16GPIO CONTRAL*/
#define MINI_LE_PORTA   GPIOA
#define MINI_LE_PIN     LL_GPIO_PIN_1
#define MINI_LE_UP()    LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_1)
#define MINI_LE_DOWN()  LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_1)

#define MINI_OEI_POART 	GPIOA
#define MINI_OEI_PIN   	LL_GPIO_PIN_2
#define MINI_OEI_UP()    LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_2)
#define MINI_OEI_DOWN()  LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_2)

#define MINI_LCDI_POART 	GPIOA
#define MINI_LCDI_PIN   	LL_GPIO_PIN_3
#define MINI_LCDI_UP()    LL_GPIO_SetOutputPin(GPIOA,LL_GPIO_PIN_3)
#define MINI_LCDI_DOWN()  LL_GPIO_ResetOutputPin(GPIOA,LL_GPIO_PIN_3)

#define MINI_AI_POART 	GPIOB
#define MINI_AI_PIN   	LL_GPIO_PIN_0
#define MINI_AI_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_0)
#define MINI_AI_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_0)

#define MINI_SDI0_POART 	GPIOB
#define MINI_SDI0_PIN   	LL_GPIO_PIN_1
#define MINI_SDI0_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_1)
#define MINI_SDI0_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_1)

#define MINI_B9_POART 	GPIOB
#define MINI_B9_PIN   	LL_GPIO_PIN_9
#define MINI_B9_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_9)
#define MINI_B9_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_9)

#define MINI_B11_POART 	GPIOB
#define MINI_B11_PIN   	LL_GPIO_PIN_11
#define MINI_B11_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_11)
#define MINI_B11_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_11)

#define MINI_C0_POART 	GPIOC
#define MINI_C0_PIN   	LL_GPIO_PIN_0
#define MINI_C0_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_0)
#define MINI_C0_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_0)

#define MINI_C1_POART 	GPIOC
#define MINI_C1_PIN   	LL_GPIO_PIN_1
#define MINI_C1_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_1)
#define MINI_C1_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_1)

#define MINI_BI_POART 	GPIOC
#define MINI_BI_PIN   	LL_GPIO_PIN_2
#define MINI_BI_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_2)
#define MINI_BI_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_2)

#define MINI_C3_POART 	GPIOC
#define MINI_C3_PIN   	LL_GPIO_PIN_3
#define MINI_C3_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_3)
#define MINI_C3_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_3)

#define MINI_CLK_POART 	GPIOC
#define MINI_CLK_PIN   	LL_GPIO_PIN_4
#define MINI_CLK_UP()   LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_4)
#define MINI_CLK_DOWN() LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_4)

#define MINI_OE_POART 	GPIOC
#define MINI_OE_PIN   	LL_GPIO_PIN_5
#define MINI_OE_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_5)
#define MINI_OE_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_5)

#define MINI_C7_POART 	GPIOC
#define MINI_C7_PIN   	LL_GPIO_PIN_7
#define MINI_C7_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_7)
#define MINI_C7_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_7)

#define MINI_D12_POART 	GPIOD
#define MINI_D12_PIN   	LL_GPIO_PIN_12
#define MINI_D12_UP()   LL_GPIO_SetOutputPin(GPIOD,LL_GPIO_PIN_12)
#define MINI_D12_DOWN() LL_GPIO_ResetOutputPin(GPIOD,LL_GPIO_PIN_12)

#define MINI_E0_POART 	GPIOE
#define MINI_E0_PIN   	LL_GPIO_PIN_0
#define MINI_E0_UP()    LL_GPIO_SetOutputPin(GPIOE,LL_GPIO_PIN_0)
#define MINI_E0_DOWN()  LL_GPIO_ResetOutputPin(GPIOE,LL_GPIO_PIN_0)

static const unsigned char ONE[16]=
{
0x00,0xff,0x00,0xff,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xff,0x00,0x00
};

static const unsigned char TWO[16]=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff
};

static const unsigned char THREE[16]=
{
0xdd,0xcc,0xbb,0xaa,0x99,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11,0x00,0xff,0xee
};
static const unsigned char FOUR[16]=
{
0xcc,0xbb,0xaa,0x99,0x88,0x77,0x66,0x55,0x44,0x33,0x22,0x11,0x00,0xff,0xee,0xdd
};


/*
*********************************************************************************************************
*                                               GLOBAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                               GLOBAL PROTOTYPES
*********************************************************************************************************
*/
BSP_LED_HARDWARE void BSP_LED_HARDWAREGlobal(void);
BSP_LED_HARDWARE void LED_GPIO_Init(void);
BSP_LED_HARDWARE uint32_t g_OS_InitFlag;
BSP_LED_HARDWARE uint32_t SER;



/* LOCAL Define -------------------------------------------------------------*/
#ifdef LOCAL_GLOBAL
/*
*********************************************************************************************************
*                                          LOCAL EXCEPTION DEFINES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                               LOCAL VARIABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                              LOCAL PROTOTYPES
*********************************************************************************************************
*/

void BSP_LED_HARDWARELocal(void);

/*
*********************************************************************************************************
*                                              Exception Other PROTOTYPES
*********************************************************************************************************
*/


#endif
#undef LOCAL_GLOBAL
#endif
/*********************************END OF FILE**********************************/


