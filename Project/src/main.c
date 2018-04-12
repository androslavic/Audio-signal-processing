#include "main.h"



int main(void) {

	int data;
	init_I2C1(); 
	init_USART6(28800); 	
	resetButtonD5();
	SystemInit();
	/* Initialize MCO2 output, pin PC9 */
	TM_MCOOUTPUT_InitMCO2();
	/* Set MCO2 output = SYSCLK / 4 */
	TM_MCOOUTPUT_SetOutput2(TM_MCOOUTPUT2_Source_SYSCLK, TM_MCOOUTPUT_Prescaler_5);

	registerSetup();	
	
						
  while (1){  
		
		
//		while(!I2S_ready){
			outDSP_callback(&data);
//			I2S_send(data);			
	//	}

	}

	
		
	

}

