#include <stdio.h>

double ary_min(double*);

int main(){
	
	double ary[]={1.5,20.1,16.4,2.3,3.5};
	double res;

	res=ary_min(ary);
	printf("배열의 최솟값: %.1lf\n",res);

	return 0;
}
double ary_min(double*ap)
{
	int i;
	double min;

	min=ap[0];
	for(i=1;i<5;i++){
		if(ap[i]<min)  min=ap[i];
	}
	return min;
}