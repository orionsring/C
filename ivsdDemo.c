/* This is ivsdDemo.c */

#include <stdio.h>

int main (void)
{
	int counter = 123;
	
	printf("The value of counter using %%d is %d\n\n", counter);
	printf("The value of counter using %%i is %i\n\n", counter);

	printf("Enter a new value for counter using %%d ");
	scanf("%d", &counter);
	printf("User entered value of counter is %d\n\n", counter);
	
	printf("Enter a hex value for counter using 0x for hex ");
	scanf("%i", &counter);
	printf("User entered value of counter is %i\n\n", counter);
	
	printf("Enter an octal value for counter using 0 for octal ");
	scanf("%i", &counter);
	printf("User entered value of counter is %i\n\n", counter);
	
	return 0;
}