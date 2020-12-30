#include<stdio.h>

int main()
{
	int	km,m,cm,mm;
	int classnum;
	char name[5];
	double distance;

	printf("학번<정수>, 이름<문자열>을 입력하세요: " );
	scanf("%d%s",&classnum,name);
	printf("소수점 이하 자리수가 10자리 이상인 실수를 입력하세요: ");
	scanf("%lf",&distance);

	km=(int)distance;
	m=(distance-km)*1000;
	cm=(((distance-km)*1000)-m)*100;
	mm=(((((distance-km)*1000)-m)*100)-cm)*10;

	printf("========================================\n");
	printf("학번: %d, 이름: %s\n",classnum,name);
	printf("%lf km is %dkm, %dm, %dcm, %dmm\n",distance,km,m,cm,mm);
	printf("========================================\n");
    return 0;




	






