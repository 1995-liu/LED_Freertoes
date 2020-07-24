

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "bsp_led_hardware.h"


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* Definitions for defaultTask */
osThreadId_t    defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes =
{
    .name               = "defaultTask", 
    .priority           = (osPriority_t)
    osPriorityNormal, 
    .stack_size         = 512 * 4
};


/* Definitions for myTask02 */
osThreadId_t    myTask02Handle;
const osThreadAttr_t myTask02_attributes =
{
    .name               = "myTask02", 
    .priority           = (osPriority_t)
    osPriorityLow, 
    .stack_size         = 512 * 4
};


/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void * argument);
void StartTask02(void * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

    NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    /* System interrupt init*/
    /* PendSV_IRQn interrupt configuration */
    NVIC_SetPriority(PendSV_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

    /* SysTick_IRQn interrupt configuration */
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 15, 0));

    /** NOJTAG: JTAG-DP Disabled and SW-DP Enabled 
    */
    LL_GPIO_AF_Remap_SWJ_NOJTAG();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    LED_GPIO_Init();

    /* USER CODE BEGIN 2 */

    /* USER CODE END 2 */

    /* Init scheduler */
    osKernelInitialize();

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* creation of defaultTask */
    defaultTaskHandle   = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    /* creation of myTask02 */
    //myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */

    /* Start scheduler */
    osKernelStart();

    /* We should never get here as control is now taken by the scheduler */
    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1)
    {
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }

    /* USER CODE END 3 */
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
    LL_FLASH_SetLatency(LL_FLASH_LATENCY_0);

    if (LL_FLASH_GetLatency() != LL_FLASH_LATENCY_0)
    {
        Error_Handler();
    }

    LL_RCC_HSE_Enable();

    /* Wait till HSE is ready */
    while (LL_RCC_HSE_IsReady() != 1)
    {

    }

    LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE_DIV_1, LL_RCC_PLL_MUL_3);
    LL_RCC_PLL_Enable();

    /* Wait till PLL is ready */
    while (LL_RCC_PLL_IsReady() != 1)
    {

    }

    LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
    LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
    LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
    LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

    /* Wait till System clock is ready */
    while (LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
    {

    }

    LL_Init1msTick(24000000);
    LL_SetSystemCoreClock(24000000);
}


/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

    /* GPIO Ports Clock Enable */
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOA);

}


/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
//void Array(int one[][64])
//{
//	int i,j;
//	for(i=0;i<16;i++)
//		for(j=0;j<4;j++)		
//}
void LED_Delay(void)
{
    uint8_t         i   = 10;

    while (i)
        i--;
}


void MOC_Delay_ms(uint32_t nTime)
{
    //#to-do
    //   osStatus_t          t_err;
    uint32_t        tTimeCnt;

    if (g_OS_InitFlag == 0x55) //use hardware delay before os run
    {
        for (; nTime > 0; nTime--)
        {
            for (tTimeCnt = 0; tTimeCnt < 4000; tTimeCnt++)
            {
                ;
            }
        }
    }
    else if (g_OS_InitFlag == 0xaa) //use os delay after os run
    {
        osDelay(nTime);
    }
}

void LED_SendByte(uint8_t senddata) //数据从高位到低位//
{
    uint8_t         i   = 8;
    while (i--)
    {
        __NOP();
        MINI_CLK_DOWN();
        __NOP();

        if (senddata & 0x80)
        {
        __NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
            MINI_SDI0_UP();
        }
        else 
        {
        __NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
            MINI_SDI0_DOWN();	
        }

        senddata <<= 1;
        __NOP();
        MINI_CLK_UP();
    }	
		MINI_SDI0_UP();
}


//void LED_SendByte(void) //数据从高位到低位//
//{
//    MINI_CLK_UP();
//	__NOP();
//    MINI_CLK_DOWN();
//	__NOP();
//}
//void Test(uint16_t dat)
//{
//	uint16_t i;
//	MINI_CLK_DOWN();	
//	//MOC_Delay_ms(1000);
//	for(i=0;i<8;i++)
//		{
//			SER = dat>>7;	
//			dat<<=1;
//			MINI_SDI0_DOWN();
//			LED_Delay();
//			MINI_SDI0_UP();
//		}
//	MINI_CLK_UP();
//	//LED_Delay();
//	//MINI_CLK_UP();
//}
void moc_L0_ON(void)
{
		uint8_t t_testcycleA = 0;

  	 	MINI_CLK_DOWN();
		MINI_SDI0_DOWN();
		MINI_OEI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT ;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_AI_DOWN();
    	MINI_BI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_DOWN();
    	MINI_OEI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
}


void moc_L1_ON(void)
{
		uint8_t t_testcycleA = 0;

    	MINI_CLK_DOWN();
		MINI_SDI0_DOWN();
		MINI_OEI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT ;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_AI_UP();
    	MINI_BI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_DOWN();
    	MINI_OEI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
}


