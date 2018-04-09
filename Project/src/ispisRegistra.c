#include "ispisRegistra.h"

void ispisRegistra(uint8_t reg){
	
		uint8_t value;
		char str[100];

		value=TM_I2C_Read(I2C1,ADDRESS<<1,reg);
		sprintf(str, "\r\n Registar %d ima vrijednost: %d\r\n",reg,value);		
		USART_puts(USART6, str);
	
}

void upisRegistra (uint8_t reg,uint8_t value){
	
	
		char str[100];
		sprintf(str, "\r\n U registar %d upisujem %d: \r\n",reg,value);		
		USART_puts(USART6, str);
		TM_I2C_Write(I2C1,ADDRESS<<1,reg,value);


	
}