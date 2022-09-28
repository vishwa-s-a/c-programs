#include <stdio.h>
int main()
{
    int a=45;
    int *ptra=&a;
    int *ptr2=NULL;
    printf(" The value of a is %d\n",a);
    printf(" The value of a is %d\n",*ptra);
    printf("The address of a is %x\n", ptra);
    printf("The address of pointer to a is %x\n",&ptra);
    printf("The address of a is %x\n",&a);
    printf("The value of some garbage value is %x\n",ptr2);
    return 0;
}