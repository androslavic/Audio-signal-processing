#include "dsp.h"


volatile	double bufferInput[3]={0};
volatile double bufferOutput[3]={0};
volatile double temp=0;



void shiftBuffers (void) {
	
	bufferInput[2]=bufferInput[1];
	bufferInput[1]=bufferInput[0];
	bufferOutput[2]=bufferOutput[1];
	bufferOutput[1]=bufferOutput[0];	
	
}



void outDSP_callback (int* data){
	
	
	double a0=parameter[0];
	double a1=parameter[1];
	double a2=parameter[2];
	double b0=parameter[3];
	double b1=parameter[4];
	double b2=parameter[5];
	
//first sound effect using value[3] 
	if (variables[0]==1){
			return;
	}
	
//second sound effect using value[4]
	if (variables[1]==1){
			return;
	}
	
//third sound effect using value[5]
	if (variables[2]==1){
		
	if((temp-variables[5])>100 || (temp-variables[5])<-100)
		{

			shiftBuffers();
			
			bufferInput[0]=*data;
			bufferOutput[0]=( A * ( a0 * bufferInput[0] + a1 * bufferInput[1] + a2 * bufferInput[2] )
												- b1 * bufferOutput[1] - b2 * bufferOutput[2] ) / b0;
			
			*data=bufferOutput[0];


	}
}
}
