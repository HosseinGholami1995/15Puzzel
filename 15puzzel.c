//optimize the boolian value could 

#define True 1
#define False 0

#define EASY 10
#define NORMAL 20
#define HARD 30
#define ERROR 40

#define Esc 27

#include<time.h>//for random
#include <stdio.h>
#include <conio.h>//for getch

unsigned char init (unsigned char x[4][4]);
void show_table(unsigned char x[4][4] );
unsigned char MoveRule(unsigned char x[4][4],unsigned char input,unsigned char *X,unsigned char *Y);
unsigned char show_welcome_page();
void random_move(unsigned char NUM,unsigned char x[4][4],unsigned char *X,unsigned char *Y);
unsigned char CheckWin(unsigned char x[4][4]);
void shuffle_table(unsigned char lvl,unsigned char x[4][4],unsigned char *X,unsigned char *Y);
unsigned char show_play_again_page();	

void main(){
//Reserv and initial parameter on RAM
	unsigned char i,j;//used in for loop
	unsigned char x[4][4];//used as number in puzzel
	unsigned char exit=False,win=False,result=False; //use as boolian value 
	unsigned char X=3; //use as position of +
	unsigned char Y=3; //use as position of +
	unsigned char lvl;//use as hardness lvl
	unsigned char input;//use as keybord read 
//initial the game
	init(x);
	lvl=show_welcome_page();
	shuffle_table(lvl,x,&X,&Y);
	
	//game started 
	do {
		system("cls");
		show_table(x);

		if(win==False){
						input=getch();
			if(input==Esc)exit=True;
			MoveRule(x,input,&X,&Y);
			if(CheckWin(x))win=True;
		}
		else{
			result=show_play_again_page();
			if (result){
				lvl=show_welcome_page();
				shuffle_table(lvl,x,&X,&Y);
				win=False;
			}else exit =True;
		}
	}while(exit==False);

}

//show welcom page and lvl choos
unsigned char show_play_again_page(){
	system("cls");
	printf("  		/\\________________	15 Puzzel Game		________________/\\ \n");
	printf("		==================================================================\n");
	printf("		||								||\n");
	printf("		||congratulations,Do you whant play again?	 		||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||	press y to play again  					||\n");
	printf("		||	or press any thing else to quit				||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		||								||\n");
	printf("		==================================================================\n");
	printf("			");
	unsigned char input;
	input=getch();
	if((input=='y')||(input=='Y'))
		return True;
	else 
		return False;

}
//check it if its on win pattern
unsigned char CheckWin(unsigned char x[4][4]){
	unsigned char WinnerPattern[4][4],i,j,equal;
	equal=1;
	init(WinnerPattern);
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			if(WinnerPattern[i][j]!=x[i][j])
				equal=0;
	return equal;
}
//shuffle
void shuffle_table(unsigned char lvl,unsigned char x[4][4],unsigned char *X,unsigned char *Y){
	switch (lvl){
		case EASY:
				random_move(3,x,X,Y);
			break;
		case NORMAL:
				random_move(30,x,X,Y);
			break;
		case HARD:
				random_move(200,x,X,Y);
			break;
		default:
		break;	
		}

	}
