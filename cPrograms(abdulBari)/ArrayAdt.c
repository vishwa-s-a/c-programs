//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void display(struct Array arr1)//for displaying this works fine(call by value)
{
    int v;
    printf("Elements are\n");
    for(v=0;v<arr1.length;v++)
    {
        printf("%d\n",arr1.A[v]);
    }
}
void append(struct Array *arr1,int x)//for modifying we use call by reference
{
    if(arr1->length<arr1->size)
    {
        arr1->A[arr1->length++]=x;
    }
}
void insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index<arr->length)
    {
        for(i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}
int delete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
       x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    return x;
}
int main()
{
    int n;
    struct Array arr;
    printf("enter the size of the array: ");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    //arr.length=0;
    printf("Enter number of numbers");
    scanf("%d",&n);
    arr.length=n;
    printf("Enter all elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    display(arr);
    append(&arr,10);
    display(arr);
    //printf("length: %d\n",arr.length);
    insert(&arr,3,20);
    display(arr);
    printf("%d\n",delete(&arr,4));
    display(arr);
    return 0;
}