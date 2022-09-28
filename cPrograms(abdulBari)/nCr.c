// using factorial
#include<stdio.h>
int fact(int n)
{
    if(n==0) return 1;
    return n*fact(n-1);
}
int C(int n,int r)
{
    int den,num;
    num=fact(n);
    den=fact(r)*fact(n-r);
    return num/den;
}
int main()
{
    printf("%d",C(5,2));   
    return 0;
}