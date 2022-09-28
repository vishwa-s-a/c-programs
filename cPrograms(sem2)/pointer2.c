#include<stdio.h>
// pointer arithmetic
int main()
{
    int arr[10];
    for(int i=0;i<5;i++)
    {
        scanf("%d",arr+i);// here instead of writing &a[i] we have used pointer concept
        // as arr is a pointer which points to arr[0]. then arr has the address of a[0]
    }
    for(int i=0;i<5;i++)
    {
        printf("%d",*(arr+i));// here we use deference operator for getting value.
    }
    return 0;
}