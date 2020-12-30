#include <stdio.h> 
#include <string.h> 

void sort(char (*ap)[9]); 

void main() 
{ 
	 char animal[5][9]={"dog","elephant","monkey","rabbit","tiger"};
	 char (*ap)[9]; 
	 int i; 
  
	 ap = animal; 
	 sort(ap); 
  
	 for(i=0;i<5;i++){ 
     printf("%s\n",animal[i]); 
     } 
} 

void sort(char (*ap)[9]) 
{ 
	int a,b,i,k; 
	char temp[9]; 
	for(i=0;i<4;i++)
	{ 
	   a = ap[i][0]; 
	   for(k=i+1;k<5;k++)
	   { 
	     b = ap[k][0]; 
		 if(a>b) 
		 { 
		   strcpy(temp,ap[i]); 
		   strcpy(ap[i],ap[k]); 
		   strcpy(ap[k],temp); 
		 } 
		} 
    } 
} 