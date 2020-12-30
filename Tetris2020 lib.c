#include"tetris.h"
#include<conio.h>
#include<Windows.h>

extern Point	current;
extern int		curBlock;
extern int		curDir;
extern int		basGround[MY_HIGH][MY_WIDTH];	//base
extern int		disGround[MY_HIGH][MY_WIDTH];	//dispaly
extern int		preGround[MY_HIGH][MY_WIDTH];	//previous


extern Point	blockPattern[MY_PATTERN_NUM][4][4];


int getKey(){

	int key=0;

	if( kbhit() ){
		key = getch();
		if( key == 224 ) key = getch();
	}
	return key;
}

void gotoxy(int row, int column){
	static HANDLE h = NULL;
	COORD c = { column, row };

	if (!h){
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	SetConsoleCursorPosition(h, c);
}

int checkTimer(int cTime){
	static unsigned long oldTime = 0;
	unsigned long newTime;

	newTime = GetTickCount64();
	if( (newTime - oldTime ) > cTime){
		oldTime = newTime;
		return MY_TIME_OVER;
	}
	else{
		return MY_TIME_NOT;
	}
}

int copyGround(int (*source)[MY_WIDTH], int (*target)[MY_WIDTH]){
	int i,k;
	for( i = 0 ; i< MY_HIGH ; i++){
		for(k = 0 ; k < MY_WIDTH ; k++){
			target[i][k] = source[i][k] ;
		}
	}
	return 0;
}
