#include "dsp.h"


void outDSP_callback (int* data){
	
	double A,w0,alpha,b0,b1,b2,a0,a1,a2;
	
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
		
			A=sqrt( 10^(dBgain/20) );
			//    w0 = 2*pi*f0/Fs
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
	
			*data=*data*((b2+a0-a0*b0)/a2);
	}
}
