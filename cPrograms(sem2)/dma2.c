// use of calloc
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d",&n);
    ptr=(int *) calloc(n,sizeof(int));
    for(int i=0;i<n-1;i++)
    {
        printf("Enter the value no %d of this array\n",i);
        scanf("%d",&ptr[i]);// here pointer arithematics is used and use ptr just as array 
    }
    for(int i=0;i<n;i++)
    {
        printf("The value at %d of this array %d\n",i, ptr[i]);
        
    }
    return 0;
}