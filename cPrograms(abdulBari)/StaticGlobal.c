#include<stdio.h>
// instead of static variable even if we use global variable
// int x=0;
//then also we get the same output as static and global variable are treated the same
int fun(int n)
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int main()
{
    int r;
    r=fun(5);
    printf("%d\n",r);
    r=fun(5);
    printf("%d",r);
    return 0;
}