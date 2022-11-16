#include<stdio.h>
// we are using iterative method for binary search
int binarySearch(int a[],int size,int target)
{
    int first,middle,last;
    first=0;
    last=size-1;
    while("true")
    {
        middle=(first+last)/2;
        if(a[middle]==target)
        return middle;
        else if(first>=last)
        return -1;
        else if(a[middle]>target)
        last=middle-1;
        else
        first=middle+1;
    }
}
int main()
{
    int arraySize,value,index;
    printf("enter the size of array: ");
    scanf("%d",&arraySize);
    int num[arraySize];
    printf("enter the element for the array: \n");
    for(int i=0;i<arraySize;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("enter the value to search: ");
    scanf("%d",&value);
    index=binarySearch(num,arraySize,value);
    if(index==-1)
    printf("Element is not present in array.\n");
    else
    printf("The element is present at index %d",index);
    return 0;
}