#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>


//구조체 정의
typedef struct _Point{
	int row;
	int Column;
}Point;

int getKey();
int getLine();
int play(Point *cPoint);

void init(Point *cPoint);
void display(int key);

void getIndex(int key, Point cPoint, Point *mPoint);
void change(Point *cPoint, Point mPoint);
int check();
void reset(Point *cPoint);

int		(*pz)[3]; //2차원
//int    *pz;   //1차원 
int		count   =0;
int		maxCount=0;

//struct _Point cPoint;
//Point		  mPoint;

FILE  *score;
char  user[100];

int main(){
	
	char   input=0;
	Point  cPoint, mPoint;

	pz=(int(*)[3])malloc(sizeof(int)*9);  //2차원
	//pz=(int*)malloc(sizeof(int)*9); //1차원

	reset(&cPoint);

	while(1){
		if((count>maxCount) || check() || input=='r'|| input=='q' ) {  
			printf("Finish\n");

			if(input=='q') break;
			else if(input !='r'){
				printf("continue? (y/n) : ");
				scanf(" %c",&input);  //" %c" 띄어쓰기 
			}

			if(input == 'y' || input=='r'){
				reset(&cPoint);
			}
			else break;		
		}
		
		input=play(&cPoint);
	}

	getchar();
	getchar();
	return 0;
}

void reset(Point *cPoint){
	//char *filename = "score11.txt"; -> 쉽게 파일명을 바꾸려면 이렇게 작성

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

	if( strcmp(input,"up")==0)	      key = 72;
	else if( strcmp(input,"down")==0) key = 80;
	else if( strcmp(input,"right")==0)key = 77;
	else if( strcmp(input,"left")==0) key = 75;
	else if( strcmp(input,"q")==0)    key = 'q';
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
	case 72: 
		str="UP";
		break;
	case 80: 
		str="DOWN";
		break;
	case 77: 
		str="RIGHT";
		break;
	case 75: 
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
	case 72: 
		if(cPoint.row>0)	mPoint->row = cPoint.row-1;
		break;
	case 80: 
		if(cPoint.row<2)	mPoint->row= cPoint.row+1;
		break;
	case 77: 
		if(cPoint.Column<2) mPoint->Column = cPoint.Column+1;
		break;
	case 75: 
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

