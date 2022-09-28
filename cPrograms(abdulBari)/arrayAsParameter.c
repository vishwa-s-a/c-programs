#include<stdio.h>
// in below arguments we can also use  int p[]. this specifically used for showing that passed parameter is a array
// other wise in general we can use int *p, which can point to both integer and array
void display(int *p,int n)// here n is the length of the array, we should pass it separately.
{
    printf("the elements of the array are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",p[i]);// instead of below lines we can use this line as simple as possible
        //printf("%d\n",*p);
        //p++;
    }
}
// to demonstrate int b[] instead of int *b. here b[] can be used efficiently to modify the element
void modify(int b[],int n)
{
    for(int i=0;i<n;i++)
    {
        b[i]=b[i]+10;
    }
}
int main()
{
    int a[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    display(a,5);
    modify(a,5);
    display(a,5);
    return 0;
}