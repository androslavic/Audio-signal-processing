#include "main.h"



int main(void) {

	int i,k;
	int variables[numOfVariables];
	char str[10];
	uint8_t data[200] = {2,2,2};

	init_I2C1(); // initialize I2C peripheral
	init_USART6(28800); 	
	resetButtonD5();
	SystemInit();
	/* Initialize MCO2 output, pin PC9 */
	TM_MCOOUTPUT_InitMCO2();
	/* Set MCO2 output = SYSCLK / 4 */
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);

	int connected = TM_I2C_IsDeviceConnected(I2C1, 0x18<<1);
			
	if (connected) {
					USART_puts(USART6, "Spojen\r\n");
								} else {
					USART_puts(USART6, "Nije spojen\r\n");
					}


		ispisRegistra(0);
		upisRegistra(0,0);
		ispisRegistra(0);

		
	while(1){	
		
		for(i=0;i<10000000;i++);
	
			
		k=rand()%14;	
		upisRegistra(31,k);
		ispisRegistra(31);
		

}

	
		
					
  while (0){  
		while(newData == 0);
		USART_puts(USART6, received_string2);	
		sscanf((const char *)received_string2, "%d %d %d %d %d %d", 
			&variables[0], &variables[1], &variables[2], &variables[3], &variables[4], &variables[5]);		
		//buffer clean
		for(i=0;i<MAX_STRLEN;i++)  
			received_string2[i]=0;
		newData=0;
		USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt 
	}
}

