#include "ispisRegistra.h"

void ispisRegistra(uint8_t reg){
	
		uint8_t value;
		char str[100];

		value=TM_I2C_Read(I2C1,ADDRESS<<1,reg);
		sprintf(str, "\r\n Registar %d ima vrijednost: %d\r\n",reg,value);		
		USART_puts(USART2, str);
	
}

void upisRegistra (uint8_t reg,uint8_t value){
	
	
		char str[100];
		sprintf(str, "\r\n U registar %d upisujem %d: \r\n",reg,value);		
		USART_puts(USART2, str);
		TM_I2C_Write(I2C1,ADDRESS<<1,reg,value);


	
}


void registerSetup (void){
	
	int connected = TM_I2C_IsDeviceConnected(I2C1, 0x18<<1);
	if (connected) {
					USART_puts(USART2, "Spojen\r\n");	
								
								
	// koristimo page 0
		upisRegistra(0,0);
		ispisRegistra(0);
		
// software reset
		upisRegistra(0x01,0x80);
		ispisRegistra(0x01);
					

					
// Register 9: Audio Serial Data Interface Control Register B					
//Audio Serial Data Word Length Control
//00: Audio data word length = 16 bits
//01: Audio data word length = 20 bits
//10: Audio data word length = 24 bits
//11: Audio data word length = 32 bits
//		upisRegistra(9,0x30);
//		ispisRegistra(9);
					

		
/// Register 17: MIC2L/R to Left-ADC Control Register
//		upisRegistra(17,0x0F);
//		ispisRegistra(17);

// Register 18: MIC2/LINE2 to Right-ADC Control Register
//		upisRegistra(18,0xF0);
//		ispisRegistra(18);

//Register 19: MIC1LP/LINE1LP to Left-ADC Control Register
		upisRegistra(0x13,0x04);
		ispisRegistra(0x13);

//Register 22: MIC1RP/LINE1RP to Right-ADC Control Register
		upisRegistra(0x16,0x04);
		ispisRegistra(0x16);
		
/// Register 15: Left-ADC PGA Gain Control Register
		upisRegistra(15,0x00);
		ispisRegistra(15);
//		
/// Register 16: Right-ADC PGA Gain Control Register
		upisRegistra(16,0x00);
		ispisRegistra(16);
		
// Register 7: Codec Data-Path Setup Register
// D4-D3 01: Left-DAC data path plays left-channel input data.
// D2-D1 01: Right-DAC data path plays right-channel input data					
//		D4-D1 0000: MUTED
		upisRegistra(7,0x0A);
		ispisRegistra(7);


// Register 37: DAC Power and Output Driver Control Register
// D7:  Left DAC is powered up.
// D6:  Right DAC is powered up.
// D5-D4:
//00: HPLCOM configured as differential of HPLOUT
//01: HPLCOM configured as constant VCM output
//10: HPLCOM configured as independent single-ended output
//11: Reserved. Do not write this sequence to these register bits
		upisRegistra(37,0xC0);
		ispisRegistra(37);
		
// Register 38: High-Power Output Driver Control Register
// D7-D6: RESERVED [00]
//??????????????????????????????????????????????????????
// D5-D3: HPRCOM Output Driver Configuration Control
//???????????????????????????????????????????????????????
//	000: HPRCOM configured as differential of HPROUT 
//	001: HPRCOM configured as constant VCM output  
//	010: HPRCOM configured as independent single-ended output
//	011: HPRCOM configured as differential of HPLCOM
//	100: HPRCOM configured as external feedback with HPLCOM as constant VCM output
//	101–111: Reserved. Do not write these sequences to these register bits.
// D2-D1: Short circuit control [11] enabled.
// D0: reserved [0]
//	upisRegistra(38,0x00);
//		ispisRegistra(38);
		
// Register 41: DAC Output Switching Control Register
// D7-D6: Left-DAC Output Switching Control
//	00: Left-DAC output selects DAC_L1 path.
//	01: Left-DAC output selects DAC_L3 path to left line output driver.
//	10: Left-DAC output selects DAC_L2 path to left high-power output drivers.
//	11: Reserved. Do not write this sequence to these register bits.
// D5-D4: Right-DAC Output Switching Control
//	00: Right-DAC output selects DAC_R1 path.
//	01: Right-DAC output selects DAC_R3 path to right line output driver.
//	10: Right-DAC output selects DAC_R2 path to right high-power output drivers.
//	11: Reserved. Do not write this sequence to these register bits.
//		upisRegistra(41,0x50);
//		ispisRegistra(41);


// Register 43: Left-DAC Digital Volume Control Register
		upisRegistra(43,0);
		ispisRegistra(43);
		
//Register 44: Right-DAC Digital Volume Control Register
		upisRegistra(44,0);
		ispisRegistra(44);


// Register 82: DAC_L1 to LEFT_LOP/M Volume Control Register
		upisRegistra(82,0x80);
		ispisRegistra(82);
		

		
// Register 91: PGA_R to RIGHT_LOP/M Volume Control Register
//		upisRegistra(91,0x80);
//		ispisRegistra(91);

//Register 92: DAC_R1 to RIGHT_LOP/M Volume Control Register
		upisRegistra(92,0x80);
		ispisRegistra(92);
		
// Register 86: LEFT_LOP/M Output Level Control Register
// 0x08 ili 0x0A   "all programmed gains to LEFT_LOP/M have been applied"??
		upisRegistra(86,0x09);
		ispisRegistra(86);
		
// Register 93: RIGHT_LOP/M Output Level Control Register
// 0x08 ili 0x0A   "all programmed gains to LEFT_LOP/M have been applied"??
		upisRegistra(93,0x09);
		ispisRegistra(93);



}
	else {
					USART_puts(USART2, "Nije spojen\r\n");
					}
	
}


