// using call by reference using '*'
#include<stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
int area(struct rectangle *x)// here we are actually acccessing the original parameters of the structure, so we can modify the varaibles
{
    return((x->length)*(x->breadth));
}
int main()
{
    struct rectangle r={10,15};
    printf("the area of the rectangle is %d",area(&r));
    return 0;
}