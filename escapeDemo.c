/* Demonstration of escape characters */

#include <stdio.h>

void DemoTab(void)
{
	printf("This\tis\ta\tdemo\tof\tTAB\n\n\n");
}

void DemoBackspace(void)
{
	printf("This\bis\ba\bdemo\bof\bBACKSPACE\n\n\n");
}

void DemoDoubleQuote(void)
{
	printf("This\"is\"a\"demo\"of\"DOUBLEQUOTE\n\n\n");
}

void DemoSingleQuote(void)
{
	printf("This\'is\'a\'demo\'of\'SINGLEQUOTE\n\n\n");
}

void DemoBackSlash(void)
{
	printf("This\\is\\a\\demo\\of\\BACKSLASH\n\n\n");
}

void DemoNull(void)
{
	printf("This\007is\007a\007demo\007of\007NULL+BEL\n\n");
}

int main (void)
{
	DemoTab(); 
	DemoBackspace();
	DemoDoubleQuote();
	DemoSingleQuote();
	DemoBackSlash();
	DemoNull();
	
	return 0;
}