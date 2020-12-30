/*
** 테트리스 2020
** 수원대학교 정보보호학과 1학년 C언어
*/

#include"tetris.h"
#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>

extern Point		current;
extern int		curBlock;
extern int		curDir;
extern int		basGround[MY_HIGH][MY_WIDTH];	//base
extern int		disGround[MY_HIGH][MY_WIDTH];	//dispaly
extern int		preGround[MY_HIGH][MY_WIDTH];	//previous


extern Point	blockPattern[MY_PATTERN_NUM][4][4];


int main(){

	Point	cur;
	int		dir, key;

	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	system("mode con: cols=40 lines=25");

	srand(time(NULL));
	
	//base ground를 초기화 한다.
	init();

	//블럭을 랜덤하게 선택한 후, 출력한다.
	newBlock();
	copybasGroundTodisGround(MY_ADD_BLOCK);
	displayGround();

	while(1){
		cur = current;
		dir = curDir;
		
		if( checkTimer(1000) == MY_TIME_OVER ){ 
				// 키보드 입력 없이 1초가 경과하면 
				// 블럭을 한칸 아래로 내린다.
				key = MY_KEY_DOWN;
		}
		else key= getKey();
		
		if( key != MY_KEY_NOT ){
			// 키보드 입력이 있으면, 
			// 해당 키 값에 따라 블럭이 이동할 좌표/회전을 임시 계산한다.
			getChangeBlockPointDir(key, &cur, &dir);

			// 임시 계산 값을 바탕으로 블럭 이동이 가능한지 확인한다.
			if( changeBlock(cur,dir) == MY_MOVE_ON ){
				//이동이 가능하면, 블럭을 이동시키고 출력한다.
				copybasGroundTodisGround(MY_ADD_BLOCK);
				displayGround();				
			}
			else if( key == MY_KEY_DOWN ){
				//이동이 불가능 하고, 입력 키 값이 DOWN이면
				//base ground에 해당 불럭을 추가한다.
				copyGround(disGround, basGround);

				//게임 판 아래부터 차례로 확인하며 
				//삭제할 라인이 있으면 삭제한다.
				removeLine();

				//새로운 블럭을 선택한다.
				newBlock();
				if (checkFinish() == MY_MOVE_NOT){
					//새로 선택한 블럭을 게임판에 추가할 수 없으면
					//게임이 종료된 것으로 간주한다.
					break;	
				}
				//새로 추가된 블럭을 출력하고 게임을 계속한다.
				copybasGroundTodisGround(MY_ADD_BLOCK);
				displayGround();				
			}
		}
	}

	gameOver();

	return 0;
}


