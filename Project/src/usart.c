#include "usart.h"

volatile char received_string[MAX_STRLEN+1]; // this will hold the recieved string
volatile char received_string2[MAX_STRLEN+1]; // this will hold the recieved string
volatile int newData=0;
volatile	int variables[numOfVariables];
volatile	int parameter[numOfParameters];

void Delay(__IO uint32_t nCount) {
  while(nCount--) {
  }
}


/* This funcion initializes the USART1 peripheral
 * 
 * Arguments: baudrate --> the baudrate at which the USART is 
 * 						   supposed to operate
 */
void init_USART1(uint32_t baudrate){
	
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the USART1 initilization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOB, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_USART1); //
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_USART1);
	
	USART_InitStruct.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART1, &USART_InitStruct);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
	

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART1 receive interrupt 
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;		 // we want to configure the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART1 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART1 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	

	USART_Cmd(USART1, ENABLE);
}

void init_USART2(uint32_t baudrate){

	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure; 
	
 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
 GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2);
 GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2);


 USART_InitStructure.USART_BaudRate = baudrate;
 USART_InitStructure.USART_WordLength = USART_WordLength_8b;
 USART_InitStructure.USART_StopBits = USART_StopBits_1;
 USART_InitStructure.USART_Parity = USART_Parity_No;
 USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
 USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;;
 USART_Init(USART2, &USART_InitStructure);

 
 	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;		 // we want to configure the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART6 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	
	
 
 USART_Cmd(USART2, ENABLE); 

}



void init_USART3(uint32_t baudrate){
	
	
	

	
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the USART6 initilization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9; // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_USART3);
	
	USART_InitStruct.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART6, &USART_InitStruct);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
	
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE); // enable the USART6 receive interrupt 
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;		 // we want to configure the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART6 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	

	USART_Cmd(USART3, ENABLE);
}


void init_USART6(uint32_t baudrate){
	
	
	

	
	/* This is a concept that has to do with the libraries provided by ST
	 * to make development easier the have made up something similar to 
	 * classes, called TypeDefs, which actually just define the common
	 * parameters that every peripheral needs to work correctly
	 * 
	 * They make our life easier because we don't have to mess around with 
	 * the low level stuff of setting bits in the correct registers
	 */
	GPIO_InitTypeDef GPIO_InitStruct; // this is for the GPIO pins used as TX and RX
	USART_InitTypeDef USART_InitStruct; // this is for the USART6 initilization
	NVIC_InitTypeDef NVIC_InitStructure; // this is used to configure the NVIC (nested vector interrupt controller)
	
	/* enable APB2 peripheral clock for USART6 
	 * note that only USART1 and USART6 are connected to APB2
	 * the other USARTs are connected to APB1
	 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6, ENABLE);
	
	/* enable the peripheral clock for the pins used by 
	 * USART6, PC6 for TX and PC7 for RX
	 */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	/* This sequence sets up the TX and RX pins 
	 * so they work correctly with the USART6 peripheral
	 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; // Pins 6 (TX) and 7 (RX) are used
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF; 			// the pins are configured as alternate function so the USART peripheral has access to them
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;		// this defines the IO speed and has nothing to do with the baudrate!
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;			// this defines the output type as push pull mode (as opposed to open drain)
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;			// this activates the pullup resistors on the IO pins
	GPIO_Init(GPIOC, &GPIO_InitStruct);					// now all the values are passed to the GPIO_Init() function which sets the GPIO registers
	
	/* The RX and TX pins are now connected to their AF
	 * so that the USART6 can take over control of the 
	 * pins
	 */
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_USART6);
	
	/* Now the USART_InitStruct is used to define the 
	 * properties of USART6
	 */
	USART_InitStruct.USART_BaudRate = baudrate;				// the baudrate is set to the value we passed into this init function
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;// we want the data frame size to be 8 bits (standard)
	USART_InitStruct.USART_StopBits = USART_StopBits_1;		// we want 1 stop bit (standard)
	USART_InitStruct.USART_Parity = USART_Parity_No;		// we don't want a parity bit (standard)
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None; // we don't want flow control (standard)
	USART_InitStruct.USART_Mode = USART_Mode_Tx | USART_Mode_Rx; // we want to enable the transmitter and the receiver
	USART_Init(USART6, &USART_InitStruct);					// again all the properties are passed to the USART_Init function which takes care of all the bit setting
	
	
	/* Here the USART6 receive interrupt is enabled
	 * and the interrupt controller is configured 
	 * to jump to the USART6_IRQHandler() function
	 * if the USART6 receive interrupt occurs
	 */
	USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART6 receive interrupt 

	
	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;		 // we want to configure the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;// this sets the priority group of the USART6 interrupts
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;		 // this sets the subpriority inside the group
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			 // the USART6 interrupts are globally enabled
	NVIC_Init(&NVIC_InitStructure);							 // the properties are passed to the NVIC_Init function which takes care of the low level stuff	

	// finally this enables the complete USART6 peripheral
	USART_Cmd(USART6, ENABLE);
}
/* This function is used to transmit a string of characters via 
 * the USART specified in USARTx.
 * 
 * It takes two arguments: USARTx --> can be any of the USARTs e.g. USART1, USART2 etc.
 * 						   (volatile) char *s is the string you want to send
 * 
 * Note: The string has to be passed to the function as a pointer because
 * 		 the compiler doesn't know the 'string' data type. In standard
 * 		 C a string is just an array of characters
 * 
 * Note 2: At the moment it takes a volatile char because the received_string variable
 * 		   declared as volatile char --> otherwise the compiler will spit out warnings
 * */
