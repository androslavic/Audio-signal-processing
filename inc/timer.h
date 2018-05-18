#include "stm32f4xx_tim.h"


void TM_TIMER_Init(void);
void TM_PWM_Init(void);

#define period 52
#define pulseLength25 (((period + 1) * 25) / 100 - 1)
#define pulseLength50 (((period + 1) * 50) / 100 - 1)
#define pulseLength75 (((period + 1) * 75) / 100 - 1)
#define pulseLength100 (((period + 1) * 100) / 100 - 1)
