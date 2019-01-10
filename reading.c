/* reading day */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, int *argv[] )
{
	FILE *fptr;
	char filename[15];
	char dir[15] = {"dir"};
	char ch;
	
	int i,j,k,res,*dest;
	
	
	
	for (i = 0; i < argc; i++)
	{
	if (!memcmp(*(argv + i), "DIRECTION=", 10))
	memcpy(dir, (strchr(*(argv + i), '=') + 1), 10);
	if(dir==NULL)
	perror("\n error: no DIRECTION= argument\n");
	}
	printf("\n dir is: %s \n", dir);
	
	/*open the file for reading*/
	fptr=fopen(dir,"r");
	if(fptr==NULL)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	
	ch=fgetc(fptr);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch = fgetc(fptr);
	}
	fclose(fptr);
	return 0;
}