void USART_puts(USART_TypeDef* USARTx, volatile char *s){

	while(*s){
		// wait until data register is empty
		while( !(USARTx->SR & 0x00000040) ); 
		USART_SendData(USARTx, *s);
		*s++;
	}
}


// this is the interrupt request handler (IRQ) for ALL USART1 interrupts
void USART1_IRQHandler(void){
	
	
	if(newData == 0) {		
		// check if the USART6 receive interrupt flag was set
		if( USART_GetITStatus(USART1, USART_IT_RXNE) ) {
		
			static uint8_t cnt = 0; // this counter is used to determine the string length
			char t = USART1->DR; // the character from the USART6 data register is saved in t
			int i;
			
			int IRQvariables[numOfVariables]={0};
			int IRQparameter[numOfParameters]={0};
			char str[200];

			/* check if the received character is not the LF character (used to determine end of string) 
			* or the if the maximum string length has been been reached 
			*/
			if( (t != '\n') && (cnt < MAX_STRLEN) ){ 
				received_string[cnt] = t;
				str[cnt]=t;
				cnt++;
			}
			else { // otherwise reset the character counter and print the received string
				received_string[cnt] = '\n';
				str[cnt]='\n';
				cnt = 0;
				
				USART_ITConfig(USART1, USART_IT_RXNE, DISABLE); // enable the USART1 receive interyrupt 
				
				newData = 1;
		
				//buffer clean	
				for(i=0;i<MAX_STRLEN;i++)
					received_string[i]=0;
				
				USART_puts(USART6, str);
				
		sscanf(str, "%d %d %d %d %d %d %d %d %d %d %d %d", 
			&IRQvariables[0], &IRQvariables[1], &IRQvariables[2], &IRQvariables[3], &IRQvariables[4],
		&IRQvariables[5], &IRQparameter[0], &IRQparameter[1], &IRQparameter[2], &IRQparameter[3], &IRQparameter[4], &IRQparameter[5]);		
		
	
		
		
			sprintf(str, "\r\n IRQvariables[0]=%d , IRQvariables[1]=%d , IRQvariables[2]=%d , IRQvariables[3]=%d , IRQvariables[4]=%d , IRQvariables[5]=%d  \r\n",
		IRQvariables[0], IRQvariables[1], IRQvariables[2], IRQvariables[3], IRQvariables[4],IRQvariables[5]);
		USART_puts(USART6, str);	
		sprintf(str, "\r\n IRQparameter[0]=%d , IRQparameter[1]=%d , IRQparameter[2]=%d , IRQparameter[3]=%d , IRQparameter[4]=%d , IRQparameter[5]=%d  \r\n",
		IRQparameter[0], IRQparameter[1], IRQparameter[2], IRQparameter[3], IRQparameter[4], IRQparameter[5]);
		USART_puts(USART6, str);	
		
		
		variables[0]=IRQvariables[0];
		parameter[0]=IRQvariables[0];
		variables[1]=IRQvariables[1];
		parameter[1]=IRQparameter[1];
		variables[2]=IRQvariables[2];
		parameter[2]=IRQparameter[2];
		variables[3]=IRQvariables[3];
		parameter[3]=IRQparameter[3];
		variables[4]=IRQvariables[4];
		parameter[4]=IRQparameter[4];
		variables[5]=IRQvariables[5];
		parameter[5]=IRQparameter[5];
		
		sprintf(str, "\r\n variables[0]=%d , variables[1]=%d , variables[2]=%d , variables[3]=%d , variables[4]=%d , variables[5]=%d  \r\n",
		variables[0], variables[1], variables[2], variables[3], variables[4],variables[5]);
		USART_puts(USART6, str);	
		sprintf(str, "\r\n parameter123[0]=%d , parameter[1]=%d , parameter[2]=%d , parameter[3]=%d , parameter[4]=%d , parameter[5]=%d  \r\n",
		parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], parameter[5]);
		USART_puts(USART6, str);	
		
	//buffer clean	
				for(i=0;i<MAX_STRLEN;i++)
					str[i]=0;
		newData=0;
		USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); // enable the USART6 receive interrupt 
	
			}
		}
	}
}


