/* my test C Program */

#include "stm32f439xx.h"


int Sum( int a, int b)  // a simple function for testing
{ int c;
	c=a+b;
	return c;
}


int main ( void)
{	
	
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
	

	for(; ;)
	{;} /* dead loop*/
}