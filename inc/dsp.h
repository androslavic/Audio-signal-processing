#include "usart.h"
#include "math.h"

void outDSP_callback (double* data);
void shiftBuffers (void);

#define pi 3.141592
#define Fs 48000
#define Q 1


#define dBgain 0
//		A=sqrt( 10^(dBgain/20) );
#define A 1

#define minValue4 0
#define minValue5 0
#define minValue6 0
#define maxValue4 100
#define maxValue5 100
#define maxValue6 40000



extern volatile	double bufferInput[5];
extern volatile double bufferOutput[5];
extern volatile int parameter[numOfParameters];
extern volatile	int variables[numOfVariables];
