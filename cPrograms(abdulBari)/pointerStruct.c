#include<stdio.h>
struct rectangle
{
    int length;
    int breadth;
}*p1,*p2;
int main()
{
    // here both p1 and p2 pointers are stored in stalk
    struct rectangle r1={15,10};
    p1=&r1;
    // now to access the variables of the struct we cannot use
    // p1.length;  here it gives error
    // *p1.length; here this also gives error as . operator has more priority than *
    // (*p1).length; here it works fine but why to have such complexity when we can use
    //p1->length;
    printf("%d\n",r1.length);
    printf("%d\n",p1->length);
    //dynamic memory allocation of structure pointer
    p2=(struct rectangle *)malloc(sizeof(struct rectangle));
    //in c++ we use new keyword for DMA
    // p2=new rectangle;// here we dont have to give struct rectangle on rectangle is enough
    p2->length=65;
    printf("DMA %d",p2->length);
    return 0;
}