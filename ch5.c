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

	printf("���� ��뷮�� �Է��ϼ���(kw)\n");
	scanf("%d",&users);
	printf("���� ��� ����� %lf���Դϴ�.\n",total);
	return 0 ;
}


