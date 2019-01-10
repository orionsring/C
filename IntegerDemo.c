/* This is intDemo.c */

#include <stdio.h>

int main (void)
{
	int first, second, third = 789;
	int counter = 123;
	
	printf("The value of counter is %d\n", counter);
	
	counter = 456;
	
	printf("The value of counter is %i\n", counter);

	printf("The value of first %d, second %d, third is %d\n",
	       first, second, third);
	
	first = second = 567;
	third = first;
	
	printf("The value of first %d, second %d, third is %d\n",
	       first, second, third);
	
	return 0;
}
