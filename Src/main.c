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
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes =
{
    .name = "defaultTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 512 * 4
};
/* Definitions for myTask02 */
osThreadId_t myTask02Handle;
const osThreadAttr_t myTask02_attributes =
{
    .name = "myTask02",
    .priority = (osPriority_t) osPriorityLow,
    .stack_size = 512 * 4
};
/* USER CODE BEGIN PV */
unsigned char displayram[16][4] =
{
    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0xff, 0xf3, //L0
    0xff, 0xff, 0xff, 0xf2, //L1
    0xff, 0xff, 0xff, 0xfd, //L2
    0xff, 0xff, 0xff, 0xfb, //L3
    0xff, 0xff, 0xff, 0xf4, //L0
    0xff, 0xff, 0xff, 0xfc, //L1
    0xff, 0xff, 0xff, 0xff, //L2

    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0xff, 0xff, //L0
    0xff, 0xff, 0x9f, 0xff, //L1
    0xff, 0xff, 0x9f, 0xff, //L2
    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0x9f, 0xff, //L0
    0xff, 0xff, 0x9f, 0xff, //L1
    0xff, 0xff, 0xff, 0xff  //L2
};

const unsigned char backgroud[16][4] =
{
    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0xff, 0xf3, //L0
    0xff, 0xff, 0xff, 0xf2, //L1
    0xff, 0xff, 0xff, 0xfd, //L2
    0xff, 0xff, 0xff, 0xfb, //L3
    0xff, 0xff, 0xff, 0xf4, //L0
    0xff, 0xff, 0xff, 0xfc, //L1
    0xff, 0xff, 0xff, 0xff, //L2

    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0xff, 0xff, //L0
    0xff, 0xff, 0x9f, 0xff, //L1
    0xff, 0xff, 0x9f, 0xff, //L2
    0xff, 0xff, 0xff, 0xff, //L3
    0xff, 0xff, 0x9f, 0xff, //L0
    0xff, 0xff, 0x9f, 0xff, //L1
    0xff, 0xff, 0xff, 0xff  //L2
};

const unsigned char gRNum[13][7] =
{
    /*0*/
    //0b11110000
    //0b11110110
    //0b11110110
    //0b11110110
    //0b11110110
    //0b11110110
    //0b11110000
    0xf0, 0xf6, 0xf6, 0xf6, 0xf6, 0xf6, 0xf0,
    /*1*/
    //0b11111101
    //0b11111001
    //0b11111101
    //0b11111101
    //0b11111101
    //0b11111101
    //0b11111101
    0xfd, 0xf9, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd,
    /*2*/
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11110000
    //0b11110111
    //0b11110111
    //0b11110000
    0xf0, 0xfe, 0xfe, 0xf0, 0xf7, 0xf7, 0xf0,
    /*3*/
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11110000
    0xf0, 0xfe, 0xfe, 0xf0, 0xfe, 0xfe, 0xf0,
    /*4*/
    //0b11110110
    //0b11110110
    //0b11110110
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11111110
    0xf6, 0xf6, 0xf6, 0xf0, 0xfe, 0xfe, 0xfe,
    /*5*/
    //0b11110000
    //0b11110111
    //0b11110111
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11110000
    0xf0, 0xf7, 0xf7, 0xf0, 0xfe, 0xfe, 0xf0,
    /*6*/
    //0b11110000
    //0b11110111
    //0b11110111
    //0b11110000
    //0b11110110
    //0b11110110
    //0b11110000
    0xf0, 0xf7, 0xf7, 0xf0, 0xf6, 0xf6, 0xf0,
    /*7*/
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11111110
    //0b11111110
    //0b11111110
    //0b11111110
    0xf0, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
    /*8*/
    //0b11110000
    //0b11110110
    //0b11110110
    //0b11110000
    //0b11110110
    //0b11110110
    //0b11110000
    0xf0, 0xf6, 0xf6, 0xf0, 0xf6, 0xf6, 0xf0,
    /*9*/
    //0b11110000
    //0b11110110
    //0b11110110
    //0b11110000
    //0b11111110
    //0b11111110
    //0b11110000
    0xf0, 0xf6, 0xf6, 0xf0, 0xfe, 0xfe, 0xf0,
    /*black*/
    //0b11111111
    //0b11111111
    //0b11111111
    //0b11111111
    //0b11111111
    //0b11111111
    //0b11111111
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    /*%*/
    //0b11111111
    //0b11110011
    //0b11110010
    //0b11111101
    //0b11111011
    //0b11110100
    //0b11111100
    0xff, 0xf3, 0xf2, 0xfd, 0xfb, 0xf4, 0xfc,
    /*:*/
    //0b11111111
    //0b11111001
    //0b11111001
    //0b11111111
    //0b11111001
    //0b11111001
    //0b11111111
    0xff, 0xf9, 0xf9, 0xff, 0xf9, 0xf9, 0xff
};

