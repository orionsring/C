
/*
*  Donald Adams
*  Code2_1000768238.c 
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int ConvertDecimalToBinary(int n);
void main()
{
	int a =1, i =0, n= 0;
	while(a)
	{
		printf("\nDecimal value is not within range of 0 - 255\n");		
		printf("Enter decimal number: \n");
		scanf("%d", &n);		
		if ((n>=0)&&(n<=255))
		{
			printf("\nvalue entered %d \n",n);
			a=0;
		}
	}
	
	printf("\n\n\t= %08d in binary", ConvertDecimalToBinary(n));
	return;
	
}

int ConvertDecimalToBinary(int n)
{
	int rem, i=1, binary =0;
	while (n!=0)
	{
		rem=n%2;
		n=n/2;
		binary = binary+rem*i;
		i=i*10;
	}
	return binary;
}