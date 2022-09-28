//doing binary search using recursion
#include<stdio.h>
int BinSearch(int array[],int l,int f,int target)
{
    if(l>=f){
    int m=(l+f)/2;
    printf("first: %d\nlast: %d\nmiddle: %d\n",f,l,m);
    if(target==array[m])
    return m;
    if(array[m]>target)
    return BinSearch(array,m-1,f,target);
    return BinSearch(array,l,m+1,target);
    }
    return -1;
}
int main()
{
    int num[]={4,9,12,17,23,28,99};
    int index=BinSearch(num,6,0,28);
    if(index==-1) printf("Element not found.");
    else printf("The element found at index: %d",index);
    return 0;
}