//level implement via random move
void random_move(unsigned char NUM,unsigned char x[4][4],unsigned char *X,unsigned char *Y){
	 srand((unsigned) time(NULL));
	unsigned char i,input;
	for(i=0;i<NUM;i++){
		switch(rand()%4){
			case 0:
				input='w';
			break;
			case 1:
				input='a';
			break;
			case 2:
				input='s';
			break;
			default:
				input='d';
			break;	
		}
		MoveRule(x,input,X,Y);
	}
	MoveRule(x,'d',X,Y);
}
//show welcom page and lvl choos
unsigned char show_welcome_page(){
	unsigned char lvl;
	do{		
		system("cls");
		printf("  		/\\________________	15 Puzzel Game		________________/\\ \n");
		printf("		==================================================================\n");
		printf("		||welcom to 15 puzzel Game :) 					||\n");
		printf("		||this game has designd by Hossein Gholami			||\n");
		printf("		||as project of Computer Basics	and programming lesson		||\n");
		printf("		||at khajeh nasir university of technology(KNTU)		||\n");
		printf("		||								||\n");
		printf("		||	Choose your hardness then press enter :			||\n");
		printf("		||	(E)asy							||\n");
		printf("		||	(N)ormal						||\n");
		printf("		||	(H)ard							||\n");
		printf("		||								||\n");
		printf("		||								||\n");
		printf("		||								||\n");
		printf("		||								||\n");
		printf("		==================================================================\n");
		printf("			");
		lvl=getchar();	
		switch (lvl){
			case 'e':
				lvl=EASY;
				break;
			case 'E':
				lvl=EASY;
				break;
			case 'n':
				lvl=NORMAL;
				break;
			case 'N':
				lvl=NORMAL;
				break;
			case 'h':
				lvl=HARD;
				break;
			case 'H':
				lvl=HARD;
				break;
			default:
				lvl=ERROR;
				break;
			}
	}while(lvl==ERROR);
	return lvl;
}
//Move Rule
unsigned char MoveRule(unsigned char x[4][4],unsigned char input,unsigned char *X,unsigned char *Y){
		switch (input){
			case Esc:
				break;
			case 's'://up
				if (*Y==0)*Y=0;
				else {
					x[*Y][*X]=x[*Y-1][*X];
					*Y=*Y-1;
					x[*Y][*X]=0;
				}
				break;
			case 'd'://left
				if (*X==0)*X=0;
				else {
					x[*Y][*X]=x[*Y][*X-1];
					*X=*X-1;
					x[*Y][*X]=0;
				}
				break;
			case 'a':
				if (*X==3)*X=3;
				else {
					x[*Y][*X]=x[*Y][*X+1];
					*X=*X+1;
					x[*Y][*X]=0;
				}
				break;
			case 'w':
				if (*Y==3)*Y=3;
				else {
					x[*Y][*X]=x[*Y+1][*X];
					*Y=*Y+1;
					x[*Y][*X]=0;
				}
				break;
			default:
				printf("haam???\n");
				break;				
		}

}
//function for initiolization of table 	
unsigned char init (unsigned char x[4][4]){
	unsigned char i,j,k;//used in for loop
	k=0;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			k++;
			if(k!=16){
				x[i][j]=k;
			}else{
				x[i][j]=0;
			}
		}
	}
}
//function for show the table 
void show_table(unsigned char x[4][4] ){
	unsigned char i;
	//show table function
	printf("  		/\\________________	15 Puzzel Game		________________/\\ \n");
	printf("		==================================================================\n");
	printf("		||								||\n");
	for (i=0;i<4;i++){
		if (x[i][0]*x[i][1]*x[i][2]*x[i][3]!=0){
			printf("		||	%d		%d		%d		%d	||\n",x[i][0],x[i][1],x[i][2],x[i][3]);
			printf("		||								||\n");
			printf("		||								||\n");
		}else{
				if (x[i][0]==0)
					printf("		||	 		%d		%d		%d	||\n",x[i][1],x[i][2],x[i][3]);
				if (x[i][1]==0)
					printf("		||	%d		 		%d		%d	||\n",x[i][0],x[i][2],x[i][3]);
				if (x[i][2]==0)
					printf("		||	%d		%d		 		%d	||\n",x[i][0],x[i][1],x[i][3]);
				if (x[i][3]==0)
					printf("		||	%d		%d		%d		 	||\n",x[i][0],x[i][1],x[i][2]);
			
			printf("		||								||\n");
			printf("		||								||\n");
			
			}
	}
	printf("		==================================================================\n");
	printf("  		\\/________________	press \"Esc\" to quit	________________\\/ \n");

}
