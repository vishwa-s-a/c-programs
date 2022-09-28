#include<stdio.h>
void main()
{
    int m,n,i,j,k,sum=0;
    printf("Input the size of the square matrix (less than 5): ");
    scanf("%d",&m);
    n=m;
    int a[m][m],b[m][m],c[m][m];
    printf("Input elements in the first matrix :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Element-[%d],[%d] : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Input elements in the second matrix :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("Element-[%d],[%d] : ",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    printf("The first matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("The second matrix is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            sum=0;
            for(k=0;k<m;k++)
            {
                sum=sum+(a[i][k]*b[k][j]);
                c[i][j]=sum;
            }
        }
    }
    printf("The multiplication of two matrices is :\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}