#include<stdio.h>
int F[10];// this is the array which is used for memoization, initialise it with -1 in a separate loop
// this is iterative form of the function
int fib(int n)
{
    int t0=0,t1=1,s=0;
    if(n<=1) return n;
    for(int i=2;i<=n;i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;

    }
    return s;
}

// now we write the recurssive form of the function
int rfib(int n)
{
    if(n<=1) return n;
    return rfib(n-2)+rfib(n-1);
}

// now to use memoization method to reduce the number of steps in recursive call
int mfib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
        F[n-2]=mfib(n-2);
        if(F[n-1]==-1)
        F[n-1]=mfib(n-1);
        return F[n-2]+F[n-1];
    }
}
int main()
{
    for(int i=0;i<10;i++)
    {
        F[i]=-1;
    }
    // printf("%d",rfib(10));
    //printf("%d",rfib(10));
    printf("%d",mfib(10));
    return 0;
}