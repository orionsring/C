/*		identchk.c
*
*		Synopsis	-	Prompts for and accepts input of a potential
*			C identifier and reports whether the identifier
*			is legal or not.
*	
*		Objective 	-	To illustrate a use of strspn().
*
*/
/*	Header Files */
#include <stdio.h>
#include <string.h>
/*	Constant Definitions */
#define ID_LGTH 80
#define FALSE 0
#define TRUE 1

/* Function Prototypes */
int id_legal( char id[] );
/* PRECONDITION: id is a null-terminated string.
*  POSTCONDITION: returns TRUE if id is a legal C identifier and
*	FALSE if not.
*
*/

int main()
{
	char identifier[ID_LGTH];
	int retval;
	
	printf( "Enter your identifier: ");
	fgets( identifier, ID_LGTH, stdin );
	identifier[ strlen( identifier ) - 1 ] = '\0';	
	/* The user must press return to enter a potential identifier. The newline 
	('\n') will not be part of the identifier. This line of code replaces the 
	newline with a null character.
	*/
	
	retval = id_legal( identifier );
	
	if ( retval == TRUE )
		printf( "The identifier %s is legal\n", identifier );
	else
		printf( "%s is not a legal identifier.\n", identifier );
	
	return 0;
	}
	
	int id_legal( char id[] )
	{
		char * legal = "abcdefghijklmnopqrstuvwxyz"
		/*
		The legal charaters in a C identifier can be lower case alphabetics, upper
		case alphabetics, digits, or an underscore. The legal characters consist of
		all the characters in the three strings. The underscore is included in the 
		string with the digits. Placing the three strings adjacent in the code 
		creates one string that consists of
		"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"
		These are the legal characters in an identifier.
		*/
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"0123456789_";
		
		char *start = "abcdefghijklmnopqrstuvwxyz"
		/*
		In a method similar to that described in Note 2, the string consisting of
		the legal first characters to an identifier is formed. The first character of a
		C identifier can be either an alphabetic character, either upper or lowercase, 
		or the underscore character.
		*/
		"_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		
		if ( strspn( id, start) >= 1 && strspn( id, legal ) == strlen( id ) )
			return TRUE;
		return FALSE;
		
		