void USART6_IRQHandler(void){
	
	if(newData == 0) {		
		// check if the USART6 receive interrupt flag was set
		if( USART_GetITStatus(USART6, USART_IT_RXNE) ) {
		
			static uint8_t cnt = 0; // this counter is used to determine the string length
			char t = USART6->DR; // the character from the USART6 data register is saved in t
			int i;
			int IRQvariables[numOfVariables]={0};
			int IRQparameter[numOfParameters]={0};
			char str[200];
			
			/* check if the received character is not the LF character (used to determine end of string) 
			* or the if the maximum string length has been been reached 
			*/
			if( (t != '\n') && (cnt < MAX_STRLEN) ){ 
				received_string[cnt] = t;
				received_string2[cnt]=t;
				cnt++;
			}
			else { // otherwise reset the character counter and print the received string
				received_string[cnt] = '\n';
				received_string2[cnt] = '\n';
				cnt = 0;
				
				USART_ITConfig(USART6, USART_IT_RXNE, DISABLE); // enable the USART1 receive interyrupt 
				
				newData = 1;
		
				//buffer clean	
				for(i=0;i<MAX_STRLEN;i++)
					received_string[i]=0;
				
				USART_puts(USART6, received_string2);
				
		sscanf((const char *)received_string2, "%d %d %d %d %d %d %d %d %d %d %d %d", 
			&IRQvariables[0], &IRQvariables[1], &IRQvariables[2], &IRQvariables[3], &IRQvariables[4],
		&IRQvariables[5], &IRQparameter[0], &IRQparameter[1], &IRQparameter[2], &IRQparameter[3], &IRQparameter[4], &IRQparameter[5]);		
		
		
	
		
			sprintf(str, "\r\n IRQvariables[0]=%d , IRQvariables[1]=%d , IRQvariables[2]=%d , IRQvariables[3]=%d , IRQvariables[4]=%d , IRQvariables[5]=%d  \r\n",
		IRQvariables[0], IRQvariables[1], IRQvariables[2], IRQvariables[3], IRQvariables[4],IRQvariables[5]);
		USART_puts(USART6, str);	
		sprintf(str, "\r\n IRQparameter[0]=%d , IRQparameter[1]=%d , IRQparameter[2]=%d , IRQparameter[3]=%d , IRQparameter[4]=%d , IRQparameter[5]=%d  \r\n",
		IRQparameter[0], IRQparameter[1], IRQparameter[2], IRQparameter[3], IRQparameter[4], IRQparameter[5]);
		USART_puts(USART6, str);	
//
	for (i=0;i<6;i++)
		{
		variables[i]=IRQvariables[i];
		parameter[i]=IRQparameter[i];
		}
		
		sprintf(str, "\r\n variables[0]=%d , variables[1]=%d , variables[2]=%d , variables[3]=%d , variables[4]=%d , variables[5]=%d  \r\n",
		variables[0], variables[1], variables[2], variables[3], variables[4],variables[5]);
		USART_puts(USART6, str);	
		sprintf(str, "\r\n parameter[0]=%d , parameter[1]=%d , parameter[2]=%d , parameter[3]=%d , parameter[4]=%d , parameter[5]=%d  \r\n",
		parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], parameter[5]);
		USART_puts(USART6, str);	
		
		//buffer clean
		for(i=0;i<MAX_STRLEN;i++)  
			received_string2[i]=0;
		newData=0;
		USART_ITConfig(USART6, USART_IT_RXNE, ENABLE); // enable the USART6 receive interrupt 
	
			}
		}
	}
}




