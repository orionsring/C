/* cODING aSSIGNMENT 5 */
// dONALD aDAMS 1000768238
#include <stdio.h>
#include "MyLib.h"
//#include "MyLib.c"



int main(void)
{
	int DecNum;
	int AskAgain = 1;
	int BinaryNumber[8];
	
	printf("Decimal to binary convertor\n\n");
	
	while(AskAgain)
	{
		printf("Please enter a decimal number between 0 and 255 ");
		scanf("%d", &DecNum);
		
		if(DecNum >= 0 && DecNum <= 255)
			AskAgain = 0;
		else
		{
			AskAgain = 1;
			printf("\nYou entered a number not between 0 and 255\n\n");
		}
	}
	
	ConvertDecimalToBinary(DecNum, BinaryNumber);
	
	PrintBinary(BinaryNumber);
	
	return 0;
	
}


