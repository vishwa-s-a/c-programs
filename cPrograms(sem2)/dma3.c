// use of realloc
#include<stdio.h>
#include<stdlib.h>

int main()
{
    // here we allocate a memory block using calloc and then we reallocate it
    int *ptr;
    int n;
    printf("Enter the size of the array you want to create\n");
    scanf("%d",&n);
    ptr=(int *) calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter the value no %d of this array\n",i);
        scanf("%d",&ptr[i]);// here pointer arithematics is used and use ptr just as array 
    }
    for(int i=0;i<n;i++)
    {
        printf("The value at %d of this array %d\n",i, ptr[i]);
        
    }

    // use of realloc()
    printf("Enter the size of the new array you want to create\n");
    scanf("%d",&n);
    ptr=(int *) realloc(ptr,n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        printf("Enter the new value no %d of this array\n",i);
        scanf("%d",&ptr[i]);// here pointer arithematics is used and use ptr just as array 
    }
    for(int i=0;i<n;i++)
    {
        printf("The new value at %d of this array %d\n",i, ptr[i]);
        
    }
    free(ptr);
    return 0;
}