void USART2_IRQHandler(void){
	
	
	if(newData == 0) {		
		// check if the USART6 receive interrupt flag was set
		if( USART_GetITStatus(USART2, USART_IT_RXNE) ) {
		
			static uint8_t cnt = 0; // this counter is used to determine the string length
			char t = USART2->DR; // the character from the USART6 data register is saved in t
			int i;
			
			int IRQvariables[numOfVariables]={0};
			int IRQparameter[numOfParameters]={0};
			char str[200];

			/* check if the received character is not the LF character (used to determine end of string) 
			* or the if the maximum string length has been been reached 
			*/
			if( (t != '\n') && (cnt < MAX_STRLEN) ){ 
				received_string[cnt] = t;
				str[cnt]=t;
				cnt++;
			}
			else { // otherwise reset the character counter and print the received string
				received_string[cnt] = '\n';
				str[cnt]='\n';
				cnt = 0;
				
				USART_ITConfig(USART2, USART_IT_RXNE, DISABLE); // enable the USART1 receive interyrupt 
				
				newData = 1;
		
				//buffer clean	
				for(i=0;i<MAX_STRLEN;i++)
					received_string[i]=0;
				
				USART_puts(USART2, str);
				
		sscanf(str, "%d %d %d %d %d %d %d %d %d %d %d %d", 
			&IRQvariables[0], &IRQvariables[1], &IRQvariables[2], &IRQvariables[3], &IRQvariables[4],
		&IRQvariables[5], &IRQparameter[0], &IRQparameter[1], &IRQparameter[2], &IRQparameter[3], &IRQparameter[4], &IRQparameter[5]);		
		
	
		
		
			sprintf(str, "\r\n IRQvariables[0]=%d , IRQvariables[1]=%d , IRQvariables[2]=%d , IRQvariables[3]=%d , IRQvariables[4]=%d , IRQvariables[5]=%d  \r\n",
		IRQvariables[0], IRQvariables[1], IRQvariables[2], IRQvariables[3], IRQvariables[4],IRQvariables[5]);
		USART_puts(USART2, str);	
		sprintf(str, "\r\n IRQparameter[0]=%d , IRQparameter[1]=%d , IRQparameter[2]=%d , IRQparameter[3]=%d , IRQparameter[4]=%d , IRQparameter[5]=%d  \r\n",
		IRQparameter[0], IRQparameter[1], IRQparameter[2], IRQparameter[3], IRQparameter[4], IRQparameter[5]);
		USART_puts(USART2, str);	
		
		
		variables[0]=IRQvariables[0];
		parameter[0]=IRQparameter[0];
		variables[1]=IRQvariables[1];
		parameter[1]=IRQparameter[1];
		variables[2]=IRQvariables[2];
		parameter[2]=IRQparameter[2];
		variables[3]=IRQvariables[3];
		parameter[3]=IRQparameter[3];
		variables[4]=IRQvariables[4];
		parameter[4]=IRQparameter[4];
		variables[5]=IRQvariables[5];
		parameter[5]=IRQparameter[5];
		
		sprintf(str, "\r\n variables[0]=%d , variables[1]=%d , variables[2]=%d , variables[3]=%d , variables[4]=%d , variables[5]=%d  \r\n",
		variables[0], variables[1], variables[2], variables[3], variables[4],variables[5]);
		USART_puts(USART2, str);	
		sprintf(str, "\r\n parameter123[0]=%d , parameter[1]=%d , parameter[2]=%d , parameter[3]=%d , parameter[4]=%d , parameter[5]=%d  \r\n",
		parameter[0], parameter[1], parameter[2], parameter[3], parameter[4], parameter[5]);
		USART_puts(USART2, str);	
		
	//buffer clean	
				for(i=0;i<MAX_STRLEN;i++)
					str[i]=0;
		newData=0;
		USART_ITConfig(USART2, USART_IT_RXNE, ENABLE); // enable the USART2 receive interrupt 
	
			}
		}
	}
}

