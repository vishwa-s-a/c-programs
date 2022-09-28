#include<stdio.h>
int main()
{
    printf("Lets learn about pointers\n");
    int a=76;
    int *ptr=&a;
    int *ptr1;
    int *ptr2=NULL;
    printf("The value of a is %d\n",*ptr);
    printf("The value of address of a is %x\n",ptr);
    printf("The value of a is %x\n",&a);
    printf("The value in ptr1 is %p\n",ptr1);
    printf("The value of ptr2 is %p\n",ptr2);
    

    return 0;
}