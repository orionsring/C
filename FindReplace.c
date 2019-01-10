/*
*
*
*	word replace
*
*/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	
	char *stack[256];
	int stack_depth = 0;
	
	const char *punct = ".,;:!?";
	
	int main(int argc, char **argv)
	{
		char *ptr, *find, *change;
		int i;
		if (argc !=3)
		{
			ptr = strrchr( argv[0], '/');
			if (!ptr)
				ptr = strrchr(argv[0], '\\');
			if (ptr)
				ptr ++;
			else
				ptr = argv[0];
			printf("Usage:%s \"original string \"\" original -->new\"\n",ptr);
			return 0;
		}
		
		ptr = argv[1];
		
		while (* ptr)
		{
			while(*ptr == ' ')
				ptr ++;
			i = 0;
			while(ptr[i])
			{
			//do not store spaces
			if(ptr[i]==' ')
			break;
			i++;
			}
			
			if(i)
			{
			stack[stack_depth] = malloc(i+1);
				if(stack[stack_depth]==NULL)
				{
				printf("oh wow, out of memory \n");
				return -1;
				}
			strncpy(stack[stack_depth], ptr, i);
			stack[stack_depth][i]=0;
			stack_depth++;
			ptr +=i;
			}
		
			if(*ptr && strchr (punct, *ptr))
				{
				i=0;
			while(ptr[i] && strchr (punct, ptr[i]))
			i++;
				stack[stack_depth] = malloc(i+1);
				if(stack[stack_depth] == NULL)
			{
				printf("oh wow, out of memory \n");
				return -1;
			}
				strncpy (stack[stack_depth], ptr, i);
				stack[stack_depth][i] = 0;
				stack_depth++;
				ptr +=i;
				}
		}// end while *ptr
		
		printf("Original String: ");
		for(i=0; i<stack_depth; i++)
		{
			if(i >0 && !strchr(punct, stack[i][0]))
			printf(" ");
			printf("%s", stack[i]);
		}
		printf("\n");
		
		
		/* fetch change words */
		
		ptr = strstr (argv[2], "--> ");
		if(!ptr)
		{
			printf("bad syntax!\n");
			return -1;
		}
		
		/* fetch the length of 'find' */
		i = ptr - argv[2];
		find = malloc(i+1);
		strncpy(find, argv[2],i);
		find[i]=0;
		
		/*fetch the length of 'change' */
		/* this is the 5 characters '-->' after start */
		
		ptr +=5;
		i = strlen(ptr);
		change = malloc(i+1);
		strncpy(change, ptr, i);
		change[i] = 0;
		printf("Word for change: %s --> %s \n",find, change);
		printf("Result: ");
		for(i=0; i< stack_depth; i++)
		{
			if(i>0 && !strchr(punct, stack[i][0]))
				printf(" ");
			if (strcmp(stack[i], find))
				printf("%s", stack[i]);
			else
				printf("%s", change);
		}
		printf("\n");
	}
	
	//endof program
	