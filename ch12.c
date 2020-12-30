//20518031 ╧з╧наж
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>

void drawingTree(int high, int width, int space, int color)
{
		int i , k ;
		for(i=0; i<high; i++)
		{
			for(k=0; k<space; k++) 
			{
				printf(" ");
			}
			for(k=0; k<width; k++) 
			{
				if(color==0)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XF0+(rand()%15));
				printf("*");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XF0+(0X00));
			}
				printf("\n");
				space--;
				width+=2;
		}
}
	int getRandom(){
	int num;
	num=rand()%15;
	return num;
}

	int main(void){

	int t,num;
	num=getRandom();
	system("color f0");
	srand(time(NULL));

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XF0+(num));
	drawingTree(6,1,20,0);
	drawingTree(6,7,17,0);
	drawingTree(6,13,14,0);
	drawingTree(6,19,11,0);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0XF0+(0));
	for(t=0; t<4; t++) drawingTree(1,5,18,1);
	for(t=0; t<2; t++) drawingTree(1,11,15,1);
	for(t=0; t<2; t++) drawingTree(1,9,16,1);
	for(t=0; t<2; t++) drawingTree(1,7,17,1);
	for(t=0; t<2; t++) drawingTree(1,5,18,1);
	return 0;
}

