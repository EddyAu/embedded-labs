//
// Lab 4 - EEET2096
//
// Authors: 
//   Berk Dogan, s3717496
//   Engin Akil, 
//
// Last Modified: 23 May 2020

#include "stm32f439xx.h"
#include <stdio.h>
#include <stdbool.h>


/****************************
General variables
****************************/
int current_humidity;
int light;
bool lightStatus; // might use these to show that the fan is working or not
bool fanStatus;		// same for fan
/***********************************
UART SETUP
	- Refer to tutorial 8, slide 9 for UART receiving interrupt. 
	- Slide 7 for Tx.
*/
char rx_array[2];				// AAAAA
int rx_index;						// USED FOR RECEIVING
int nextByteIsCmdFlag;	// detecting if a command is coming from the UART
bool lightCommandFlag; 	// set if a light command is received
bool lightCommand;			// light command 1 or 0
bool fanCommandFlag;		// set if fan command is received
bool fanCommand;				// fan command 1 or 0

char tx_array[3];				// for transmission
int tx_index = 0;				
bool tx_finished = false;

/****************************
ADC IRQ Handler
****************************/
void ADC_IRQHandler() {
	
	if (ADC1->SR & (1<<1)) {
		// If EoC, then read the ADV value
		current_humidity = ADC1->DR;	// Read the ADC
		ADC1->SR &=(1<<1); 						// Apparently not necessary
		
	}
	// check if the interrupt is triggered by ADC watch dog
	// ... see tutorial 7, page 8,9
	
}


// SysTick interrupt routines



/****************************
USART IRQ Receive (Rx)
****************************/
void USART6_IRQHandler_Rx() {
	char header=0xAD;
	char rx_char;
	
	if (USART6->SR & ((1<<5)==1)) {
		// if the RXD register is full
		rx_char = USART6->DR; // rx_char has received the byte
		
		if (rx_char == header) {
			rx_index = 0;
			rx_array[rx_index] = rx_char;
			rx_index++; // move to next position
			nextByteIsCmdFlag = 1;
		}
		else {
			if (nextByteIsCmdFlag) {
				// the following byte is part of a command
				
				rx_array[rx_index] = rx_char;
				rx_index++;
				
				if (rx_index == 2) {
					// since the full command is received, setup the command flags and commands...
					// ...
					
					rx_index = 0;
					nextByteIsCmdFlag = 0;
				}
			}
			
		}
		
		
	}
	
}


/****************************
USART IRQ Transmission (Tx)
****************************/
void USART6_IRQHandler_Tx() { 
	
	if (USART6->SR & ((1<<7)==0)) {
		// if TXD register is empty
		USART6->DR = tx_array[tx_index]; // transmit 1 byte!
		tx_index++;	// move ot next byte!
		
		if(tx_index == 3) {
			tx_finished = true;
			tx_index = 0;
		}
	}
	
}
/****************************
USART IRQ Transmission (Tx)
****************************/
void myDelay(long delay) {
	for (long i = 0; i <delay; i++) {
	}
}



int main (void) {	
	// Declaration of local variables
		
	// System configuration - this should include the ADC, serial port and SysTick
	
	RCC->AHB1ENR |= (1<<5) | (1<<2) | (1<<1) | (1<<0); //enable clock for portf, portc, portb and porta
	RCC_APB2ENR |= (1 << 5); // Enable Usart6 clock
	
	GPIOB->MODER = (1<<8); // PB8 for portb set output 01  
	GPIOF->MODER = (1<<8); // PB8 for portf set output 01
	
	
	
	GPIOB->OTYPER = (GPIOB->OTYPER & GPIO_OTYPER_OT8);
	GPIOF->OTYPER = (GPIOF->OTYPER & GPIO_OTYPER_OT8);
	
	GPIOB->OSPEEDR = (GPIO_OSPEEDR_OSPEED0_0) | (GPIO_OSPEEDR_OSPEED1_0) | (GPIO_OSPEEDR_OSPEED8_0) ;
	
	GPIOF->OSPEEDR = (GPIO_OSPEEDR_OSPEED8_0);
	//GPIOB->OSPEEDR=0x10005;
	//GPIOF->OSPEEDR=0x10000;
	
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPD0_0|GPIO_PUPDR_PUPD0_1); // set to 00: No pull-up, pull-down
	//GPIOB->PUPDR=0x00;
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPD0_0|GPIO_PUPDR_PUPD0_1); // set to 00: No pull-up, pull-down
	//GPIOF->PUPDR=0x00;
	
	
	
	while(1){
		
		/*
		Check if the light command flag is set.
			IF TRUE, execute command from UART
			ELSE, check if the light toggle flag is set
				IF TRUE, toggle light
		
		Clear light command flag
		Clear light toggle flag
		.....
		.....
		Check if the fan command flag is set
			IF TRUE, execute the command from UART
			ELSE check if the fan toggle flag is set
				IF YES, toggle the fan
			
		Clear fan command flag
		Clear fan toggle flag
		
		
		*/
		
	}
}

