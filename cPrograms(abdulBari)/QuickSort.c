#include<stdio.h>
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[], int l, int h)
{
    int pivot=a[l];
    int i=l,j=h;
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if(i<j)
        {
            swap(&a[i],&a[j]);
        }
    }while(i<j);
    swap(&a[l],&a[j]);
    return j;
}
void quickSort(int a[],int l,int h)
{
    int j;
    if(l<h)
    {
        j=partition(a,l,h);
        quickSort(a,l,j);//here we have to use j-1 but j th element acts as infinity for the first list
        quickSort(a,j+1,h);
    }
}
int main()
{
    // here int32_max is must as it acts as infinity 
    int b[]={11,13,7,12,16,9,24,5,10,3,__INT32_MAX__};// here __INT32_MAX__ acts as infinity as it is the highest 32 bit integer
    int size=sizeof(b)/sizeof(b[0]);//size of the array
    quickSort(b,0,size-1);
    for(int i=0;i<size-1;i++)//here if size is given then int32_max is printed so dont give
    printf("%d,",b[i]);

    return 0;
}