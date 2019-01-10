//donald adams 1000768238 assignment for coding number 10 treasure map reader and video game
/*
This program takes the input file named map2,
and displays the map to the screen.
The user then can update his changes to the 
map.
As the user makes changes to the map, the
program will print, and compare his moves with
that of the map.
If the user moves to the same ending position
as that in the map2 file, they become the 
winner.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAPSIZE 10
#define TRUE	1
#define FALSE	0

struct PlayerInfo{
	char PlayerName[20];
	int row;
	int col;
	};
char PlayerPath[MAPSIZE][MAPSIZE];
// declare two global characters to null
char DirectionsFilename[20]={};
char MapFilename[20]       ={};
char MapList[500];
char Map[MAPSIZE][MAPSIZE];

int moveeast(struct PlayerInfo *ptr){
	if(ptr->col < (MAPSIZE-1)) {
		ptr->col=(ptr->col)+1;
		return 1;
		}
	return 0;
}
int movewest(struct PlayerInfo *ptr){
	if(ptr->col >0){
		ptr->col=(ptr->col)-1;
		return 1;
		}
return 0;
}
int movesouth(struct PlayerInfo *ptr){
	if(ptr->row <9){
		ptr->row=(ptr->row)+1;
		return 1;
		}
return 0;
}
int movenorth(struct PlayerInfo *ptr){
	if(ptr->row >0){
		ptr->row=(ptr->row)-1;
		return 1;
		}
return 0;
}

void print_PlayerPath(char arr[MAPSIZE][MAPSIZE]){
	int i, j;
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
}
void get_direction(char *str){
	int i=0,j=0,k=0,res;
	char dest[11];
	char ch;
	while(i<=strlen(str)){
		strncpy(dest,(str+i),10);
		dest[10]='\0';
		res=strcmp(dest, "DIRECTION=\0");
		if(res==0){
			i=i+10;
			while(i<=strlen(str)&&((ch=(char)str[i])!=' ' || (ch=(char)str[i]!='\n') || (ch=(char)str[i])!=EOF)){
				DirectionsFilename[k]=ch;
				k++;
				i++;
				} //end while
		}else{
			i=i+10;
		}
	}//end outer while
}
void get_map(char *str){
	int i=0, j=0, k=0, res;
	char dest[5];
	char ch;
	while(i<=strlen(str)){
		strncpy(dest,(str+i),4);
		dest[4]='\0';
		res=strcmp(dest,"MAP=\0");
		if(res==0){
			i=i+4;
			while(i<=strlen(str) && ((ch=(char)str[i])!=' ' || (ch=(char)str[i]!='\n') || (ch=(char)str[i])!=EOF)){
				MapFilename[k]=ch;
				k++;
				i++;
			}
		}else{
		 i=i+4;
		}
	}
}
void get_command_line_parameters(int argc, char *argv[]){
	int i, j;
	for(i=1;i<(int)argc;i++){
		//get_direction(argc[i]);
		get_map(argv[i]);
	}
}
int main(int argc, char *argv[]){
	int i,j,k,makemove;
	char ch,PlayerMove;
	FILE *TreasureMap;
	//reading paramters
	get_command_line_parameters(argc,argv);
	printf("opening file: %s\n", MapFilename);
	TreasureMap=fopen(MapFilename,"r");
	if(TreasureMap==NULL){
		perror("TreasureMap did not open");
		exit(0);
	}
	system("clear");
	printf("Enter the Player Nmae\n");
	//initialised rows and columns for structure
	struct PlayerInfo *Player=(struct PlayerInfo *)malloc(1*sizeof(struct PlayerInfo));
	Player->row=0;
	Player->col=0;
	scanf("%s",&Player->PlayerName);
	//reading from TreasureMap into MapList
	fgets(MapList,110,TreasureMap);
	printf("MapList is :%s\n",MapList);
	i=0;
	for(j=0;j<MAPSIZE;j++){
		for(k=0;k<MAPSIZE;k++){
			Map[j][k]=MapList[i];
			printf("%c",Map[j][k]);	
			i++;	
			PlayerPath[j][k]='-';
		}
	printf("\n");
	}
	scanf("%c",&ch);
	system("clear");
	//printing contents of both cahracter arrays Directions and Mapfilename
	//initialzes PlayerPath with zeros
	/*
	for(i=0;i<MAPSIZE;i++){
		for(j=0;j<MAPSIZE;j++){
			PlayerPath[j][k]=0;
		}
	}
	PlayerPath[0][0]=1;
	*/
	PlayerPath[0][0]=Map[0][0];
	//open fil to read input
	i=0;
	
	do{
		system("clear");
		printf("-----------------------MAP-----------------------------\n");
		print_PlayerPath(Map);
		printf("-----------------------Your Progress------------------\n");
		print_PlayerPath(PlayerPath);
		printf("Enter Directions(NEWS) or 'Q' to quit\n");
		scanf("%c",&PlayerMove);
		PlayerMove=toupper(PlayerMove);
		printf("Player move is :%c\n", PlayerMove);
		if(PlayerMove=='N'){
			printf("moving north:%d\t%d\n",Player->row,Player->col);
			//PlayerPath[Player->row][Player->col]='X';
		}else{
			if(PlayerMove=='S'){
				printf("moving south:%d\t%d\n",Player->row,Player->col);
				makemove=movesouth(Player);
				//PlayerPath[Player->row][Player->col]='X';
				//endif	
		}else{	
			if(PlayerMove=='E'){
				printf("moving east:%d\t%d\n",Player->row,Player->col);
				makemove=moveeast(Player);
				//PlayerPath[Player->row][Player->col]='X';
				 //end if
		}else{
			if(PlayerMove=='W'){
				printf("moving west:%d\t%d\n",Player->row,Player->col);
				makemove=movewest(Player);
				//PlayerPath[Player->row][Player->col]='X';
				 //end if
		}
		}
		}
		}
		 //end elses chain
		if(makemove==1){
			if(Map[Player->row][Player->col]=='S'){
				printf("Player x is back at the start\n");
			}
			if(Map[Player->row][Player->col]=='X'){
				PlayerPath[Player->row][Player->col]='E';
				PlayerMove='Q';
			} //end inner if
		}//end outer if
	}while(PlayerMove!='Q');
	print_PlayerPath(PlayerPath);
	fclose(TreasureMap);
return 0;
}// end main;




