// to get to know know the number of elements in the array we use this formula: {sizeof(array[])/sizeof(array[0])}
// if only sizeof() function is used we only get the bits occupied by the array
#include<stdio.h>
void main()
{
    int i,j,ctr,n=0;
    printf("enter the number of elements in array\n");
    scanf("%d",&n);
    int num[n],gum[n],k=0;
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element: ",i);
        scanf("%d",&num[i]);
    }
    for (i = 0; i < n; i++)
    {
        ctr=1;
        for (j = i + 1; j < n; j++)
        {
            if (num[i] == num[j])
            {
                ctr++;
                gum[j]=-1;
            }
        }
        if(gum[i]!=-1)
        gum[i]=ctr;
    }
    for(i=0;i<n;i++)
    {
        if(gum[i]!=-1)
        {
            printf("%d is repeating %d times\n",num[i],gum[i] );
        }
    }
    
    
}