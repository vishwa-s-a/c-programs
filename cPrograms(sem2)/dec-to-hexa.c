#include<stdio.h>
#include<string.h>
int main()
{
    int a[20],num,i,j,rem;
    printf("please enter the number\n");
    scanf("%d",&num);
    for(i=0;num>0;i++)
    {
        rem=num%16;
        num=num/16;
        if(rem<=9)
        a[i]=rem;
        else{
            if(rem==10)
                a[i]='A';
            else if(rem==11)
                a[i]='B';
            else if(rem==12)
                a[i]='C';
            else if(rem==13)
                a[i]='D';
            else if(rem==14)
                a[i]='E';
            else
                a[i]='F';

        }

    }
    printf("The binary number is \n");
    for(j=i-1;j>=0;j--)
    {
        if(a[j]<=9)
        printf("%d",a[j]);
        else
        printf("%c",a[j]);
    }
    return 0;
}