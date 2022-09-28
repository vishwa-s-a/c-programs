#include <stdio.h>
#include <string.h>
#include <math.h>
void main()
{
    char num,a[30]={0};
    int i,j=0,sum1,sum=0;
    printf("Enter the number\n");
    scanf("%s", &a);
    for (i = (strlen(a) - 1); i >= 0; i--)
    {
        if (isdigit(a[i]))
        {
            sum1=((a[i]-48) * pow(16, j));
            sum = sum + sum1;
            j = j + 1;
        }
        else
        {
            num=toupper(a[i]);
            if(num=='A')
            sum=sum+(10*pow(16,j));
            else if(num=='B')
            sum=sum+(11*pow(16,j));
            else if(num=='C')
            {sum=sum+(12*pow(16,j));
            }
            else if(num=='D')
            sum=sum+(13*pow(16,j));
            else if(num=='E')
            sum=sum+(14*pow(16,j));
            else
            sum=sum+(15*pow(16,j));

            j=j+1;
        }
    }
    printf("the decimal number is %d",sum);
}