void registerSetup2 (void){
	
	int connected = TM_I2C_IsDeviceConnected(I2C1, 0x18<<1);
	if (connected) {
					USART_puts(USART2, "Spojen\r\n");	
								
								
	// koristimo page 0
		upisRegistra(0,0);
		ispisRegistra(0);
		
// software reset
		upisRegistra(0x01,0x80);
		ispisRegistra(0x01);
					

					
// Register 9: Audio Serial Data Interface Control Register B					
//Audio Serial Data Word Length Control
//00: Audio data word length = 16 bits
//01: Audio data word length = 20 bits
//10: Audio data word length = 24 bits
//11: Audio data word length = 32 bits
		upisRegistra(9,0x00);
		ispisRegistra(9);
					



//Register 19: MIC1LP/LINE1LP to Left-ADC Control Register
		upisRegistra(0x13,0x04);
		ispisRegistra(0x13);

//Register 22: MIC1RP/LINE1RP to Right-ADC Control Register
		upisRegistra(0x16,0x04);
		ispisRegistra(0x16);
		
/// Register 15: Left-ADC PGA Gain Control Register
		upisRegistra(15,0x00);
		ispisRegistra(15);
//		
/// Register 16: Right-ADC PGA Gain Control Register
		upisRegistra(16,0x00);
		ispisRegistra(16);
		
// Register 7: Codec Data-Path Setup Register
// D4-D3 01: Left-DAC data path plays left-channel input data.
// D2-D1 01: Right-DAC data path plays right-channel input data					
//		D4-D1 0000: MUTED
//		upisRegistra(7,0x0A);
//		ispisRegistra(7);


// Register 37: DAC Power and Output Driver Control Register
// D7:  Left DAC is powered up.
// D6:  Right DAC is powered up.
// D5-D4:
//00: HPLCOM configured as differential of HPLOUT
//01: HPLCOM configured as constant VCM output
//10: HPLCOM configured as independent single-ended output
//11: Reserved. Do not write this sequence to these register bits
		upisRegistra(37,0xC0);
		ispisRegistra(37);
		
// Register 38: High-Power Output Driver Control Register
// D7-D6: RESERVED [00]
//??????????????????????????????????????????????????????
// D5-D3: HPRCOM Output Driver Configuration Control
//???????????????????????????????????????????????????????
//	000: HPRCOM configured as differential of HPROUT 
//	001: HPRCOM configured as constant VCM output  
//	010: HPRCOM configured as independent single-ended output
//	011: HPRCOM configured as differential of HPLCOM
//	100: HPRCOM configured as external feedback with HPLCOM as constant VCM output
//	101–111: Reserved. Do not write these sequences to these register bits.
// D2-D1: Short circuit control [11] enabled.
// D0: reserved [0]
//	upisRegistra(38,0x00);
//		ispisRegistra(38);
		
// Register 41: DAC Output Switching Control Register
// D7-D6: Left-DAC Output Switching Control
//	00: Left-DAC output selects DAC_L1 path.
//	01: Left-DAC output selects DAC_L3 path to left line output driver.
//	10: Left-DAC output selects DAC_L2 path to left high-power output drivers.
//	11: Reserved. Do not write this sequence to these register bits.
// D5-D4: Right-DAC Output Switching Control
//	00: Right-DAC output selects DAC_R1 path.
//	01: Right-DAC output selects DAC_R3 path to right line output driver.
//	10: Right-DAC output selects DAC_R2 path to right high-power output drivers.
//	11: Reserved. Do not write this sequence to these register bits.
//		upisRegistra(41,0x50);
//		ispisRegistra(41);


// Register 43: Left-DAC Digital Volume Control Register
		upisRegistra(43,0);
		ispisRegistra(43);
		
//Register 44: Right-DAC Digital Volume Control Register
		upisRegistra(44,0);
		ispisRegistra(44);


// Register 82: DAC_L1 to LEFT_LOP/M Volume Control Register
		upisRegistra(82,0x80);
		ispisRegistra(82);
		

		
// Register 91: PGA_R to RIGHT_LOP/M Volume Control Register
//		upisRegistra(91,0x80);
//		ispisRegistra(91);

//Register 92: DAC_R1 to RIGHT_LOP/M Volume Control Register
		upisRegistra(92,0x80);
		ispisRegistra(92);
		
// Register 86: LEFT_LOP/M Output Level Control Register
// 0x08 ili 0x0A   "all programmed gains to LEFT_LOP/M have been applied"??
		upisRegistra(86,0x09);
		ispisRegistra(86);
		
// Register 93: RIGHT_LOP/M Output Level Control Register
// 0x08 ili 0x0A   "all programmed gains to LEFT_LOP/M have been applied"??
		upisRegistra(93,0x09);
		ispisRegistra(93);



}
	else {
					USART_puts(USART2, "Nije spojen\r\n");
					}
	
}