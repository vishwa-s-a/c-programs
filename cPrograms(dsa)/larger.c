// without using the array to sort the three items. just to use the if conditions
#include<stdio.h>
int main()
{
    // to arrange the numbers in the ascending order
    int a,b,c;
    int temp;
    printf("Enter the three numbers :\n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b)
    {
        temp=a;
        a=b;
        b=temp;
        if(b>c)
        {
            temp=b;
            b=c;
            c=temp;
            if(a>b)
            {
                temp=a;
                a=b;
                b=temp;
            }
        }
    }
    else if(b>c)
    {
        temp=b;
        b=c;
        c=temp;
    }
    printf("order: %d,%d,%d",a,b,c);
    return 0;
}