const unsigned char BigOne[16][4] =
{
//big1
    0xff, 0xfe, 0x7f, 0xff, //L3
    0xff, 0xfc, 0x7f, 0xff, //L0
    0xff, 0xf8, 0x7f, 0xff, //L1
    0xff, 0xf8, 0x7f, 0xff, //L2

    0xff, 0xfe, 0x7f, 0xff, //L3
    0xff, 0xfe, 0x7f, 0xff, //L0
    0xff, 0xfe, 0x7f, 0xff, //L1
    0xff, 0xfe, 0x7f, 0xff, //L2

    0xff, 0xfe, 0x7f, 0xff, //L3
    0xff, 0xfe, 0x7f, 0xff, //L0
    0xff, 0xfe, 0x7f, 0xff, //L1
    0xff, 0xfe, 0x7f, 0xff, //L2

    0xff, 0xfe, 0x7f, 0xff, //L3
    0xff, 0xfe, 0x7f, 0xff, //L0
    0xff, 0xfe, 0x7f, 0xff, //L1
    0xff, 0xfe, 0x7f, 0xff  //L2
};

const unsigned char BigTWO[16][4] =
{
//big2
    0xff, 0xf8, 0x0f, 0xff, //L3
    0xff, 0xf8, 0x0f, 0xff, //L0
    0xff, 0xff, 0xcf, 0xff, //L1
    0xff, 0xff, 0xcf, 0xff, //L2

    0xff, 0xff, 0xcf, 0xff, //L3
    0xff, 0xff, 0xcf, 0xff, //L0
    0xff, 0xff, 0xcf, 0xff, //L1
    0xff, 0xf8, 0x0f, 0xff, //L2

    0xff, 0xf8, 0x0f, 0xff, //L3
    0xff, 0xf9, 0xff, 0xff, //L0
    0xff, 0xf9, 0xff, 0xff, //L1
    0xff, 0xf9, 0xff, 0xff, //L2

    0xff, 0xf9, 0xff, 0xff, //L3
    0xff, 0xf9, 0xff, 0xff, //L0
    0xff, 0xf8, 0x0f, 0xff, //L1
    0xff, 0xf8, 0x0f, 0xff  //L2
};

const unsigned char BigThree[16][4] =
{
//big3
    0xff, 0xf8, 0x0f, 0xff, //L3
    0xff, 0xf8, 0x0f, 0xff, //L0
    0xff, 0xff, 0xcf, 0xff, //L1
    0xff, 0xff, 0xcf, 0xff, //L2

    0xff, 0xff, 0xcf, 0xff, //L3
    0xff, 0xff, 0xcf, 0xff, //L0
    0xff, 0xff, 0xcf, 0xff, //L1
    0xff, 0xf8, 0x0f, 0xff, //L2

    0xff, 0xf8, 0x0f, 0xff, //L3
    0xff, 0xff, 0xcf, 0xff, //L0
    0xff, 0xff, 0xcf, 0xff, //L1
    0xff, 0xff, 0xcf, 0xff, //L2

    0xff, 0xff, 0xcf, 0xff, //L3
    0xff, 0xff, 0xcf, 0xff, //L0
    0xff, 0xf8, 0x0f, 0xff, //L1
    0xff, 0xf8, 0x0f, 0xff  //L2
};


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void *argument);
void StartTask02(void *argument);

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
    HAL_Init();

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
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL,
                                    &defaultTask_attributes);

    /* creation of myTask02 */
    myTask02Handle = osThreadNew(StartTask02, NULL, &myTask02_attributes);

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
    LL_SetSystemCoreClock(24000000);

    /* Update the time base */
    if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
    {
        Error_Handler();
    };
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

