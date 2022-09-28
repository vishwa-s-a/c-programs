#include<stdio.h>
int main()
{
    int n,a,lowest;
    printf("Enter the total number of elements in an array\n");
    scanf("%d",&n);
    int num[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the %d element :",i+1);
        scanf("%d",&num[i]);
    }
    printf("The elements entered are : ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",num[i]);
    }
    printf("\n");
    printf("Enter the element you want to delete\n");
    scanf("%d",&a);
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(num[i]==a)
            {
                num[i]=num[j];
                num[j]=a;
            }

        }
    }
    n=(n-1);
    printf("Elements of the array after deletion of the element is :");
    for(int i=0;i<n;i++)
    {
        printf("%d ",num[i]);
    }

    return 0;

}