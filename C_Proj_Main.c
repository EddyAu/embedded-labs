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
	
	int dataRead, dataOutput;  
	int buttonA, buttonB; 		// Buttons
	int led6, led7;						// LEDs
	
	//SystemInit();  // Call SystemInit here (comment out for simulator)
	RCC->AHB1ENR |= 1<<7;
	GPIOB->IDR = dataRead;
	GPIOB->ODR = dataOutput;
	
	
	
	// infinite loop
	for(; ;)
	{;} /* dead loop*/
}