#include<stdio.h>

int main()
{
	char name[80];
	int sn,kor,eng,mat;
	char group;
	int total;
	double average;

	scanf("%s", name);
	scanf("%d", &sn);
	scanf("%d", &kor);
	scanf("%d", &eng);
	scanf("%d", &mat);
	scanf(" %c", &group);

	printf("  ┌─────────────────────────────────────────────────┐\n");
	printf("  │                   1학기 성적표                  │\n");
	printf("  └─────────────────────────────────────────────────┘\n");
	printf("\n");
	printf("%22c조,학번:%d번,이름(%s)\n", group, sn, name);
	printf("\n");
	
	total= kor + eng + mat;
	average= total / 3.0;

	printf("  ┌─────────┬─────────┬─────────┬─────────┬─────────┐\n");
	printf("  │   국어  │   영어  │   수학  │   총점  │   평균  │\n");
	printf("  ├─────────┼─────────┼─────────┼─────────┼─────────┤\n");
	printf("  │%9d│%9d│%9d│%9d│%9.2lf│\n",kor,eng,mat,total,average);
	printf("  └─────────┴─────────┴─────────┴─────────┴─────────┘\n");

	
    return 0;
}


