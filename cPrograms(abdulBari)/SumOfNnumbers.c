// using recursions to find sum of n natural number 
#include<stdio.h>
int sumOfN(int n)
{
    int sum=0;
    if(n>0)
    {
        sum=n+sumOfN(n-1);
    }
    return sum;
}
int main()
{
    printf("%d",sumOfN(6));
    return 0;
}