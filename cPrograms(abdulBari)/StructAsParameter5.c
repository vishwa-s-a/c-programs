// here we will return structure to a function
#include<stdio.h>
#include<stdlib.h>
struct rectangle
{
    int length;
    int breadth;
};
struct rectangle * func()
{
    struct rectangle *p;
    p=(struct rectangle *)malloc(sizeof(struct rectangle));
    p->length=34;
    p->breadth=59;
    return p;
}
int main()
{
    struct rectangle *ptr;
    ptr=func();
    printf("Length is %d\n Breadth is %d",ptr->length,ptr->breadth);
    return 0;
}