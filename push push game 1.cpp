#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int getKey();
int init(int*);
int check(int*);
void display (int *pz);
void getIndex ( int key, int currentIndex, int *changeIndex);
int change (int *pz, int currentIndex, int changeIndex);



int getKey() {

	int key = NULL;

	if (_kbhit()) {
		key = getch();
		if (key == 224){
           key = getch();
		}
	}
	return key;
}

int main() {
	
	int i, key, currentIndex, changeIndex, result;
	int pz[9];

	srand(time(NULL));
	currentIndex=init(pz);
	display(pz);
	while (1) {
		key = getKey();
		if (key !=0){
			getIndex(key, currentIndex, &changeIndex);
			currentIndex=change(pz, currentIndex, changeIndex);
			display(pz);
			if(check(pz)) break;
		}
	}
	return 0;
}


int init (int *pz) {

		int i , k , index=0;
	
		for (i=0; i<9; i++){
			pz[i]=rand()%9;   
			for (k=0;k<i;k++){
					if(pz[i]==pz[k]){
						 i--;
						 break;
					 }
		     }
			if(pz[i]==0) index = i ;
	    }
	return index;
}

int check (int *pz) {
		
	int i;

	for(i=0 ; i<8 ; i++){
			if (pz[i]!=i+1){
				return 0;
			}
     }	
	return 1;
}

void display (int *pz) {
		
		int i ;
		
		system("cls");
		for(i=0;i<9;i++){
				if(pz[i] ==0){
					printf("%3c",'*');
				}
				else{
					printf("%3d", pz[i]);
				}
				if(i%3==2) printf("\n");
		}
}

void getIndex ( int key, int currentIndex, int *changeIndex){
	
	*changeIndex = currentIndex;

	switch(key){
	case 72: //up
			if(currentIndex>2)  *changeIndex =currentIndex-3 ; 
			break;
	case 80://down
			if(currentIndex< 6 )   *changeIndex = currentIndex+3;
			break;
	case 77://right
			if(currentIndex%3 !=2)  *changeIndex =currentIndex+1 ; 
			break;
	case 75://left
			if(currentIndex%3 !=0)  *changeIndex  =currentIndex-1 ; 
			break;
	default:
			break;
	}
}

int change (int *pz, int currentIndex, int changeIndex){

		int temp;
													 
		temp=pz[currentIndex];                  
		pz[currentIndex]=pz[changeIndex];        
		pz[changeIndex]=temp;  
		return changeIndex;
	
}