//optimize the boolian value

#include <stdio.h>
#include <conio.h>//for getch

unsigned char init (unsigned char x[4][4]);
void show_table(unsigned char x[4][4] );


void main(){
	unsigned char i,j;//used in for loop
	unsigned char x[4][4];//used as number in puzzel
	unsigned char exit=0; //use as boolian value 
	unsigned char X=3; //use as position of +
	unsigned char Y=3; //use as position of +
	unsigned char input;
	
	init(x);
	
	do {
		system("cls");
		show_table(x);
		input=getch();
		//printf("key is %d--\n",input);
		switch (input){
			case 27://escape
				exit=1;
				break;
			case 'w'://up
				if (Y==0)Y=0;
				else {
					x[Y][X]=x[Y-1][X];
					Y=Y-1;
					x[Y][X]=0;
				}
				break;
			case 'a'://left
				if (X==0)X=0;
				else {
					x[Y][X]=x[Y][X-1];
					X=X-1;
					x[Y][X]=0;
				}
				break;
			case 'd':
				if (X==3)X=3;
				else {
					x[Y][X]=x[Y][X+1];
					X=X+1;
					x[Y][X]=0;
				}
				break;
			case 's':
				if (Y==3)Y=3;
				else {
					x[Y][X]=x[Y+1][X];
					Y=Y+1;
					x[Y][X]=0;
				}
				break;
			default:
				printf("haam???\n");
				break;				
		}
	
	}while(!exit);
		

	
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
					printf("		||	+		%d		%d		%d	||\n",x[i][1],x[i][2],x[i][3]);
				if (x[i][1]==0)
					printf("		||	%d		+		%d		%d	||\n",x[i][0],x[i][2],x[i][3]);
				if (x[i][2]==0)
					printf("		||	%d		%d		+		%d	||\n",x[i][0],x[i][1],x[i][3]);
				if (x[i][3]==0)
					printf("		||	%d		%d		%d		+	||\n",x[i][0],x[i][1],x[i][2]);
			
			printf("		||								||\n");
			printf("		||								||\n");
			
			}
	}
	printf("		==================================================================\n");
	printf("  		\\/________________	Hossein Gholami		________________\\/ \n");

}
