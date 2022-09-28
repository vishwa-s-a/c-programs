#include<stdio.h>
#include<stdlib.h>
int findMax(int a[],int n)
{
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    return max;
}
void countSort(int a[],int n)
{
    int i,j,max,*c;
    max=findMax(a,n);
    c=(int *)malloc((max+1)*sizeof(int));
    for(i=0;i<max+1;i++)
    {
        c[i]=0;
    }
    for(i=0;i<n;i++)
    {
        c[a[i]]++;
    }
    i=0;j=0;
    while(i<max+1)
    {
        if(c[i]>0)
        {
            a[j++]=i;
            c[i]--;
        }
        else
        i++;
    }
}
int main()
{
    int a[]={9,7,5,3,2};
    int n=5;
    countSort(a,n);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}