/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef USART_H
#define USART_H


/* Includes ------------------------------------------------------------------*/
#include <stm32f4xx.h>
#include <stm32f4xx_gpio.h>
#include <stm32f4xx_rcc.h>
#include <stm32f4xx_usart.h> // under Libraries/STM32F4xx_StdPeriph_Driver/inc and src


void Delay(__IO uint32_t nCount);
void init_USART1(uint32_t baudrate);
void init_USART6(uint32_t baudrate);
void USART_puts(USART_TypeDef* USARTx, volatile char *s);
void USART1_IRQHandler(void);


#define numOfVariables 6
#define MAX_STRLEN 20 // this is the maximum string length of our string in characters

extern volatile char received_string[MAX_STRLEN+1]; // this will hold the recieved string
extern volatile char received_string2[MAX_STRLEN+1]; // this will hold the recieved string
extern volatile int newData;

#endif
