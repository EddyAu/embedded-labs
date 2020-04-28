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

/**
	System Initialisation Function
*/
void SystemInit(void) {
	
	
}

/*
GPIOx_ODR - output data register
GPIOx_IDR - input data register

// TASKS (MAIN):
	* PORTs configuration
	* Read data from input pins
	* Write data to output pins

// TASKS (SIMULATOR):
	* Use fakeIDR as input data
	* Use variables to store output values

// Summary:
	* Use Button A (PB0) and Button B (PB1) to control two LEDs
		LED 6 (PB8) and LED 7 (PF8)
*/
int main (void) {	
	
	int dataRead, dataOutput;  // Used for storing and sending data
	
	int buttonA;		// Button A, by default set to "0"
	int buttonB; 		// Button B, by default set to "0"
	int led6;				// LED6 = PB8
	int led7;				// LED7 = PF8
	
	
	//SystemInit();  // Call SystemInit here (comment out for simulator)
	
	RCC->AHB1ENR |= 1<<7;
	GPIOB->IDR = dataRead;
	GPIOB->ODR = dataOutput;
	
	// CASE 1: No button is pressed
	if ((buttonA == 0) && (buttonB == 0)){
		// LED6 = OFF
		// LED7 = blinks 1s interval
	}
	
	// CASE 2: Button A is pressed
	else if ((buttonA == 1)&& (buttonB == 0)){
		// Turn LED7 on, LED6 stays off
	}
	
	// CASE 3: Button B is pressed
	else if ((buttonA == 0)&& (buttonB == 1)) {
		// Turn LED6 on, LED7 stays off
	}
	
	// CASE 4: Both buttons are pressed
	else {
		// All LEDs are off
	}
	
	
	
	
	// infinite loop
	for(; ;)
	{;} /* dead loop*/
}