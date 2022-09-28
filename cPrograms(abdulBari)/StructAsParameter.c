/*
* here we will use call by value method to pass the structure to a function
* due to this method now we have formal and actual parameters
* so changes done in parameter will not affect the other, as both are different copies
*/
#include<stdio.h>
struct rectangle
{
    int length;
    int breadth;
};
int area(struct rectangle x)// so changes made here in this section will not affect the actual parameters
{
    return((x.length)*(x.breadth));
}
int main()
{
    struct rectangle r={10,15};
    printf("the area of the rectangle is %d",area(r));
    return 0;
}