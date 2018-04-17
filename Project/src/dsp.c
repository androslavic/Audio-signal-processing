#include "dsp.h"


extern volatile	double bufferInput[3]={0};
extern volatile double bufferOutput[3]={0};
extern volatile double temp=0;



void shiftBuffers (void) {
	
	bufferInput[2]=bufferInput[1];
	bufferInput[1]=bufferInput[0];
	bufferOutput[2]=bufferOutput[1];
	bufferOutput[1]=bufferOutput[0];	
	
}



void outDSP_callback (int* data){
	
	
	double w0,alpha,b0,b1,b2,a0,a1,a2;
	
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
		
		if (variables[5]>20000)
		//filtriraj sve ispod frekvencije variables[5]-20000
						w0=2*pi*(variables[5]-20000)/Fs;
		else
		//filtriraj sve iznad frekvencije variables[5]
						w0=2*pi*variables[5]/Fs;
		
		alpha=sin(w0)/(2*Q);

		
			//HPF  H(s) = s^2 / (s^2 + s/Q + 1)
			if (variables[5]>20000){
						
						
						b0 =  (1 + cos(w0))/2;
            b1 = -(1 + cos(w0));
            b2 =  (1 + cos(w0))/2;
            a0 =   1 + alpha;
            a1 =  -2*cos(w0);
            a2 =   1 - alpha;		
						
			}
			//LPF    H(s) = 1 / (s^2 + s/Q + 1)
			else if (variables[5]<20000){

						
						b0 =  (1 - cos(w0))/2;
            b1 =   1 - cos(w0);
            b2 =  (1 - cos(w0))/2;
            a0 =   1 + alpha;
            a1 =  -2*cos(w0);
            a2 =   1 - alpha;	
			}
		}
		
			temp=variables[5];
			shiftBuffers();
			
			bufferInput[0]=*data;
			bufferOutput[0]=( A * ( a0 * bufferInput[0] + a1 * bufferInput[1] + a2 * bufferInput[2] )
												- b1 * bufferOutput[1] - b2 * bufferOutput[2] ) / b0;
			
			*data=bufferOutput[0];


	}
}
