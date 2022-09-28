#include<stdio.h>
#include<math.h>
int i,j,n,m,j;
void main()
{
    printf("Enter the number \n");
    scanf("%d",&n);
    printf("1\n");
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d\t",j);
        }
        printf("\n");
    }
    for(m=n-1;m>=1;m--)
    {
        for(j=1;j<=m;j++)
        {
            printf("%d\t",j);
        }
        printf("\n");
    }
}