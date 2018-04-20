/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include <stdio.h>
#include <misc.h>			 // I recommend you have a look at these in the ST firmware folder
#include <stdlib.h>
#include <string.h>
#include <stm32f4xx_i2c.h>
#include <math.h>  


/*User Includes ------------------------------------------------------------------*/
#include "usart.h"
#include "i2s.h"
#include "i2c.h"
#include "timer.h"
#include "tm_stm32f4_mco_output.h"
#include "ispisRegistra.h"
#include "dsp.h"

void resetButtonD5(void);

#define ADDRESS		0x18u // 0011000 tlv datasheet str 41
#define PI 3.14159265


#endif