void moc_L0_ON(void)
{
    uint8_t t_testcycleA = 0;

    MINI_CLK_DOWN();
    MINI_SDI0_DOWN();
    MINI_OEI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT ; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_AI_DOWN();
    MINI_BI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_DOWN();
    MINI_OEI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
}


void moc_L1_ON(void)
{
    uint8_t t_testcycleA = 0;

    MINI_CLK_DOWN();
    MINI_SDI0_DOWN();
    MINI_OEI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT ; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_AI_UP();
    MINI_BI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_DOWN();
    MINI_OEI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
}


void moc_L2_ON(void)
{
    uint8_t t_testcycleA = 0;

    MINI_CLK_DOWN();
    MINI_SDI0_DOWN();
    MINI_OEI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT ; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_AI_DOWN();
    MINI_BI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_DOWN();
    MINI_OEI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
}


void moc_L3_ON(void)
{
    uint8_t t_testcycleA = 0;

    MINI_CLK_DOWN();
    MINI_SDI0_DOWN();
    MINI_OEI_DOWN();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT ; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_AI_UP();
    MINI_BI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
    MINI_LE_DOWN();
    MINI_OEI_UP();
    for (t_testcycleA = 0; t_testcycleA <= NOPCNT; t_testcycleA++)
    {
        __NOP();
    }
}

void Refresh_LED(void)
{
    uint8_t         i, j, k;

    moc_L3_ON();
    for (i = 0; i < 4; i++)
    {
        k = 12;
        for (j = 0; j < 4; j++)
        {
            LED_SendByte(displayram[k][i]);
            k -= 4;
        }
    }
    osDelay(1);

    moc_L0_ON();
    for (i = 0; i < 4; i++)
    {
        k = 13;
        for (j = 0; j < 4; j++)
        {
            LED_SendByte(displayram[k][i]);
            k -= 4;
        }
    }
    osDelay(1);

    moc_L1_ON();
    for (i = 0; i < 4; i++)
    {
        k = 14;
        for (j = 0; j < 4; j++)
        {
            LED_SendByte(displayram[k][i]);
            k -= 4;
        }
    }
    osDelay(1);

    moc_L2_ON();
    for (i = 0; i < 4; i++)
    {
        k = 15;
        for (j = 0; j < 4; j++)
        {
            LED_SendByte(displayram[k][i]);
            k -= 4;
        }
    }
    osDelay(1);;
}

void EreaseAll(void)
{
    memset(displayram,0xff,64);
}

void Big_Number(uint8_t senddata)
{
    if (senddata == 1)
    {
        memcpy(displayram, BigOne, 64);
    }
    else if (senddata == 2)
    {
        memcpy(displayram, BigTWO, 64);
    }
    else if (senddata == 3)
    {
        memcpy(displayram, BigThree, 64);
    }
    else
    {
        ;
    }
}

void Ball_Numbers(uint8_t senddata)
{
    uint8_t i;
    uint8_t t_hundred, t_ten, t_one;
    t_one = senddata % 10;
    t_ten = (senddata / 10) % 10;
    t_hundred = (senddata / 100) % 10;


    if ((t_ten == 0) && (t_hundred == 0))
    {
        t_hundred = 0x0a;
        t_ten = 0x0a;
    }

    if (t_hundred == 0)
    {
        t_hundred = 0x0a;
    }
    for (i = 0; i < 7; i++)
    {
        displayram[i][0] = (displayram[i][0] | 0xf0) & ((gRNum[t_hundred][i] << 4) |
                           0x0f);
        displayram[i][0] = (displayram[i][0] | 0x0f) & gRNum[t_ten][i];
        displayram[i][1] = (displayram[i][1] | 0xf0) & ((gRNum[t_one][i] << 4) | 0x0f);
    }
}
void Hit_Rate(uint8_t senddata)
{
    uint8_t i;
    uint8_t t_hundred, t_ten, t_one;
    t_one = senddata % 10;
    t_ten = (senddata / 10) % 10;
    t_hundred = (senddata / 100) % 10;


    if ((t_ten == 0) && (t_hundred == 0))
    {
        t_hundred = 0x0a;
        t_ten = 0x0a;
    }

    if (t_hundred == 0)
    {
        t_hundred = 0x0a;
    }
    for (i = 0; i < 7; i++)
    {
        displayram[i][2] = (displayram[i][2] | 0xf0) & ((gRNum[t_hundred][i] << 4) |
                           0x0f);
        displayram[i][2] = (displayram[i][2] | 0x0f) & gRNum[t_ten][i];
        displayram[i][3] = (displayram[i][3] | 0xf0) & ((gRNum[t_one][i] << 4) | 0x0f);
    }

}

