#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int fnintcmp(const void *a, const void *b)
{
	return 0;
}

void main(void)
{
	int intarray[5] = {19, 375, 60, 8916, 7354};
	qsort(intarray, 5, sizeof(int),fnintcmp);
	printf("%d", intarray[2]);
	
	
}


