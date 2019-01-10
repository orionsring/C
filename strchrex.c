/*			strchrex.c
*
* Synopsis - Accetps a line of text as input from standard
*			 input and displays each of the space-delimited
*			 words in the input on a separate line on
*			 standard output.
* Objective - To illustrate the string library function strchr()
*/

/* Include Files */
#include <stdio.h>
#include <string.h>

/* Constant Definitions */
#define BUF_SIZE 512

int main( void )
{
	char instring[BUF_SIZE];
	char *currentpos, *lastpos;
	/* The pointer lastpos will always point to 
	the beginning of the word to be output; currentpos will
	point to the end of the word.*/
	
	printf( "Enter a line of text.\n> ");
	fgets( instring, BUF_SIZE, stdin );			
	/* The buffer instring is initialized by a call to fgets() */
	
	instring[strlen( instring ) - 1 ] = '\0';
	lastpos = instring;
	
	/* The call to strchr() begins its search for a blank character at the 
	memory location pointed to by lastpos. It returns a pointer to the first
	blank character. If no blank is found before the terminating null charac-
	ter, strchr() returns a NULL pointer. In this program, the return of a 
	NULL pointer by strchr() signifies that the whole input line has been
	processed. */
	while ( ( currentpos = strchr( lastpos, ' ' ) ) != NULL) {
		*currentpos++ = '\0';
	/* The blank character found by strchr() is replaced by '\0'. This cre-
	ates a null-terminated string that consists of a single word. The pointer
	lastpos points to the beginning of the word. Note that currentpos 
	is incremented after the assignment so that, theoretically, it points to 
	the beginning of the next word */
		printf( "%s\n", lastpos );
		lastpos = currentpos;
	/*In preparation for another iteration of the while loop, lastpos is 
	updated to point to the beginning of the next word. */
		
	}
	
	printf( "%s\n", lastpos );
	return 0;
}
	