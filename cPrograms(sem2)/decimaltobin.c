//this code works for binary conversion, fine even for octal number conversion
// for that we have to replace 2 by 8 in this code
#include<stdio.h>
#include<string.h>
int main()
{
    int a[10],num,i,j;
    printf("please enter the number\n");
    scanf("%d",&num);
    for(i=0;num>0;i++)
    {
        a[i]=num%2;
        num=num/2;
    }
    printf("The binary number is \n");
    for(j=i-1;j>=0;j--)
    {
        printf("%d",a[j]);
    }
    return 0;
}