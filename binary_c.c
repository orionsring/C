/*
*	C program to accept a dcimal number and convert it to binary
* and count the number of 1's in the binary number
*
*/
#include <stdio.h>

int main(void)
{
	long num, decimal_num, remainder, base = 1, binary = 0, no_of_1s = 0;
	
	unsigned short first;
	unsigned short second = 255;
	unsigned short result = 0;
	
	printf("Enter a decimal integer \n");
	scanf("%d", &first);
	
	if ((first > 255)||(first<0)){// makes sure that the arguments given are within range
	
	printf("The argument is out of range, 8 bit unsigned values must be used");
	return 0;
	
}

int i;
for (i=8; i>0; i--)// repeat for all 8 bits
{
	
	if(first & 1){// If "first" is odd, print 1.
		printf("1");
	}
	else
		printf("0");
	
	first = first >> 1;//(shift operator) halves the first argument.
	
	
}
printf("\n\n=======================\n");
printf("\t The product is %d ==\n",result);
printf("=======================\n");

return 0;
	}

