#include<stdio.h>
void main()
{
    int even[20],odd[20];
    int i,j,n=0;
    int a=0,b=0;
    printf("enter the number of elements in array\n");
    scanf("%d",&n);
    int num[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element: ",i);
        scanf("%d",&num[i]);
    }
    for(j=0;j<n;j++)
    {
        if(num[j] % 2 == 0)
        {
        even[a]=num[j];
        a++;
        }
        else
        {
         odd[b]=num[j];
         b++;
        }   
    }
    printf("The Even elements are\n");
    for(i=0;i<a;i++)
    {
        printf("%d ",even[i]);
    }
    printf("\n");
    printf("The Odd elements are\n");
    for(i=0;i<b;i++)
    {
     printf("%d ",odd[i]);   
    }
    
}