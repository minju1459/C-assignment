#include "push.h"
#include <stdio.h>

int		 ground[SIZE][SIZE];
Point	 user;
int      count;


int main(){

	int key;
	init();
	display();
	while(1){
		key=getKey();
	    display();
#ifdef _MY_DEBUG
		printf("KEY= %d\n",key);
#endif
	}

	getchar();
	getchar();
	return 0;

}