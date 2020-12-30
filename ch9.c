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
    printf("============<�޴�>============\n");
    printf("1.    ����\n");
    printf("2.    ����\n");
    printf("3.    ����\n");
    printf("4.    ������\n");
    printf(">>���ϴ� ������ �����ϼ���: ");
}

double add()
{
    double a, b, res;
    system("cls");
    printf("=======<���� ������ �����մϴ�.>=======\n");
    printf("�� ���� ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf%lf", &a, &b);
    res = a + b;
    return res;
}
double sub()
{
    double a, b, res;
    system("cls");
    printf("=======<���� ������ �����մϴ�.>=======\n");
    printf("�� ���� ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf%lf", &a, &b);
    res = a - b;
    return res;
}
double mul()
{
    double a, b, res;
    system("cls");
    printf("=======<���� ������ �����մϴ�.>=======\n");
    printf(">>�� ���� ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf%lf", &a, &b);
    res = a * b;
    return res;
}
double diff()
{
    double a, b, res;
    system("cls");
    printf("=======<������ ������ �����մϴ�.>=======\n");
    printf(">>�� ���� ���ڸ� �Է��ϼ���: ");
    scanf_s("%lf%lf", &a, &b);
    res = a / b;
    return res;
}

void res_display(double val)
{
    printf("a b=%lf�Դϴ�.\n", val);
}

int cac()
{
    char ing;
    int selection;
    double a, b, result=0;
    while (1)
    {
        system("cls");
        printf("============<�޴�>============\n");
        printf(">>1.    ����\n");
        printf(">>2.    ����\n");
        printf(">>3.    ����\n");
        printf(">>4.    ������\n");
        printf("�޴� ��ȣ�� �����Ͻÿ� \n");
        scanf_s(" %d", &selection);
        if (selection > 4 || selection < 1)
        {
            printf("�����Դϴ�.\n");
            system("pause");
            continue;
        }
        printf("�� ���� ���� �Է��Ͻÿ� \n");
        scanf_s("%lf%lf", &a, &b);
        switch (selection)
        {
        case 1:
            printf("a-b=%lf�Դϴ�.\n", result);
            break;
        case 2:
            printf("a-b=%lf�Դϴ�.\n", result);
            break;
        case 3: 
            printf("a*b=%lf�Դϴ�.\n", result);
            break;
        case 4: 
            printf("a/b=%lf�Դϴ�.\n", result);
            break;
        }
 
    }
    return 0;
}