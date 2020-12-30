
#include<stdio.h>
#include<Windows.h>
#include"push.h"

int		ground[SIZE][SIZE];
Point	user;
int		count;

int main(){
	int key;

	init();
	display();
	while(1){
		key = getKey();		
#ifdef _MY_DEBUG
		printf("Key = %d\n", key);
#endif
		if(check(key)){
			move();
			display();
			if(RET_SUCCESS == finish()){
				system("cls");
				printf("\n\n\n\n\n");
				printf("\tSuccess !!\n");
				break;
			}
		}
	}

	getchar();
	getchar();

	return 0;
}