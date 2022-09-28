#include<stdio.h>
#include<string.h>
#include<math.h>
int count=0;
void arm(int q)
{
    int q1,quo,rem,sum=0;
    q1=q;
    while (q > 0)
    {
        quo = q / 10;
        rem = q % 10;
        sum = sum + pow(rem, 3);
        q = quo;
    }
    //printf("%d\n",sum);
    if (sum==q1)
    {
       count=count+1;
    }
    else
    {
        count=count+0;
    } 
}
void main()
{
    int n,i,ans;
    printf("Enter the total number of elements\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the element\n");
        scanf("%d",&a[i]);
        arm(a[i]);
    }
    printf("The number of armstrong number present is :%d",count);
}