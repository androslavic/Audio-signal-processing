#include "i2c.h"
#include "usart.h"
#include "stdio.h"
 

#define ADDRESS		0x18u // 0011000 tlv datasheet str 41


void ispisRegistra(uint8_t reg);
void upisRegistra (uint8_t reg,uint8_t value);
void registerSetup (void);
