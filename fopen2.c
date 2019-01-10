/*					fopen2.c
*
*					Synopsis - opens a file named info and
* 			closes it.
*
*					Objective - Demonstrates elementary handling
*			with fopen and fclose()
*
*/

/* include files */
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *fp;
	
	if((fp = fopen("info", "r")) == NULL){
	printf("Input file could not be opened\n");
	exit(1);
	}
	
	// other code to process file goes here
	
	
	if(fclose(fp) == EOF)
	printf("The file couldn't close \n");
	
	return 0;
}


	