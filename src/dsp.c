#include "dsp.h"

	volatile double bufferInput[5]={0};
	volatile double bufferOutput[5]={0};
		


void shiftBuffers (void) {
	
	bufferInput[4]=bufferInput[3];
	bufferInput[3]=bufferInput[2];
	bufferInput[2]=bufferInput[1];
	bufferInput[1]=bufferInput[0];
	bufferOutput[3]=bufferOutput[3];
	bufferOutput[2]=bufferOutput[2];
	bufferOutput[2]=bufferOutput[1];
	bufferOutput[1]=bufferOutput[0];	
	
}



void outDSP_callback (double* data){

	int a0=parameter[0];
	int a1=parameter[1];
	int a2=parameter[2];
	int b0=parameter[3];
	int b1=parameter[4];
	int b2=parameter[5];

	
	

	
//first sound effect using value[3] 
//distorsion
	
	if (variables[0]==1){
		
			bufferInput[0]=*data;
			bufferOutput[0]= bufferInput[0] + variables[3]*100;

	}
	
//second sound effect using value[4]
//	reverb
//y(n) = x(n-d) +1/2*x(n-2d) +1/4 * x(n-3d) + 1/8* x(n-4d) ; 
	
	
	if (variables[1]==1){
		
			shiftBuffers();
			
			bufferInput[0]=*data;
			bufferOutput[0]= bufferInput[0] + ((variables[4]/100.)/2.)* bufferInput[1]
																			+ ((variables[4]/100.)/4.)* bufferInput[2] 
																			+ ((variables[4]/100.)/8.)* bufferInput[3] ;
												

	
			*data=bufferOutput[0];	}
	
//third sound effect using value[5]
	if (variables[2]==1){
		
	


			shiftBuffers();
			
			bufferInput[0]=*data;
			bufferOutput[0]=( A * ( a0 * bufferInput[0] + a1 * bufferInput[1] + a2 * bufferInput[2] )
												- b1 * bufferOutput[1] - b2 * bufferOutput[2] ) / (4*b0);

	
			*data=bufferOutput[0];

		
		

	}
}

