#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>

#include "pz19.h"

extern int		(*pz)[3]; //2차원
extern int		count   ;
extern int		maxCount;

static FILE  *score;
char   user[100];


void reset(Point *cPoint){
	char *filename = FILE_SCORE;;

	system("cls");
	printf("Input User's name: ");
	scanf("%s",user);
	printf("input max count: ");
	scanf("%d",&maxCount);
	
	score = fopen("score01.txt","r" );
	if( score==NULL){
		//file 생성
		score = fopen("score01.txt","w");
		fprintf(score, "%15s  %10s  %6s\n","Date, Time","Name", "Count");
		fprintf(score,"------------------------------------\n");
	}
	fclose(score);
	
	score = fopen("score01.txt","a");


	init(cPoint);

	display(0);
}

int play(Point *cPoint){
	int key;
	Point mPoint;
	
	key=getKey();  
	
	if( key =='q'|| key=='r') return key;

	getIndex(key, *cPoint, &mPoint);
	change(cPoint, mPoint);
	
	count++;
	display(key);

	return 0;
}

int getLine(){

	char input[100];
	int len,key;

	gets(input);
	len=strlen(input);
	if(len ==3 || len>5) return key;

	if( strcmp(input,"up")==0)	      key = KEY_UP;
	else if( strcmp(input,"down")==0) key = KEY_DOWN;
	else if( strcmp(input,"right")==0)key = KEY_RIGHT;
	else if( strcmp(input,"left")==0) key = KEY_LEFT;
	else if( strcmp(input,"q")==0)    key = KEY_STOP;
	else key=0;

	return key;
}

void init(Point *cPoint){
	int i,k, num;
	int test[9] = {1,2,3,4,5,6,7,0,8}; 

	for(i=0;i<9;i++){
		num = rand() %9;
		num = test[i];
		pz[i/3][i%3] = num;
		
		for(k=0;k<i;k++){
			if(pz[i/3][i%3] == pz[k/3][k%3]){
				i--;
				break;
			}
		}
		if(pz[i/3][i%3]==0){
			cPoint->row = i/3;
			cPoint->Column= i%3;
		}
	}
	count=0;
}

void scoredRecord(){
	char Date[100]={0};
	char Time[100]={0};

	_strdate(Date);
	_strtime(Time);

	if(score){

		fprintf(score,"%8s,%6s  %10s  %6d\n",Date,Time,user,count); 
		fclose(score);
	}

}

int check(){

	int i;

	for(i=0;i<8;i++){
		if(pz[i/3][i%3] != i+1) return 0;
		
	}

	//score 기록
	scoredRecord();
	return 1;
}

void display(int key){

	int i;
	char *str;
	
	system("cls");
	printf("┌───┬───┬───┐\n");
	
	for(i=0;i<9;i++){
		
		if (pz[i/3][i%3]==0)     printf("│%3c", '*');
		else				     printf("│%3d", pz[i/3][i%3]);					
		if(i%3==2&&i<7)			 printf("│\n├───┼───┼───┤\n");
		if(i%3==2&&i>7)			 printf("│\n");				 
	}	
	printf("└───┴───┴───┘\n");
	
	//key
	switch(key){
	case KEY_UP: 
		str="UP";
		break;
	case KEY_DOWN: 
		str="DOWN";
		break;
	case KEY_RIGHT: 
		str="RIGHT";
		break;
	case KEY_LEFT: 
		str="LEFT";
		break;
	default:
		str="NOTHING";
		break;
	}
	
	printf("input : %s\n",str);
	//count
	printf("count : %d\n",count);
}

void getIndex(int key, Point cPoint, Point *mPoint){
	
	mPoint->row = cPoint.row;
	mPoint->Column = cPoint.Column;

	switch(key){
	case KEY_UP: 
		 if(cPoint.row>0)	mPoint->row = cPoint.row-1;
		 break;
	case KEY_DOWN: 
		 if(cPoint.row<2)	mPoint->row= cPoint.row+1;
		 break;
	case KEY_RIGHT: 
		 if(cPoint.Column<2) mPoint->Column = cPoint.Column+1;
		 break;
	case KEY_LEFT: 
		 if(cPoint.Column>0) mPoint->Column = cPoint.Column-1;
		 break;
	default:
		 break;
	}
	
}

void change(Point *cPoint, Point mPoint){

	int temp;

	temp			                =pz[cPoint->row][cPoint->Column];
	pz[cPoint->row][cPoint->Column] =pz[mPoint.row][mPoint.Column];
	pz[mPoint.row][mPoint.Column]   =temp;

	cPoint->row		 = mPoint.row;
	cPoint->Column   = mPoint.Column; 
}

int getKey(){
	
	int key;
	char *str;
	key = getch();

	if(key == 224){
		key = getch();
	}
	return key;
}