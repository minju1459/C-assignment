#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void) 
{ 
 	int nums[10];
	int i,k ;
 	srand(time(NULL));
 	for(i=0; i<10; i++)
	{
 		nums[i]=(rand()%10)+1;
		for(k=0; k<i; k++)
 	    {
			if (nums[i]==nums[k])
			{
 				i--;
	 			break;
	 		}
	    }
 	}
    for(i=0; i<10; i++)
 	{
		printf("%d\n", nums[i]);
 	}
 	return 0;
} 