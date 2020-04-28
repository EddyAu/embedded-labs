//
// Lab 3 - EEET2096
//
// Authors: 
//   Berk Dogan, s3717496
//   Engin Akil, 
//
// Last Modified: 28 Aug 2020

#include "stm32f439xx.h"



int Sum( int a, int b) { 
	int c;
	c=a+b;
	return c;
}

/**
	Delay function, pass in a number.
*/
void myDelay(long delay) {
	for (long i = 0; i <delay; i++) {
	}
}


int main (void) {	
		
	int counter = 0;
	int fakeIDR = 0;
	int buttonRead;
	
	
	// enable the clock	(portb and portf)
	RCC->AHB1ENR |= (1<<1) | (1<<6);
	
	// Setup the mode register for output (portb0)
	GPIOB->MODER |= GPIO_MODER_MODER0_0;
	GPIOB->MODER &= ~(GPIO_MODER_MODER0_1);
	// Setup the mode register for output (portb1)
	GPIOB->MODER |= GPIO_MODER_MODER1_0;
	GPIOB->MODER &= ~(GPIO_MODER_MODER1_1);
	
	// Output type register
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT0);
	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT1);
	
	// Speed
	//GPIOB->OSPEEDR |= GPIO_OSPEEDR_OSPEEDR0_0 | GPIO_OSPEEDR_OSPEEDR0_1;
	

	// Main Code
	while (1) {
		
		if ((counter % 10) == 0)
			fakeIDR++;
		
		buttonRead = GPIOB->IDR; 		// real read of button A & B
		buttonRead = fakeIDR & 0x3;	// mask the rest of the bits, keep the last two bits
		
		switch (buttonRead) {
						
			case 0x0:
				// buttons 0,0
				// led 6 off, led 7 off
				GPIOB->ODR |= (1<<8);
				GPIOF->ODR |= (1<<8);
				break;
			
			
			case 0x1:
				// buttons 0,1
				// led 6 off, led 7 on
				GPIOB->ODR |= (1<<8);
				GPIOF->ODR &= ~(1<<8);
				break;
			
			case 0x2:
				// buttons 1,0
				// led 6 on, led 7 off
				GPIOB->ODR &= ~(1<<8);
				GPIOF->ODR |= (1<<8);
				break;
			
			
			case 3:
				// buttons 1,1
				// led 6 off, led 7 on (flashing)
				GPIOB->ODR |= (1<<8);
				GPIOF->ODR &= ~(1<<8);
				myDelay(10); // wait 10 units
				GPIOF->ODR |= (1<<8);


		}
		counter++; // increment counter
	}
}