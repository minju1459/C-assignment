#include"tetris.h"
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>

extern Point		current;
extern int		curBlock;
extern int		curDir;

extern int		basGround[MY_HIGH][MY_WIDTH];	//base
extern int		disGround[MY_HIGH][MY_WIDTH];	//dispaly
extern int		preGround[MY_HIGH][MY_WIDTH];	//previous


extern Point	blockPattern[MY_PATTERN_NUM][4][4];


void init(){

	int i,k;
	//baseGround setting
	for(i=0; i<MY_HIGH ; i++){
		for(k=0 ; k<MY_WIDTH ; k++){
			basGround[i][k] = MY_SPACE;
			preGround[i][k] = 0xFF;
		}
	}

	for(k=0;k<MY_WIDTH;k++){
		basGround[0][k]				= MY_WALL;
		basGround[MY_HIGH -1][k]		= MY_WALL;
	}
	for(i=1; i<MY_HIGH -1 ; i++){
		basGround[i][0]				= MY_WALL;
		basGround[i][MY_WIDTH-1]		= MY_WALL;
	}
}

void copybasGroundTodisGround(int addBlock){

	int i, row, col;

	copyGround(basGround, disGround);
	
	if( addBlock ){
		for(i=0;i<4;i++){
			row		= current.row		+ blockPattern[curBlock][curDir][i].row;
			col		= current.column		+ blockPattern[curBlock][curDir][i].column;
			disGround[row][col] = curBlock ; 
		}
	}
}

void displayGround(){

	int i,k;
	//int count=0;

	for(i=0; i<MY_HIGH; i++){
		for( k=0;k<MY_WIDTH; k++){
			if(disGround[i][k]  != preGround[i][k]){
				gotoxy(i, 2*k);
				//count++;
				switch(disGround[i][k]){
				case MY_SPACE:
					printf("  ");
					break;
				case MY_WALL:
					printf("□");
					break;
				case MY_BLOCK_1:
					printf("■");
					break;
				case MY_BLOCK_2:
					printf("■");
					break;
				case MY_BLOCK_3:
					printf("■");
					break;
				case MY_BLOCK_4:
					printf("■");
					break;
				case MY_BLOCK_5:
					printf("■");
					break;
				default:
					break;
				}
				preGround[i][k] = disGround[i][k];
			}
		}
	}

	gotoxy(MY_HIGH+3, 0);
	printf("block : %4d, dir: %4d", curBlock, curDir);

	//display ground를 previous ground에 복사
	//copyGround(disGround, preGround);
}

void getChangeBlockPointDir(int key, Point *cur, int *dir){

	*cur = current;
	*dir = curDir;

	switch(key){
	case MY_KEY_UP:
		*dir = (curDir +1)%4;  //0,1,2,3,0,1,2,3.....
		break;
	case MY_KEY_DOWN:
		cur->row +=1;
		break;
	case MY_KEY_RIGHT:
		cur->column +=1;
		break;
	case MY_KEY_LEFT:
		cur->column -=1;
		break;
	default:
		break;
	}

}

int _checkBlock(Point cur, int dir){
	int i, row, col;

	for(i=0;i<4;i++){

		row		= cur.row		+ blockPattern[curBlock][dir][i].row;
		col		= cur.column	+ blockPattern[curBlock][dir][i].column;

		if(basGround[row][col]  != MY_SPACE) return MY_MOVE_NOT;
	}

	return MY_MOVE_ON;
}

int changeBlock(Point cur, int dir){

	int result;

	result = _checkBlock(cur, dir);

	if( result == MY_MOVE_ON){
		current = cur;
		curDir	= dir;
	}

	return result;
}

void newBlock(){
	current.row = 1;
	current.column = 5;

	curBlock = rand() % MY_PATTERN_NUM ;
	//curBlock = 0 ;
	curDir = rand()%4 ;
}

void downLine(int startLine){
	int row,col ;

	for(row = startLine; row > 1; row--){
		for(col=1; col < MY_WIDTH-1 ; col++){
			basGround[row][col] = basGround[row-1][col];
		}
	}
}

void _delay(int limit){
	while (checkTimer(limit) != MY_TIME_OVER){
		;
	}
}

void removeLine(){

	int row, col; 
	for(row = MY_HIGH-2 ; row> 0 ; row--){

		for(col=1; col < MY_WIDTH-1 ; col++){
			if( basGround[row][col] == MY_SPACE) break;
		}
		if(col == MY_WIDTH-1){
			//row 번째 라인을 지운다
			downLine(row);
			copybasGroundTodisGround(MY_NO_BLOCK);
			displayGround();
			_delay(500);
			//지운 라인부터 다시 한번 확인하도록 처리한다.
			row++;
		}
	}
}

int checkFinish(){
	Point	cur;
	int		dir;

	getChangeBlockPointDir(MY_KEY_NOT, &cur, &dir);
	return _checkBlock(cur, dir);
}

void gameOver(){
	system("cls");
	gotoxy(10,0);
	printf("\t======================\n");
	printf("\t  Finish\n");
	printf("\t  Press Any Key\n");
	printf("\t======================\n");
	_getch();
}