#include <stdio.h>
void main()
{
    int i, j,n,ctr=0;
    printf("Enter the number of elements for the array\n");
    scanf("%d", &n);
    int num[n];
    for (i = 0; i < n; i++)
    {
        printf("Element-%d: ", i);
        scanf("%d", &num[i]);
    }
    printf("Different elements present in the array are \n");
    for(i=0;i<n;i++)
    {
        ctr=0;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                if(num[i]==num[j])
                ctr++;
            }
        }
        if (ctr==0)
        printf("%d\n",num[i]);
    }
}
