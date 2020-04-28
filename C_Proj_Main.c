//
// Lab 3 - EEET2096
//
// Authors: 
//   Berk Dogan, s3717496
//   Engin Akil, 
//
// Last Modified: 28 Aug 2020

#include "stm32f439xx.h"

#define RCC_AHB2ENR_GPIOBEN ((uint32_t)0x0000002u)
#define RCC_AHB2ENR_GPIOFEN ((uint32_t)0x0000002u)



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
		
	int inputVal = 2;
	int fakeIDR, fakeODR;
	
	
	
	
	// Setup PORTB
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // enable the clock
	GPIOB->MODER &= ~(3UL<<4);		//  clear mode bits
	GPIOB->MODER |= 1UL<<4;				// set mode to output
	GPIOB->OTYPER &= ~(1UL<<2);		// select push-pull output
	
	// Setup PORTF
	RCC->AHB2ENR |= RCC_AHB1ENR_GPIOFEN;
	GPIOF->MODER &= ~(3UL<<4);		// clear the mode bits
	GPIOF->MODER |= 1UL<<4;				// set the mode to output
	GPIOF->OTYPER &= ~(1UL<<2);		// select push-pull output
	
	// led6 = pb8
	// led7 = pf8
	
	
	
	// Loop indefinitely
	/*
	Case 1: Button A and B is pressed
		0b00 = 0
		Both LEDs are off
	
	Case 2: Button A is pressed
		0b01 = 1
		LED6 = OFF, LED7 = ON
	
	CASE 3: Button B is pressed
		0b10 = 2
		LED6 = ON, LED7 = OFF
	
	CASE 4: No button is pressed
		0b11 = 3
		LED 6 = OFF, LED 7 = on/off blinking (1s)
	
	*/
	while (1) {
		// 0 = case1, 1 = case2, 2 = case3, 3 = case4
		switch (inputVal) {
			case 0:
				fakeIDR = GPIOB->IDR;

				
				break;
			
			case 1:
				// led7 on
			  GPIOF->ODR |= 1UL << 8;				// output to turn on LED7 (PF8)
				fakeIDR = GPIOF->IDR;
				break;
			
			case 2:
				// led 6 on
			  GPIOB->ODR |= 1UL << 8;				// output to turn on LED6 (PB8)
				fakeIDR = GPIOB->IDR;
				break;
			
			case 3:
				// led 6 off, led 7 blinking
				GPIOF->ODR |= 1UL << 8;
				fakeIDR = GPIOF->IDR;
				//myDelay(1000); // delay
				break;
		}
	
	}
}