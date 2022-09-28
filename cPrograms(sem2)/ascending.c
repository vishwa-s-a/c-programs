#include<stdio.h>
void main()
{
    int n,i,j,lowest,k;
    int a,b;
    printf("Enter the total number of elements in an array\n");
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        printf("element-%d : ",i);
        scanf("%d",&num[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(num[j]<num[i])
            {
                a=num[i];
                num[i]=num[j];
                num[j]=a;
            }
        }
    }
    printf("The elements of the array in ascending order is \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

}