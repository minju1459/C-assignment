#include<stdio.h>

int main()
{
	int	km,m,cm,mm;
	int classnum;
	char name[5];
	double distance;

	printf("�й�<����>, �̸�<���ڿ�>�� �Է��ϼ���: " );
	scanf("%d%s",&classnum,name);
	printf("�Ҽ��� ���� �ڸ����� 10�ڸ� �̻��� �Ǽ��� �Է��ϼ���: ");
	scanf("%lf",&distance);

	km=(int)distance;
	m=(distance-km)*1000;
	cm=(((distance-km)*1000)-m)*100;
	mm=(((((distance-km)*1000)-m)*100)-cm)*10;

	printf("========================================\n");
	printf("�й�: %d, �̸�: %s\n",classnum,name);
	printf("%lf km is %dkm, %dm, %dcm, %dmm\n",distance,km,m,cm,mm);
	printf("========================================\n");
    return 0;




	






