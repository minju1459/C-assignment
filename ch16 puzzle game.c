#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>


int getKey();
int getLine();
int play();
void init();
int check();
void display();
void getIndex(int key, int cRow, int cColumn, int *chRow, int *chColumn);
void change(int *cRow, int *cColumn, int chRow, int chColumn);

char pz[3][3]={'0','1','2','3','4','5','6','7','8'};
int currRow, currColumn;

int main(){

	char *pzPoint[9]={"star","one","two","three","four","five","six","seven","eight"};
	int count;
	char input;
	
	srand(time(NULL));

	init();
	display();

	while(1){
		count=play();
		if(0== count) break;
		printf("count : %d\n", count);
		printf("%s, %s, %s\n", pzPoint[pz[0][0]-'0'],pzPoint[pz[1][1]-'0'],pzPoint[pz[2][2]-'0']);
		if( check() ){
			printf("Finish\n");
			printf("continue? (y/n) : ");
			scanf("%c",&input);
			if(input =='y'){

				init();
				display();
			}
			else break;
			
		}
	}

	getchar();
	getchar();
	
	return 0;
}

int play(){
	static int count = 0;
	int key;
	int changeRow, changeColumn;
	
	key=getKey();

	if( key =='q') return 0;

	getIndex(key, currRow, currColumn,&changeRow, &changeColumn);
	change(&currRow, &currColumn,changeRow, changeColumn);
	display();
	count++;
	return count;
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




void init(){
	int i,num;
	int k=0;
	int test[9] = {1,2,3,4,5,6,7,0,8};
	

	for(i=0;i<9;i++){
		
		num = rand() %9;
		num = test[i];
		pz[i/3][i%3] = '0'+num;
		
		for(k=0;k<i;k++){
			if(pz[i/3][i%3] == pz[k/3][k%3]){
				i--;
				break;
			}
		}
		if(pz[i/3][i%3]=='0'){
			currRow = i/3;
			currColumn = i%3;
		}

	}
}

int check(){

	int i,k;

	for(i=0;i<8;i++){
		if((pz[i/3][i%3]-'0')!= i+1) return 0;
		
	}
	
	return 1;
}

void display(){

	int i;
	system("cls");
	for(i=0;i<9;i++){
		if (pz[i/3][i%3]=='0') printf("%3c", '*');
		else printf("%3c", pz[i/3][i%3]);
		if(i%3==2) printf("\n");
	}
	
}

void getIndex(int key, int cRow, int cColumn, int *chRow, int *chColumn){
	
	(*chRow) = cRow;
	(*chColumn) = cColumn;

	switch(key){
	case 72: 
		if(cRow>0) (*chRow) = cRow-1;
		break;
	case 80: 
		if(cRow<2) (*chRow) = cRow+1;
		break;
	case 77: 
		if(cColumn<2) (*chColumn) = cColumn+1;
		break;
	case 75: 
		if(cColumn>0) (*chColumn) = cColumn-1;
		break;
	default:
		break;
	}
	
}


void change(int *cRow, int *cColumn, int chRow, int chColumn){

	int temp;

	temp			   =pz[*cRow][*cColumn];
	pz[*cRow][*cColumn]=pz[chRow][chColumn];
	pz[chRow][chColumn]=temp;

	*cRow = chRow;
	*cColumn = chColumn;
}

int getKey(){
	
	int key;
	char *str;
	key = getch();

	key = getch();
	if(key == 224){
		key = getch();
	}

	return key;
}