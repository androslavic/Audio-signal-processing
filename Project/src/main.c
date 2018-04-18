#include "main.h"



int main(void) {

	char str[200];
	double data[100]={0};
	int i,j;
	init_USART6(28800); 	
	init_USART1(28800); 	
	resetButtonD5();
	/* Initialize MCO2 output, pin PC9 */
//	TM_MCOOUTPUT_InitMCO2();
	/* Set MCO2 output = SYSCLK / 4 */
//	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);

	configAudio();
	registerSetup();	

	
	
for (i = 0; i <11 ; i++)
 {
 data[i] =10000* sin(i*PI/50)+10000* cos(i*PI/25);
	 sprintf(str, "\r\n data[%d] ima vrijednost: %g\r\n",i,data[i]);		
		USART_puts(USART6, str);
	 			
 }

 
 i=0;
 j=0;
 
  while (1){  
		
		if (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE)) {
			

			outDSP_callback(&data[i]);
			SPI_I2S_SendData(SPI3, data[i]);
			
			if (i<101) 
			{i++;
			}
			else {i=0;}
		}
		
		


	}

	
		
	

}

