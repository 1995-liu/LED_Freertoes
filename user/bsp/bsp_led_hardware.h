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
#define Key_1_GPIO_PIN  LL_GPIO_PIN_15
#define Key_1_Read()    LL_GPIO_IsInputPinSet(Key_1_GPIO_PORT, Key_1_GPIO_PIN)
/*LED*/
#define LED_1_GPIO_PORT GPIOB
#define LED_1_GPIO_PIN  LL_GPIO_PIN_5
#define LED_1_ON()      LL_GPIO_SetOutputPin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
#define LED_1_OFF()     LL_GPIO_ResetOutputPin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
#define LED_1_Toggle()  LL_GPIO_TogglePin(LED_1_GPIO_PORT,LED_1_GPIO_PIN)
/*16GPIO CONTRAL*/
#define MINI_OEI_POART  GPIOB
#define MINI_OEI_PIN    LL_GPIO_PIN_12
#define MINI_OEI_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_12)
#define MINI_OEI_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_12)

#define MINI_AI_POART   GPIOB
#define MINI_AI_PIN     LL_GPIO_PIN_13
#define MINI_AI_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_13)
#define MINI_AI_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_13)

#define MINI_BI_POART   GPIOB
#define MINI_BI_PIN     LL_GPIO_PIN_14
#define MINI_BI_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_14)
#define MINI_BI_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_14)

#define MINI_CLK_POART   GPIOB
#define MINI_CLK_PIN     LL_GPIO_PIN_15
#define MINI_CLK_UP()    LL_GPIO_SetOutputPin(GPIOB,LL_GPIO_PIN_15)
#define MINI_CLK_DOWN()  LL_GPIO_ResetOutputPin(GPIOB,LL_GPIO_PIN_15)

#define MINI_SDI0_POART     GPIOC
#define MINI_SDI0_PIN       LL_GPIO_PIN_6
#define MINI_SDI0_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_6)
#define MINI_SDI0_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_6)

#define MINI_LE_PORTA   GPIOC
#define MINI_LE_PIN     LL_GPIO_PIN_7
#define MINI_LE_UP()    LL_GPIO_SetOutputPin(GPIOC,LL_GPIO_PIN_7)
#define MINI_LE_DOWN()  LL_GPIO_ResetOutputPin(GPIOC,LL_GPIO_PIN_7)

#define NOPCNT 30

//显示效果监测数据
static const unsigned char L0_Shoot[16] =
{
    0xf6, 0xf0, 0x66, 0x66, 0x66, 0x00, 0x6e, 0x6e, 0x96, 0xf0, 0xcc, 0xcd, 0x66, 0x00, 0x64, 0x63
};
static const unsigned char L1_Shoot[16] =
{
    0xf6, 0xf6, 0x00, 0x66, 0x66, 0x66, 0x0e, 0x6e, 0x96, 0x96, 0x00, 0xcd, 0x66, 0x66, 0x0c, 0x62
};
static const unsigned char L2_Shoot[16] =
{
    0xf0, 0xf6, 0xff, 0x00, 0x00, 0x66, 0xff, 0x0e, 0xf0, 0x96, 0xff, 0x01, 0x00, 0x66, 0xff, 0x0d
};
static const unsigned char L3_Shoot[16] =
{
    0xf0, 0xff, 0x66, 0x00, 0x00, 0xff, 0x6e, 0x0e, 0xf0, 0xff, 0xcd, 0x01, 0x00, 0xff, 0x6b, 0x0f
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


