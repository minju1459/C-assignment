#include<stdio.h>
//#include<Windows.h>

void menu_display();
double add();
double sub();
double mul();
double div();
void res_display(double);

int main()
{
	int selection;
	double result;

	menu_display();
	scanf("%d", &selection);

	switch(selection){
	case 1: result=add();
			  break;
    case 2: result=sub();
			  break;
	case 3: result=mul();
			  break;
	case 4: result=div();
			  break;
	}
	res_display(result);
	return 0;
}
void menu_display()
{
	printf("============<�޴�>============\n");
	printf("1.    ����\n);
	printf("2.    ����\n);
	printf("3.    ����\n);
	printf("4.    ������\n);
	printf(">>���ϴ� ������ �����ϼ���: ");
}

double add()
{
	double a, b, res;
	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%lf%lf", &a, &b);
	res=a+b;
	return res;
}
double sub()
{
	double a, b, res;
	printf("�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%lf%lf", &a, &b);
	res=a-b;
	return res;
}
double mul()
{
	double a, b, res;
	printf(">>�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%lf%lf", &a, &b);
	res=a*b;
	return res;
}
double div()
{
	double a, b, res;
	printf(">>�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%lf%lf", &a, &b);
	res=a/b;
	return res;
}
void res_display(double val)
{
	printf("������� %lf�Դϴ�.\n",val);
}

