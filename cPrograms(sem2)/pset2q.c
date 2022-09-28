#include<stdio.h>
#include<math.h>
int n,i;
float sum=0.0;
int main()
{
    printf("Enter the number for the summation of the series\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        sum=sum+(1/(pow(n,i)));
        printf("%f\n",sum);

    }
    printf("the sum of the summation is %f",sum);
    return 0;
}
