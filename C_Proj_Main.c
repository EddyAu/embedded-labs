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
	
	int inputVal = 0;
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
	
	
	//SystemInit();  // Call SystemInit here (comment out for simulator)
	
	RCC->AHB1ENR |= 1<<7;
	GPIOB->IDR = dataRead;
	GPIOB->ODR = dataOutput;
	
	// Loop indefinitely
	while (1) {
		switch (inputVal) {
			case 0:
				// both leds off
				break;
			
			case 1:
				// led7 on
				break;
			
			case 2:
				// led 6 on
				break;
			
			case 3:
				// led 6 off, led 7 blinking
				break;
	}
	
	
}