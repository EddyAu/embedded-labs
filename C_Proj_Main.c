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
	RCC->AHB1ENR |= 1<<7; // enable the AHB clock for port h
	
}


int main (void) {	
	
	int x,y,z, s;
	
	SystemInit();  // Call SystemInit here
	
	// test some simple C statements
	x=2;
	y=5;
	z=x*y;
	
	s= Sum(x, y) ; // test a function call
	
	// test an access to GPIOD registers 
	RCC->AHB1ENR |= 0x000001F8;
	GPIOD->ODR = z;
	
	
	// infinite loop
	for(; ;)
	{;} /* dead loop*/
}