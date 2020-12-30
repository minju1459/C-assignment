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
	printf("============<메뉴>============\n");
	printf("1.    덧셈\n);
	printf("2.    뺄셈\n);
	printf("3.    곱셈\n);
	printf("4.    나눗셈\n);
	printf(">>원하는 연산을 선택하세요: ");
}

double add()
{
	double a, b, res;
	printf("두 개의 숫자를 입력하세요: ");
	scanf("%lf%lf", &a, &b);
	res=a+b;
	return res;
}
double sub()
{
	double a, b, res;
	printf("두 개의 숫자를 입력하세요: ");
	scanf("%lf%lf", &a, &b);
	res=a-b;
	return res;
}
double mul()
{
	double a, b, res;
	printf(">>두 개의 숫자를 입력하세요: ");
	scanf("%lf%lf", &a, &b);
	res=a*b;
	return res;
}
double div()
{
	double a, b, res;
	printf(">>두 개의 숫자를 입력하세요: ");
	scanf("%lf%lf", &a, &b);
	res=a/b;
	return res;
}
void res_display(double val)
{
	printf("결과값은 %lf입니다.\n",val);
}

