#include<stdio.h>


int main()
{
	int km,msec,h,min,m;
	double sec,T,pie;

	printf("�༺�� �������� �Է��ϼ��� <km>   :");
	scanf("%d",&km);
	printf("������ �ӵ��� �Է��ϼ��� <m/sec>: ");
	scanf("%d",&msec);
    
	printf("\n");
	printf("\n");

	m=km*1000;
	pie=3.14;
	T=(2*pie*m)/msec;

	h=T/3600;
    min=(T/3600-h)*60;
	sec=((T/3600-h)*60-min)*60;
	
    printf("%d km�� �������� ���� �༺�� %d m/s�� �ӵ��� �޸���\n�ѹ��� �� ��,%d �ð� %d�� %.3lf�� �ɸ��ϴ�.\n",km,msec,h,min,sec);
	printf("\n");
	printf("\n");

	return 0;
 }

	
