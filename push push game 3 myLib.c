#include <stdio.h>
#include <Windows.h>
#include "push.h"
extern int		 ground[SIZE][SIZE];
extern Point	 user;
extern int      count;
extern int      map_L_1[SIZE][SIZE];


void  init(){

		int i,k;
		for(i=0;i<SIZE;i++){
			for(k=0;k<SIZE;k++){
				ground[i][k]=map_L_1[i][k];
				if(ground[i][k]==ICON_USER){
					user.row=i;
					user.column=k;
			     }
		    }
		}
		return;
}

void  display(){

	int i,k;

	system("cls");
		for(i=0;i<SIZE;i++){
			for(k=0;k<SIZE;k++){
				switch(ground[i][k]){
				case ICON_EMPTY:
					 printf("%2s", " ");
					 break;
				case ICON_WALL:
					printf("%2s","¡à");
					break;
				case ICON_TARGET:
					printf("%2s","¡Ú");
					break;
				case ICON_BLOCK:
					printf("%2s","¡Ù");
					break;
				case ICON_USER:
					printf("%2s","¢ç");
					break;
				default:
					break;
				}		
				
			}	
			printf("\n");
		}
#ifdef _MY_DEBUG
		printf("User(%d,%d)\n",user.row, user.column);
#endif

}

int  getKey(){
	int key;
	key=getch();
	if(key==KEY_EXT){
		key=getch();
	}
	return key;
}