#define __BSP_MOCBOX_UART5_C__
#include "bsp_mocbox_UART5.h"
#undef __BSP_MOCBOX_UART5_C__

/**********************************************
* eric 20200428
***********************************************/
/* UART5 init function */
void MX_UART5_Init(uint32_t baudrate)
    {
    /**USART5 GPIO Configuration
    PC12   ------> USART5_TX
    PD2   ----- -> USART5_RX
    */
    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};
    LL_USART_InitTypeDef USART_InitStruct = {0};
    /* 第1步：打开GPIO和USART部件的时钟 */
    /* Peripheral clock enable */
    LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_UART5);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOC);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_GPIOD);
    LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_AFIO);
    /* 第2步：将USART Tx的GPIO配置为推挽复用模式 */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_12;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    LL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    /* 第3步：将USART Rx的GPIO配置为浮空输入模式
    由于CPU复位后，GPIO缺省都是浮空输入模式，因此下面这个步骤不是必须的
    但是，我还是建议加上便于阅读，并且防止其它地方修改了这个口线的设置参数
    */
    GPIO_InitStruct.Pin = LL_GPIO_PIN_2;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_FLOATING;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_HIGH;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);
    /* 第4步：配置USART参数
    - BaudRate = 921600 baud
    - Word Length = 8 Bits
    - One Stop Bit
    - No parity
    - Hardware flow control disabled (RTS and CTS signals)
    - Receive and transmit enabled
    */
    LL_USART_DisableIT_IDLE(UART5);
    LL_USART_Disable(UART5);
    USART_InitStruct.BaudRate = baudrate;
    USART_InitStruct.DataWidth = LL_USART_DATAWIDTH_8B;
    USART_InitStruct.StopBits = LL_USART_STOPBITS_1;
    USART_InitStruct.Parity = LL_USART_PARITY_NONE;
    USART_InitStruct.TransferDirection = LL_USART_DIRECTION_TX_RX;
    USART_InitStruct.HardwareFlowControl = LL_USART_HWCONTROL_NONE;
    USART_InitStruct.OverSampling = LL_USART_OVERSAMPLING_16;
    LL_USART_Init(UART5, &USART_InitStruct);
    LL_USART_ConfigAsyncMode(UART5);
    LL_USART_Enable(UART5);
}

/*
  Copyright 2001, 2002 Georges Menie (www.menie.org)
  stdarg version contributed by Christian Ettinger
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.
    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
  putchar is the only external dependency for this file,
  if you have a working putchar, leave it commented out.
  If not, uncomment the define below and
  replace outbyte(c) by your own function call.
#define putchar(c) outbyte(c)
*/
static void mocprintchar(char**str, int c)
{
 int ltxdata=c;
 unsigned int ltimeput=0;
  if(str)
  {
    **str               = c;
    ++ (*str);
  }
  else
  {
    LL_USART_TransmitData8(UART5,(uint8_t)ltxdata);
    while( LL_USART_IsActiveFlag_TC(UART5) !=1)
        {
            ltimeput++;
            if(ltimeput >= dUART5_TimeOut)
                break;
        }
    LL_USART_ClearFlag_TC(UART5);
  }
}


#define PAD_RIGHT               1
#define PAD_ZERO                2


static int mocprints(char**out, const char*string, int width, int pad)
{
  register int    pc  = 0, padchar = ' ';

  if(width>0)
  {
    register int    len = 0;
    register const char*ptr;

    for(ptr = string; *ptr; ++ptr)
    {
      ++len;
    }

    if(len>=width)
    {
      width = 0;
    }
    else
    {
      width -= len;
    }

    if(pad&PAD_ZERO)
    {
      padchar = '0';
    }
  }

  if(! (pad&PAD_RIGHT))
  {
    for(; width>0; --width)
    {
      mocprintchar(out, padchar);
      ++pc;
    }
  }

  for(; *string; ++string)
  {
    mocprintchar(out, *string);
    ++pc;
  }

  for(; width>0; --width)
  {
    mocprintchar(out, padchar);
    ++pc;
  }

  return pc;
}


/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN           12


static int mocprinti(char**out, int i, int b, int sg, int width, int pad, int letbase)
{
  char            print_buf[PRINT_BUF_LEN];
  register char*  s;
  register int    t, neg = 0, pc = 0;
  register unsigned int u = i;

  if(i==0)
  {
    print_buf[0]        = '0';
    print_buf[1]        = '\0';
    return mocprints(out, print_buf, width, pad);
  }

  if(sg&&b==10&&i<0)
  {
    neg                 = 1;
    u                   =-i;
  }

  s                   = print_buf+PRINT_BUF_LEN-1;
  *s                  = '\0';

  while(u)
  {
    t                   = u % b;

    if(t>=10)
    {
      t += letbase-'0'-10;
    }

    * --s               = t+'0';
    u                   /= b;
  }

  if(neg)
  {
    if(width&&(pad&PAD_ZERO))
    {
      mocprintchar(out, '-');
      ++pc;
      --width;
    }
    else
    {
      * --s               = '-';
    }
  }

  return pc+mocprints(out, s, width, pad);
}


