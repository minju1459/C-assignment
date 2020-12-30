#include<stdio.h>
#include"push.h"

extern int		ground[SIZE][SIZE];
extern Point		user;
extern int		map_L_1[SIZE][SIZE];
extern int		map_L_2[SIZE][SIZE];
extern int		map_L_3[SIZE][SIZE];

static Point		cUser;
static Point		cBlock;

int		check(int key){
	int		change=0;

	cUser = user;
	cBlock = user;
	
	if(key == KEY_RIGHT || key == KEY_DOWN)   change=1;
	else if(key == KEY_LEFT || key == KEY_UP) change=-1;
	else return RET_FAIL;

	if(key == KEY_RIGHT || key == KEY_LEFT) {
		cUser.column +=change;
	}
	else{
		cUser.row +=change;
	}

	cBlock = cUser;
	if(ground[cUser.row][cUser.column] == ICON_BLOCK){
		if(key == KEY_RIGHT || key == KEY_LEFT) {
			cBlock.column +=change;
		}
		else{
			cBlock.row +=change;
		}
	}

#ifdef _MY_DEBUG
	printf("--> cp(%d,%d)\n", cBlock.row, cBlock.column);
#endif
	if(ground[cBlock.row][cBlock.column] == ICON_EMPTY ||
		ground[cBlock.row][cBlock.column] == ICON_TARGET ){
		return RET_SUCCESS;
	}

	return RET_FAIL;
}

void		move(){
	if(ground[cUser.row][cUser.column] == ICON_BLOCK){
		//블럭 이동
		ground[cBlock.row][cBlock.column] = ICON_BLOCK;
	}
	//User 이동
	ground[cUser.row][cUser.column]=ICON_USER;
	
	//초기화
	ground[user.row][user.column] = ICON_EMPTY;
	if(map_L_3[user.row][user.column] == ICON_TARGET)
		ground[user.row][user.column] = ICON_TARGET;

	//좌표 설정
	user = cUser;
}

int	finish(){
	int i, k;
	for(i=0;i<SIZE;i++){
		for(k=0;k<SIZE; k++){
			if(map_L_3[i][k] == ICON_TARGET) {
				if(ground[i][k] != ICON_BLOCK) return RET_FAIL;
			}
		}
	}
	return RET_SUCCESS;
}