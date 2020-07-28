/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2013; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                           MASTER INCLUDES
*
*                                     ST Microelectronics STM32
*                                              on the
*
*                                     Micrium uC-Eval-STM32F107
*                                         Evaluation Board
*
* Filename      : includes.h
* Version       : V1.00
* Programmer(s) : Eric
*                 
*********************************************************************************************************
*/
#ifndef INCLUDES_PRESENT
#define INCLUDES_PRESENT

/*
*********************************************************************************************************
*                                         STANDARD LIBRARIES
*********************************************************************************************************
*/
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <stdint.h>
//#include <ctype.h>
#include <math.h>
//#include <time.h>

/*
*********************************************************************************************************
*                                              LIBRARIES
*********************************************************************************************************
*/
//#include <cpu.h>
//#include <lib_def.h>
//#include <lib_ascii.h>
//#include <lib_math.h>
//#include <lib_mem.h>
//#include <lib_str.h>
//#include "crypto.h"

/*
*********************************************************************************************************
*                                                 OS
*********************************************************************************************************
*/
//#include "os.h"
#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "task.h"

/*
*********************************************************************************************************
*                                                 ST
*********************************************************************************************************
*/
//#include "stm32f10x.h"          // Modified by fire (Ô­ÊÇ #include  <stm32f10x_lib.h>)
#include "main.h"
//#include "stm32f1xx_hal.h"
//#include "stm32f1xx_ll_usart.h"
//#include "stm32f1xx_hal_def.h"

/*
*********************************************************************************************************
*                                              APP / BSP
*********************************************************************************************************
*/
//#include "types.h"
//#include "apptask_cfg.h"

//bsp
#include "bsp_led_hardware.h"
//#include "bsp_mocbox_UART1.h"
//#include "bsp_mocbox_UART2.h"
//#include "bsp_mocbox_UART3.h"
//#include "bsp_mocbox_UART4.h"
//#include "bsp_mocbox_UART5.h"
//#include "bsp_mocbox_5360.h"
//#include "bsp_mocbox_bluetooth.h"
//#include "bsp_mocbox_mpu6050.h"
//#include "bsp_mocbox_mpu6050_delay.h"
//#include "bsp_mocbox_can.h"
//#include "bsp_mocbox_adc.h"
//#include "bsp_mocbox_crc.h"
//#include "bsp_mocbox_rtc.h"
//#include "bsp_mocbox_inner_flash.h"
//#include "bsp_mocbox_spi_flash.h"
//#include "bsp_spl_f10x_flash.h"
/*--------basketball project bsp include start----------------------*/
//#include "bsp_moc_pwm.h"
//#include "bsp_moc_encoder.h"
//#include "bsp_moc_time2.h"
//#include "bsp_moc_time6.h"
//#include "bsp_moc_time7.h"
//#include "bsp_moc_time8.h"
/*--------basketball project bsp include start----------------------*/
//mw
//#include "mocbox_gprs.h"
//#include "mocbox_gps.h"
//#include "mocbox_bluetooth.h"
//#include "MQTTPacket.h"
//#include "mocbox_mqtt_mw.h"
//#include "mocbox_iap.h"
//#include "mocbox_common.h"
//#include "mocbox_iap_asm.h"
//#include "err_codes.h"


//apptask
//#include "mocbox_controlcenter.h"
//#include "mocbox_eventID.h"
//#include "mocbox_extendboxCANID.h"
//#include "mocbox_mqtt.h"
//#include "mocbox_can.h"
//#include "moc_os_mem.h"
//#include "moc_freertos_init.h"
//#include "mocbox_sms.h"
//#include "moc_bs_shootball_handle.h"
//#include "moc_bs_humancheck.h"
//#include "moc_bS_pushball_handle.h"
//#include "moc_bS_rotate_handle.h"


/*
*********************************************************************************************************
*                                            INCLUDES END
*********************************************************************************************************
*/
#endif

