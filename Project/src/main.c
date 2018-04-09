#include "main.h"



int main(void) {

	int i;
	int variables[numOfVariables];
	init_I2C1(); 
	init_USART6(28800); 	
	resetButtonD5();
	SystemInit();

	/* Initialize MCO2 output, pin PC9 */
	TM_MCOOUTPUT_InitMCO2();
	/* Set MCO2 output = SYSCLK / 4 */
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);

		
	registerSetup();	
	
					

	
		
					
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

