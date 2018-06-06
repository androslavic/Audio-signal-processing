#ifndef __AUDIO_H_
#define __AUDIO_H_

#include <stm32f4xx_gpio.h>
#include <stm32f4xx_spi.h>
#include <stm32f4xx_i2c.h>
#include "tm_stm32f4_gpio.h"
#include <stm32f4xx_rcc.h>
#include "tm_stm32f4_mco_output.h"


/** GPIOA **/
#define I2S_WS GPIO_Pin_4

/** GPIOB **/
#define I2C_SCL GPIO_Pin_6
#define I2C_SDA GPIO_Pin_9

/** GPIOC **/
#define I2S_BCLK GPIO_Pin_7
#define I2S_SCLK GPIO_Pin_10
#define I2S_SD GPIO_Pin_12
#define I2S_SD_EXT GPIO_Pin_2

/** GPIOD **/
#define AUDIO_RST GPIO_Pin_4

#define AUDIO_I2C_ADDRESS 0x94
#define HOME_ADDRESS 0x33


void init_I2S(void);
void init_I2C(void);
void sendBytesAudioI2C(char *bytes, int num);
void configAudio(void);
void init_MCLK(void);

#endif
