#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<string.h>


#include "pz19.h"

int		(*pz)[3]; //2차원
int		count   =0;
int		maxCount=0;


int main(){
	
	char   input=0;
	Point  cPoint, mPoint;

	pz=(int(*)[3])malloc(sizeof(int)*9);  //2차원
	//pz=(int*)malloc(sizeof(int)*9); //1차원

	reset(&cPoint);

	while(1){
		if((count>maxCount) || check() || input==KEY_RESET|| input==KEY_STOP) {  
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



