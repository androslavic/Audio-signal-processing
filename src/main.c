#include "main.h"



int main(void) {

	//char str[200];
	//double data=0;
	//int i;
	uint16_t temp=1;

	init_USART2(); 
	init_I2S();
//	init_I2C1();	
//	init_MCLK();
	resetButtonD5();
	registerSetup();	


	variables[2]=0;

volatile double bufferInput[3]={0};
volatile double bufferOutput[3]={0};
	
 
// i=0;
  while (1){  
		
	//	for(i=0;i<10000000;i++);

	
   if (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE)) {
        
            temp=SPI_I2S_ReceiveData(SPI3);
           // data= (double) temp;
						//outDSP_callback(&data);
        

    }
        
            if (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE)) {
            
         //   SPI_I2S_SendData(I2S3ext, data);
							SPI_I2S_SendData(I2S3ext, temp);

        }
	}

	
		
	

}

