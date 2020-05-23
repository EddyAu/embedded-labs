//
// Lab 4 - EEET2096
//
// Authors: 
//   Berk Dogan, s3717496
//   Engin Akil, 
//
// Last Modified: 23 May 2020

#include "stm32f439xx.h"


// Global variables are defined here...
int current, humidity;
int light;

bool lightCommandFlag;
bool lightToggleFlag;

int lightCommand;
int lightSwitchStatus;

// ADC interrupt routine

// SysTick interrupt routines

// UART interrupt routines



/**
	Delay function, pass in a number.
*/
void myDelay(long delay) {
	for (long i = 0; i <delay; i++) {
	}
}



int main (void) {	
	// Declaration of local variables
		
	// System configuration - this should include the ADC, serial port and SysTick
	
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

