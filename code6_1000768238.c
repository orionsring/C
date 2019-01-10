/*code 6_1000768238.c */



/* Header Files */
#include "MyLib.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>




int main()	
/*
Create code6_xxxxxxxxxx.c. This program will be use to exercise the library functions that you will create as part of this assignment. This program will display a menu where each menu item will be one of your library functions in MyLib.c.
	1.	Convert Decimal to Binary
	2.	Sentence Cleanup
	3.	SKU Converter
	4.  (bonus) SKU Dasher
	
	Enter menu choice
*/

{
	system("clear");
	int choice;
	char OutputArray[256] = {};
	
	printf("Enter a number.\n");
	printf("\t1. Convert Decimal to Binary\n");
	printf("\t2. Sentence Cleanup\n");
	printf("\t3. SKU Converter\n");
	printf("\t4. SKU Dasher \n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
		
		ConvertDecimalToBinary(*OutputArray);
		
		break;
		
		case 2:
	
	
		SentenceCleanup(*OutputArray);
	
	
		break;
		
		case 3:
		
		SKUConverter(*OutputArray);
		
		break;
		
		
		case 4:
		SKUDasher(*OutputArray);
		break;
		
		
		default:
		
		
		printf("\n\tYou did not enter a valid menu number.\n");
	
	}
	return 0;
}



/*
Code6_xxxxxxxxxxxx.c will not contain any of the code for these functions - they will only be called and the output will be printed. Use a switch statement to create the menu. Remember to use a default statement in case a menu choice is entered that is not valid.

*/
