#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


void resetButtonD5(void){

	int i;
	GPIO_InitTypeDef GPIO_InitDef;

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_100MHz;
	//Initialize pins
	GPIO_Init(GPIOD, &GPIO_InitDef);
	
	for (i=0;i<500000;i++);
	GPIO_SetBits(GPIOD, GPIO_Pin_5);
	
	
	}
