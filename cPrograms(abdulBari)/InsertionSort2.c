#include<stdio.h>
void insertionSort(int a[],int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void display(int a[],int n)
{
    printf("[");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("]");
}
int main()
{
    int a[]={11,13,7,2,6,9,4,5,10,3};
    int n=10;
    insertionSort(a,10);
    display(a,10);
    return 0;
}