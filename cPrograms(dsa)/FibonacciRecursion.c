#include<stdio.h>
int fib(int number)
{
    if(number==0) return 0;
    if(number==1) return 1;
    if(number>=2)
    {
        return(fib(number-1)+fib(number-2));
    }
}
int main()
{
    int num;
    printf("Enter the number : ");
    scanf("%d",num);
    int answer;
    answer=fib(num);
    printf("%d",answer);
    return 0;
}