#include<stdio.h>
void main()
{
    struct invent
    {
        int a;
        float b;
        char c;
    }man[2], *ptr;
    ptr=man;
    scanf("%d",&ptr->a);
    printf("\n--------------------------------------------");
    printf("%d",ptr->a);
}