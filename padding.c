#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
	{
	int targetStrLen = 10;           // Target output length  
	const char *myString="1";   // String for output 
	const char *padding="000000000000000000000000000000000000000000000000000000000";

	int padLen = targetStrLen - strlen(myString); // Calc Padding length
	if(padLen < 0) padLen = 0;    // Avoid negative length

	printf("[%*.*s%s]", padLen, padLen, padding, myString);  // LEFT Padding 
	printf("[%s%*.*s]", myString, padLen, padLen, padding);  // RIGHT Padding
	return 0;
	}
	