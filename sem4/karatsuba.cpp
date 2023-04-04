#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int getSize(long num)
{
    int count=0;
    while(num>0)
    {
        count++;
        num/=10;
    }
    return count;
}
long karatsuba(long x, long y)
{
    //base case
    if(x<10 && y<10)
    return x*y;

    //determine the size of x and y
    int size=fmax(getSize(x), getSize(y));

    //split x and y
    int n=(int)ceil(size/2.0);
    long p=(long)pow(10,n);
    long a=(long)floor(x/(double)p);
    long b=x%p;
    long c=(long)floor(y/(double)p);
    long d=y%p;

    //recure until base case
    long ac=karatsuba(a,c);
    long bd=karatsuba(b,d);
    long e=karatsuba(a+b,c+d)-ac-bd;

    //return equation
    return (long)(pow(10*1L,2*n)*ac+pow(10*1L,n)*e+bd);
}
int main()
{
    long a,b;
    printf("Name: Vishwa Shivanand Appaji\nReg No:21BCI0026\n");
    printf("Enter the number which has to be multiplied: ");
    scanf("%ld,%ld",&a,&b);
    printf("product of 2 numbers is :%ld\n",karatsuba(a,b));
}