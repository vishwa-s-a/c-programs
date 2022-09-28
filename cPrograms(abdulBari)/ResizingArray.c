#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,*q;
    p=(int *)malloc(5*sizeof(int));
    p[0]=1;p[1]=2;p[2]=3;p[3]=4;p[4]=5;
    // here we can use realloc method to increase or decrease the size of array and retain the old values which 
    // were present in the array as done in above line of code
    p=(int *)realloc(p,10*sizeof(int));// here even though the size increases the elements of the array previously given are retained
    for(int i=0;i<10;i++)
    {
        printf("%d\n",p[i]);
    }
    return 0;
}