static int mocprint(char**out, const char*format, va_list args)
{
  register int    width, pad;
  register int    pc  = 0;
  char            scr[2];

  for(; *format!=0; ++format)
  {
    if(*format=='%')
    {
      ++format;
      width               = pad = 0;

      if(*format=='\0')
      {
        break;
      }

      if(*format=='%')
      {
        goto out;
      }

      if(*format=='-')
      {
        ++format;
        pad                 = PAD_RIGHT;
      }

      while(*format=='0')
      {
        ++format;
        pad                 |= PAD_ZERO;
      }

      for(; *format>='0'&&*format<='9'; ++format)
      {
        width               *= 10;
        width               +=*format-'0';
      }

      if(*format=='s')
      {
        register char*  s   = (char*)

        va_arg(         args, int);
        pc                  += mocprints(out, s ? s: "(null)", width, pad);
        continue;
      }

      if(*format=='d')
      {
        pc                  += mocprinti(out, va_arg(args, int), 10, 1, width, pad, 'a');
        continue;
      }

      if(*format=='x')
      {
        pc                  += mocprinti(out, va_arg(args, int), 16, 0, width, pad, 'a');
        continue;
      }

      if(*format=='X')
      {
        pc                  += mocprinti(out, va_arg(args, int), 16, 0, width, pad, 'A');
        continue;
      }

      if(*format=='u')
      {
        pc                  += mocprinti(out, va_arg(args, int), 10, 0, width, pad, 'a');
        continue;
      }

      if(*format=='c')
      {
        /* char are converted to int then pushed on the stack */
        scr[0]              = (char)
        va_arg(args, int);
        scr[1]              = '\0';
        pc                  += mocprints(out, scr, width, pad);
        continue;
      }
    }
    else
    {
out:
      mocprintchar(out, *format);
      ++pc;
    }
  }

  if(out)
  {
    **out = '\0';
  }

  va_end(args);
  return pc;
}


int moc_printf(const char*format, ...)
{
  va_list         args;

  va_start(args, format);
  return mocprint(0, format, args);
}


int moc_sprintf(char*out, const char*format, ...)
{
  va_list         args;

  va_start(args, format);
  return mocprint(&out, format, args);
}


int moc_snprintf(char*buf, unsigned int count, const char*format, ...)
{
  va_list         args;
  (void)count;

  va_start(args, format);
  return mocprint(&buf, format, args);
}


#ifdef TEST_PRINTF
int main(void)
{
  char*           ptr = "Hello world!";
  char*           np  = 0;
  int             i   = 5;
  unsigned int    bs  = sizeof(int)*8;
  int             mi;
  char            buf[80];

  mi                  = (1 << (bs-1))+1;
  printf("%s\n", ptr);
  printf("printf test\n");
  printf("%s is null pointer\n", np);
  printf("%d = 5\n", i);
  printf("%d = - max int\n", mi);
  printf("char %c = 'a'\n", 'a');
  printf("hex %x = ff\n", 0xff);
  printf("hex %02x = 00\n", 0);
  printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
  printf("%d %s(s)%", 0, "message");
  printf("\n");
  printf("%d %s(s) with %%\n", 0, "message");
  sprintf(buf, "justif: \"%-10s\"\n", "left");
  printf("%s", buf);
  sprintf(buf, "justif: \"%10s\"\n", "right");
  printf("%s", buf);
  sprintf(buf, " 3: %04d zero padded\n", 3);
  printf("%s", buf);
  sprintf(buf, " 3: %-4d left justif.\n", 3);
  printf("%s", buf);
  sprintf(buf, " 3: %4d right justif.\n", 3);
  printf("%s", buf);
  sprintf(buf, "-3: %04d zero padded\n", -3);
  printf("%s", buf);
  sprintf(buf, "-3: %-4d left justif.\n", -3);
  printf("%s", buf);
  sprintf(buf, "-3: %4d right justif.\n", -3);
  printf("%s", buf);

  return 0;
}

/*
 * if you compile this file with
 *   gcc -Wall $(YOUR_C_OPTIONS) -DTEST_PRINTF -c printf.c
 * you will get a normal warning:
 *   printf.c:214: warning: spurious trailing `%' in format
 * this line is testing an invalid % at the end of the format string.
 *
 * this should display (on 32bit int machine) :
 *
 * Hello world!
 * printf test
 * (null) is null pointer
 * 5 = 5
 * -2147483647 = - max int
 * char a = 'a'
 * hex ff = ff
 * hex 00 = 00
 * signed -3 = unsigned 4294967293 = hex fffffffd
 * 0 message(s)
 * 0 message(s) with %
 * justif: "left      "
 * justif: "     right"
 *  3: 0003 zero padded
 *  3: 3    left justif.
 *  3:    3 right justif.
 * -3: -003 zero padded
 * -3: -3   left justif.
 * -3:   -3 right justif.
 */
#endif

