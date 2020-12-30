#include <stdio.h>

int main()

{
	int basic, users, every, total;
	double kwdang, tax;
	basic = 660;
	kwdang= 88.5;

	every=basic + (users*kwdang);
	tax=every*0.09;

	total=(every+tax);

	printf("전기 사용량을 입력하세요(kw)\n");
	scanf("%d",&users);
	printf("전기 사용 요금은 %lf원입니다.\n",total);
	return 0 ;
}


