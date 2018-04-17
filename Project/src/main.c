#include "main.h"



int main(void) {

	char str[200];
	double data[100];
	int i;
//	init_I2C1(); 
	init_USART6(28800); 	
	resetButtonD5();
	SystemInit();
	/* Initialize MCO2 output, pin PC9 */
	TM_MCOOUTPUT_InitMCO2();
	/* Set MCO2 output = SYSCLK / 4 */
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);

//	registerSetup();	
		configAudio();

	
	variables[2]=1;
	variables[5]=20010;

for (i = 0; i <101 ; i++)
 {
 data[i] =10000* sin(i*PI/50)+10000* sin(i*PI/25);
	 sprintf(str, "\r\n data[%d] ima vrijednost: %g\r\n",i,data[i]);		
		USART_puts(USART6, str);
	 			
 }

 i=0;
 
  while (1){  

		if (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE)) {
			SPI_I2S_SendData(SPI3, data[i]);
			if (i<101) i++;
			else i=0;
		}
		
		
		
//		while(!I2S_ready){
//			outDSP_callback(&data);
//			GPIO_SetBits(GPIOD, GPIO_Pin_5);
//			if (variables[5]>40000)
//				variables[5]=0;
//			variables[5]++;
//			if (data>65000)
//				data=0;
//			data++;
//			GPIO_ResetBits(GPIOD, GPIO_Pin_5);

//			
//			I2S_send(data);			
	//	}
			

	}

	
		
	

}

