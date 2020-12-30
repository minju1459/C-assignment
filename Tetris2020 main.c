/*
** ��Ʈ���� 2020
** �������б� ������ȣ�а� 1�г� C���
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
	
	//base ground�� �ʱ�ȭ �Ѵ�.
	init();

	//���� �����ϰ� ������ ��, ����Ѵ�.
	newBlock();
	copybasGroundTodisGround(MY_ADD_BLOCK);
	displayGround();

	while(1){
		cur = current;
		dir = curDir;
		
		if( checkTimer(1000) == MY_TIME_OVER ){ 
				// Ű���� �Է� ���� 1�ʰ� ����ϸ� 
				// ���� ��ĭ �Ʒ��� ������.
				key = MY_KEY_DOWN;
		}
		else key= getKey();
		
		if( key != MY_KEY_NOT ){
			// Ű���� �Է��� ������, 
			// �ش� Ű ���� ���� ���� �̵��� ��ǥ/ȸ���� �ӽ� ����Ѵ�.
			getChangeBlockPointDir(key, &cur, &dir);

			// �ӽ� ��� ���� �������� �� �̵��� �������� Ȯ���Ѵ�.
			if( changeBlock(cur,dir) == MY_MOVE_ON ){
				//�̵��� �����ϸ�, ���� �̵���Ű�� ����Ѵ�.
				copybasGroundTodisGround(MY_ADD_BLOCK);
				displayGround();				
			}
			else if( key == MY_KEY_DOWN ){
				//�̵��� �Ұ��� �ϰ�, �Է� Ű ���� DOWN�̸�
				//base ground�� �ش� �ҷ��� �߰��Ѵ�.
				copyGround(disGround, basGround);

				//���� �� �Ʒ����� ���ʷ� Ȯ���ϸ� 
				//������ ������ ������ �����Ѵ�.
				removeLine();

				//���ο� ���� �����Ѵ�.
				newBlock();
				if (checkFinish() == MY_MOVE_NOT){
					//���� ������ ���� �����ǿ� �߰��� �� ������
					//������ ����� ������ �����Ѵ�.
					break;	
				}
				//���� �߰��� ���� ����ϰ� ������ ����Ѵ�.
				copybasGroundTodisGround(MY_ADD_BLOCK);
				displayGround();				
			}
		}
	}

	gameOver();

	return 0;
}


