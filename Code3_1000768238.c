/* Coding Assignment 3 */

#include <stdio.h>

/*pseudocode:
prototypes for ConvertDecimalToBinary()
and PrintBinary()
function ConvertDecimalToBinary()
	pass in input decimal number and array to hold binary number (8 cells -  1 for each bit)
	In for loop, use right bitshift to divide by 2
	In for loop, use a bitmask to determine if odd or even and ternary if to assign 1 or 0 to bit array	
*/

/*
function PrintBinary
		Pass in binary number array	
		Use for loop to print out each element of
		binary number array
		
main
		Input loop
			Ask for decimal number to convert
			If entered number is NOT between 0 and 255
			
			Then print "You entered a number NOT between
			0 and 255" and ask for input again
			If entered number is between 0 and 255
			then leave input loop
			
call ConvertDecimalToBinary()
call PrintBinary()
		
*/

/* prototype */
void ConvertDecimalToBinary(int);

void ConvertDecimalToBinary(int DecimalNum)
{
	int bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8;
	int bit[8];
	int i;
	
	bit[7] = DecimalNum;
	
	for(i = 6; i>=0; i--)
	{
	bit[i] = bit[i+1] / 2;
	}
	
	for(i = 0; i <=7; i++)
	{
	bit[i] = (bit[i] % 2) ? 1 : 0;
	}
	
	
	printf("\nDecimal %d converts to binary ", DecimalNum);
	
	for(i = 0; i<=7; i++)
	{
	printf("%d",
	bit[i]);
	}
	return;
}

int main(void)
{
	int DecNum;
	int AskAgain = 1;
	
	printf("Decimal to binary convertor\n\n");
	
	while (AskAgain)
	{
		printf("Please enter a decimal number between 0 and 255 ");
		scanf("%d", &DecNum);
	
		if (DecNum >= 0 && DecNum <= 255)
			AskAgain = 0;
		else
		{
			AskAgain = 1;
			printf("\nYou entered a number not between 0 and 255\n\n");
		}
	}
	
	ConvertDecimalToBinary(DecNum);

	return 0;
}