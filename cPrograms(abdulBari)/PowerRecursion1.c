#include<stdio.h>
int pow(int m, int n)
{
    if(n==0)
    return 1;
    else
    return m*pow(m,n-1);
}
// this function is more efficient than above function
int pow1(int m,int n)
{
    if(n==0)
    return 1;
    if(n%2==0)
    return pow(m*m,n/2);
    else
    return m*pow(m*m,(n-1)/2);
}
int main()
{
    printf("%d",pow1(2,9));

    return 0;
}