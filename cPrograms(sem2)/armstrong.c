#include <stdio.h>
#include <math.h>
void main()
{
    int num, num1, sum = 0, rem, quo;
    printf("Enter the number\n");
    scanf("%d", &num);
    num1 = num;
    while (num1 > 0)
    {
        quo = num1 / 10;
        rem = num1 % 10;
        sum = sum + pow(rem, 3);
        num1 = quo;
    }
    if (sum == num)
    {
        printf("Armstrong number is verified");
    }
    else
    {
        printf("Armstrong number is not verified");
    }
}