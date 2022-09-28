#include<stdio.h>
int factorial(int num)
{
    if (num==1 || num==0)
    {
        return 1;
    }
    else{
        return(num*factorial(num-1));
    }

}
int main()
{
    int num;
    printf("enter the number \n");
    scanf("%d",&num);
    printf("The factorial of the number  is= %d",factorial(num));

}