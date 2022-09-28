#include<stdio.h>
// this fun is a tail recursion function,as first printing is done and then call is taking place
void fun(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        fun(n-1);
    }
}
//this func2 is a head recursion function,as first call is taking place then printing when all calls are returned
void func2(int n)
{
    if(n>0)
    {
        func2(n-1);
        printf("%d ",n);
    }
}
int main()
{
    int x=3;
    fun(x);
    printf("\n");
    func2(x);
    return 0;
}