void moc_L2_ON(void)
{
		uint8_t t_testcycleA = 0;

    	MINI_CLK_DOWN();
		MINI_SDI0_DOWN();
		MINI_OEI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT ;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_AI_DOWN();
    	MINI_BI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_DOWN();
    	MINI_OEI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
}


void moc_L3_ON(void)
{
		uint8_t t_testcycleA = 0;

    	MINI_CLK_DOWN();
		MINI_SDI0_DOWN();
		MINI_OEI_DOWN();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT ;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_AI_UP();
    	MINI_BI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
		MINI_LE_DOWN();
    	MINI_OEI_UP();
		for(t_testcycleA = 0; t_testcycleA <=NOPCNT;t_testcycleA++){			
			__NOP();
		}
}



void StartDefaultTask(void * argument)
{
    /* USER CODE BEGIN 5 */
    /* Infinite loop */
    //MINI_LCDI_UP();

    uint8_t         i, j;
	
	//uint16_t t_testcycle = 0;
	j = 255;
    for (; ; )
    {
#if 0
		LL_GPIO_TogglePin(MINI_C1_POART,MINI_C1_PIN);
		LL_GPIO_TogglePin(MINI_SDI0_POART,MINI_SDI0_PIN);
		LL_GPIO_TogglePin(MINI_LE_PORTA,MINI_LE_PIN);
#endif
#if 1
		moc_L0_ON();    	
<<<<<<< HEAD
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L0_THREE[i]);
			//if(i == 0){LED_SendByte(L0L3_EIGHT[i]);}else{LED_SendByte(0xff);}
=======
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L0_EIGHT[i]);
			//if(i == 0){LED_SendByte(L0L3_EIGHT[i]);}else{LED_SendByte(0xff);}
		}
		osDelay(1);

		moc_L1_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L1_EIGHT[i]);
			//if(i == 1){LED_SendByte(j);}else{LED_SendByte(0xff);}
		}
		osDelay(1);

		moc_L2_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L2_EIGHT[i]);
			//if(i == 2){LED_SendByte(j);}else{LED_SendByte(0xff);}
		}
		osDelay(1);

		moc_L3_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L3_EIGHT[i]);
			//if(i == 3){LED_SendByte(j);}else{LED_SendByte(0xff);}
>>>>>>> 0ed461ca0181890208403f807e5ec57464016cf3
		}
		osDelay(1);

		moc_L1_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L1_THREE[i]);
			//if(i == 1){LED_SendByte(j);}else{LED_SendByte(0xff);}
		}
		osDelay(1);

		moc_L2_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L2_THREE[i]);
			//if(i == 2){LED_SendByte(j);}else{LED_SendByte(0xff);}
		}
		osDelay(1);

		moc_L3_ON();
		for (i = 0; i < 16; i++)
		{
			LED_SendByte(L3_THREE[i]);
			//if(i == 3){LED_SendByte(j);}else{LED_SendByte(0xff);}
		}
		osDelay(1);





//
//		moc_L0_ON();    	
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L0_TWO[i]);
//			//if(i == 0){LED_SendByte(L0L3_EIGHT[i]);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L1_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L1_TWO[i]);
//			//if(i == 1){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L2_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L2_TWO[i]);
//			//if(i == 2){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L3_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L3_TWO[i]);
//			//if(i == 3){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(100);
//
//
//
//
//
//
//
//		moc_L0_ON();    	
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L0_ONE[i]);
//			//if(i == 0){LED_SendByte(L0L3_EIGHT[i]);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L1_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L1_ONE[i]);
//			//if(i == 1){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L2_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L2_ONE[i]);
//			//if(i == 2){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(1);
//
//		moc_L3_ON();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(L3_ONE[i]);
//			//if(i == 3){LED_SendByte(j);}else{LED_SendByte(0xff);}
//		}
//		osDelay(100);


//		MINI_CLK_DOWN();
//		MINI_SDI0_DOWN();
//		MINI_OEI_DOWN();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		MINI_LE_UP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
////		t_testcycle++;
////		if(t_testcycle >= 0 && t_testcycle <= 10){
////			MINI_AI_DOWN();
////    		MINI_BI_DOWN();
////		}else if(t_testcycle > 10 && t_testcycle <= 20){
////			MINI_AI_UP();
////    		MINI_BI_DOWN();
////		}else if(t_testcycle > 20 && t_testcycle <= 30){
////			MINI_AI_DOWN();
////    		MINI_BI_UP();
////		}else if(t_testcycle > 30 && t_testcycle <= 40){
////			MINI_AI_UP();
////    		MINI_BI_UP();
////		}else{
////			t_testcycle = 0;
////		}
//		MINI_AI_DOWN();
//		MINI_BI_DOWN();
//
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		MINI_LE_DOWN();
//    	MINI_OEI_UP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		__NOP();
//		for (i = 0; i < 16; i++)
//		{
//			LED_SendByte(j);
//		}
		//osDelay(5);
		j--;
    }
#endif
    /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void * argument)
{
    /* USER CODE BEGIN StartTask02 */
    /* Infinite loop */
    for (; ; )
    {
        osDelay(1000);
    }

    /* USER CODE END StartTask02 */
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t * file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}


#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
