#include<stdio.h>


int main()
{
	int km,msec,h,min,m;
	double sec,T,pie;

	printf("행성의 반지름을 입력하세요 <km>   :");
	scanf("%d",&km);
	printf("차량의 속도를 입력하세요 <m/sec>: ");
	scanf("%d",&msec);
    
	printf("\n");
	printf("\n");

	m=km*1000;
	pie=3.14;
	T=(2*pie*m)/msec;

	h=T/3600;
    min=(T/3600-h)*60;
	sec=((T/3600-h)*60-min)*60;
	
    printf("%d km의 반지름을 갖는 행성을 %d m/s의 속도로 달리면\n한바퀴 돌 때,%d 시간 %d분 %.3lf초 걸립니다.\n",km,msec,h,min,sec);
	printf("\n");
	printf("\n");

	return 0;
 }

	
