// using pascals triangle and only one recursion method to solve
#include<stdio.h>
int C(int n,int r)
{
    if(r==0 || n==r)
    return 1;
    return C(n-1,r-1)+C(n-1,r);
}
int main()
{
    printf("%d",C(6,3));
    return 0;
}