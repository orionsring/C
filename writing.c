#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 256
#define MAPSIZE 10	
void get_command_line_parameters();
void initialize();
int  movenorth(); int movesouth(); int moveeast(); int movewest();
struct RowCol{
	int row;
	int col;
};
FILE *TreasureMap;
FILE *DirectionFile;
char MAP[MAPSIZE][MAPSIZE];
char ch='a';
char filename[LEN];
char DirectionFilename[20] = {};
char MapFilename[20]       = {};
int main(int argc, char *argv[])
{
	//initialize();	
int i= 1; int j,k,res,makemove;
struct RowCol *Position=(struct RowCol *)malloc(1*sizeof(struct RowCol));

Position->row = 0;
Position->col = 0;
MAP[Position->row][Position->col] = 'S';
get_command_line_parameters(argc,argv);	

do{
	
			//ch=getc(DirectionFile);//tokenize iostream
			printf("Row:%d\tCol:%d\n",Position->row,Position->col);
			
			if(ch=='N'){
				movenorth(Position);
				
		}else{
			if(ch=='S'){
				movesouth(Position);
		}else{	
			if(ch=='E'){
				moveeast(Position);
		}else{
			if(ch=='W'){
				movewest(Position);
		}
		}
		}
		}
			if(ch==EOF){fprintf(TreasureMap,"X",i); break;}
		}while((ch=getc(DirectionFile))!=EOF);

	/*close the file */
	fclose(TreasureMap);
	fclose(DirectionFile);
	return 0;
}

void get_command_line_parameters(int argc, char *argv[]){
	int i, j, k;
	for (i = 0; i < argc; i++)
	{
	if (!memcmp(*(argv + i), "DIRECTION=", 10))
	memcpy(DirectionFilename, (strchr(*(argv + i), '=') + 1), 10);
	if(DirectionFilename==NULL){perror("\n error: no DIRECTION= argument\n"); exit(1);}
	if (!memcmp(*(argv + i), "MAP=", 4))
	memcpy(MapFilename,   (strchr(*(argv + i), '=') + 1), 4 );
	if(MapFilename==NULL){perror("\n error: no MAP= argument\n"); exit(2);}
	}
	printf("\n DirectionFilename is: %s \n", DirectionFilename);
	printf("\n MapFilename is: %s \n", MapFilename);
	
	DirectionFile = fopen(DirectionFilename,"r");
	TreasureMap = fopen(MapFilename,"w");
}
void initialize()
{
	int i,j;
	for(i=1;i<MAPSIZE;i++){
		for(j=1;j<MAPSIZE;j++){
			fprintf(TreasureMap,"-",MAPSIZE); 
		}
	}
}


int moveeast(struct RowCol *ptr){
	int i;
	if(ptr->col < (MAPSIZE-1)) {
		ptr->col=(ptr->col)+1;
		for(i=0; i<MAPSIZE; i++)
		{
					if((ptr->col)==i)
					{
						fprintf(TreasureMap,"E",MAPSIZE);
						printf("X");
					}
					else
					{
						fprintf(TreasureMap,"-",MAPSIZE);
						printf("-");
					}
		}
		printf("\n");
		return 1;
		}
	return 0;
}
int movewest(struct RowCol *ptr){
	int i;
	if(ptr->col >0){
		ptr->col=(ptr->col)-1;
		
		for(i=0; i<MAPSIZE; i++)
		{
					if((ptr->col)==i)
					{
						fprintf(TreasureMap,"W",MAPSIZE);
						printf("X");
					}
					else
					{
						fprintf(TreasureMap,"-",MAPSIZE);
						printf("-");
					}
		}
		printf("\n");
		return 1;
		}
return 0;
}
int movesouth(struct RowCol *ptr){
	int i;
	if(ptr->row <9){
		ptr->row=(ptr->row)+1;
		for(i=0; i<MAPSIZE; i++)
		{
					if((ptr->row)==i)
					{
						fprintf(TreasureMap,"S",MAPSIZE);
					}
					else
					{
						fprintf(TreasureMap,"-",MAPSIZE);
					}
		}
		printf("\n");
		return 1;
		}
return 0;
}
int movenorth(struct RowCol *ptr){
	int i;
	if(ptr->row >0){
		ptr->row=(ptr->row)-1;
		for(i=0; i<MAPSIZE; i++)
		{
					if((ptr->row)==i)
					{
						fprintf(TreasureMap,"N",MAPSIZE);
						printf("X");
					}
					else
					{
						fprintf(TreasureMap,"-",MAPSIZE);
						printf("-");
					}
		}
		printf("\n");
		return 1;
		}
return 0;
}