void Score(uint8_t senddata)
{
    uint8_t i;
    uint8_t t_hundred, t_ten, t_one;
    t_one = senddata % 10;
    t_ten = (senddata / 10) % 10;
    t_hundred = (senddata / 100) % 10;


    if ((t_ten == 0) && (t_hundred == 0))
    {
        t_hundred = 0x0a;
        t_ten = 0x0a;
    }

    if (t_hundred == 0)
    {
        t_hundred = 0x0a;
    }
    for (i = 0; i < 7; i++)
    {
        displayram[i + 8][0] = (displayram[i + 8][0] | 0x0f) & gRNum[t_hundred][i];
        displayram[i + 8][1] = (displayram[i + 8][1] | 0xf0) & ((
                                   gRNum[t_ten][i] << 4) | 0x0f);
        displayram[i + 8][1] = (displayram[i + 8][1] | 0x0f) & gRNum[t_one][i];
    }
}

void Serve_Ball(uint8_t senddata)
{
    uint8_t i;
    uint8_t t_hundred, t_ten, t_one;
    t_one = senddata % 10;
    t_ten = (senddata / 10) % 10;
    t_hundred = (senddata / 100) % 10;


    if ((t_ten == 0) && (t_hundred == 0))
    {
        t_hundred = 0x0a;
        t_ten = 0x0a;
    }

    if (t_hundred == 0)
    {
        t_hundred = 0x0a;
    }
    for (i = 0; i < 7; i++)
    {
        displayram[i + 8][2] = (displayram[i + 8][2] | 0x0f) & gRNum[t_hundred][i];
        displayram[i + 8][3] = (displayram[i + 8][3] | 0xf0) & ((
                                   gRNum[t_ten][i] << 4) | 0x0f);
        displayram[i + 8][3] = (displayram[i + 8][3] | 0x0f) & gRNum[t_one][i];
    }

}
void StartDefaultTask(void *argument)
{
    /* USER CODE BEGIN 5 */
    /* Infinite loop */
    uint8_t         i;
    uint16_t t_testcycle = 0;
    uint8_t t_num = 0;
    uint8_t t_displaynum = 0;
    for (;;)
    {
        Refresh_LED();
        t_testcycle++;
        if (t_testcycle % 50 == 0)
        {
            t_displaynum++;
            if (t_displaynum >= 0 && t_displaynum < 5)
            {
                Big_Number(3);
            }
            else if (t_displaynum >= 5 && t_displaynum < 10)
            {
                Big_Number(2);
            }
            else if (t_displaynum >= 10 && t_displaynum < 15)
            {
                Big_Number(1);
            }
            else
            {
                memcpy(displayram,backgroud,64);
                Ball_Numbers(t_displaynum);
                Hit_Rate(t_displaynum);
                Score(t_displaynum);
                Serve_Ball(t_displaynum);
            }
        }
    }
    /* USER CODE END 5 */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
    /* USER CODE BEGIN StartTask02 */
    /* Infinite loop */
    for (; ;)
    {
        LED_1_Toggle();
        osDelay(1000);
    }

    /* USER CODE END StartTask02 */
}

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM1 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    /* USER CODE BEGIN Callback 0 */

    /* USER CODE END Callback 0 */
    if (htim->Instance == TIM1)
    {
        HAL_IncTick();
    }
    /* USER CODE BEGIN Callback 1 */

    /* USER CODE END Callback 1 */
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

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
