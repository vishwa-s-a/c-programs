#include<stdio.h>
void display(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",array[i]);

    }
    printf("\n");
}
void BubbleSort(int array[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    display(array,size);
}
int main()
{
    int num[]={-2,45,0,11,-9};
    int size=sizeof(num)/sizeof(num[0]);
    BubbleSort(num,size);
    printf("The sorted array is : \n");
    display(num,size);
    return 0;
}