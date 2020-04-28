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
	
	
	// enable the clock	(portb and portf)
	RCC->AHB1ENR |= (1<<1) | (1<<6);
	
	// Setup PORTB
	GPIOB->MODER &= ~(3UL<<4);		//  clear mode bits
	GPIOB->MODER |= 1UL<<4;				// set mode to output
	GPIOB->OTYPER &= ~(1UL<<2);		// select push-pull output
	
	// Setup PORTF
	RCC->AHB2ENR |= RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER &= ~(3UL<<4);		// clear the mode bits
	GPIOF->MODER |= 1UL<<4;				// set the mode to output
	GPIOF->OTYPER &= ~(1UL<<2);		// select push-pull output

	// Main Code
	while (1) {
		
		switch (counter) {
			
			/***************************
			Case 0: Button A and B is pressed
				0b00 = 0
				Both LEDs are off
			*/
			case 0:
				GPIOB->ODR &=(0x00000000); // turn off portb
				GPIOF->ODR &=(0x00000000); // turn off portf
			
				fakeIDR = (GPIOB->IDR) & (GPIOF->IDR);

				break;
			
			/************************
			Case 1: Button A is pressed
				0b01 = 1
				LED6 = OFF, LED7 = ON
			*/
			case 1:
				// led7 on
				GPIOF->ODR |= (1<<8);				// output to turn on LED7 (PF8)
				GPIOB->ODR &= (0x00000000);		// set it all zero
				
				fakeIDR = (GPIOB->IDR) & (GPIOF->IDR);
			
				break;
			
			/*************************
			CASE 2: Button B is pressed
				0b10 = 2
				LED6 = ON, LED7 = OFF
			*/
			case 2:
				// led 6 on
				GPIOF->ODR |= (0x00000000);  // turn off pf8
				GPIOB->ODR &= (1<<8);		// turn on pb8
			
				fakeIDR = (GPIOB->IDR) & (GPIOF->IDR);
				break;
			
			/*
			CASE 3: No button is pressed
				0b11 = 3
				LED 6 = OFF, LED 7 = on/off blinking (1s)
			*/
			case 3:
				// led 6 off, led 7 blinking
				GPIOF->ODR |= (1<<8); // turn on PF8
				GPIOB->ODR &= (0x00000000);		// set it all zero
				myDelay(5); // temporary delay
				GPIOF->ODR &= (0x00000000); // turn off PF8

				fakeIDR = (GPIOB->IDR) & (GPIOF->IDR);
				break;
		}
		counter++; // increment counter to next state
		if (counter == 4) { counter = 0; } // check if it overruns
		fakeIDR=0; // reset fakeIDR value
	}
}