/* Donald Adams 100 076 8238 */

#include <stdio.h>

#define YES 1
#define NO  0 

int main (void)
{
	int Decision;
	
	system("clear");
	
	
	printf("Enter 1 for YES and 0 for NO\n\n");
	
		   	   
	printf("You are ordering from the McDonalds Menu at the Drive Thru\n\n");
	printf("Would you like a burger?");
	scanf("%d", &Decision);
	
	if (Decision == YES)
	{
		printf("\n\nDid you want fries with that?\n\n");
		scanf("%d", &Decision);
		
		if (Decision == YES)
		{
			/* Yes Yes (1 1) */
			printf("Big Mac with Fries!!\n\n");
		}
		else if (Decision == 0)
		{
			/* Yes No (1 0) */
			printf("McDouble!!\n");
		}
		
	}
	else if (Decision == NO)
	{
		/* No (0) */
		printf("\n\nDo you want a chicken sandwich? ");
		scanf("%d", &Decision);
		
		if (Decision == NO)
		{			
			/* No No (0 0) */
			printf("\n\nDo you want a Salad? ");
			scanf("%d", &Decision);
			
			if (Decision == YES)
			{
				/*  No No Yes (0 0 1) */
				printf("\n\nSouthwest Grilled Chicken Salad!!\n\n");
			}
			else
			{
				/* No No No (0 0 0) */
				printf("\n\nIce Cream Cone!!\n\n");
			}
		}
		else
		{
			/* No Yes (0 1) */
			printf("\n\nClassic Chicken Sandwich\n\n");
		}
	}
	else
	{
		printf("\n\n%d is not a valid input - "
		       "enter 0 for NO or 1 for YES.\n", Decision);
	}
	
	return 0;
}

