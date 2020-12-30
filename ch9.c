#include<stdio.h>
#include<Windows.h>

void menu_display();
double add();
double sub();
double mul();
double diff();
void res_display(double);


int main()
{
    int selection;
    double result;

    menu_display();
    scanf_s("%d", &selection);

    switch (selection) {
    case 1: result = add();
        break;
    case 2: result = sub();
        break;
    case 3: result = mul();
        break;
    case 4: result = diff();
        break;
    }

    res_display(result);
    return 0;
}
void menu_display()
{
    printf("============<메뉴>============\n");
    printf("1.    덧셈\n");
    printf("2.    뺄셈\n");
    printf("3.    곱셈\n");
    printf("4.    나눗셈\n");
    printf(">>원하는 연산을 선택하세요: ");
}

double add()
{
    double a, b, res;
    system("cls");
    printf("=======<덧셈 연산을 시작합니다.>=======\n");
    printf("두 개의 숫자를 입력하세요: ");
    scanf_s("%lf%lf", &a, &b);
    res = a + b;
    return res;
}
double sub()
{
    double a, b, res;
    system("cls");
    printf("=======<뺄셈 연산을 시작합니다.>=======\n");
    printf("두 개의 숫자를 입력하세요: ");
    scanf_s("%lf%lf", &a, &b);
    res = a - b;
    return res;
}
double mul()
{
    double a, b, res;
    system("cls");
    printf("=======<곱셈 연산을 시작합니다.>=======\n");
    printf(">>두 개의 숫자를 입력하세요: ");
    scanf_s("%lf%lf", &a, &b);
    res = a * b;
    return res;
}
double diff()
{
    double a, b, res;
    system("cls");
    printf("=======<나눗셈 연산을 시작합니다.>=======\n");
    printf(">>두 개의 숫자를 입력하세요: ");
    scanf_s("%lf%lf", &a, &b);
    res = a / b;
    return res;
}

void res_display(double val)
{
    printf("a b=%lf입니다.\n", val);
}

int cac()
{
    char ing;
    int selection;
    double a, b, result=0;
    while (1)
    {
        system("cls");
        printf("============<메뉴>============\n");
        printf(">>1.    덧셈\n");
        printf(">>2.    뺄셈\n");
        printf(">>3.    곱셈\n");
        printf(">>4.    나눗셈\n");
        printf("메뉴 번호를 선택하시오 \n");
        scanf_s(" %d", &selection);
        if (selection > 4 || selection < 1)
        {
            printf("오류입니다.\n");
            system("pause");
            continue;
        }
        printf("두 개의 수를 입력하시오 \n");
        scanf_s("%lf%lf", &a, &b);
        switch (selection)
        {
        case 1:
            printf("a-b=%lf입니다.\n", result);
            break;
        case 2:
            printf("a-b=%lf입니다.\n", result);
            break;
        case 3: 
            printf("a*b=%lf입니다.\n", result);
            break;
        case 4: 
            printf("a/b=%lf입니다.\n", result);
            break;
        }
 
    }
    return 0;
}