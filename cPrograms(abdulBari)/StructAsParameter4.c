// using call by value and passing a struct which contains array
// usually we cannot pass the array, should use the help of pointer, but the case is different here as array
// is in a structure
#include<stdio.h>
struct test
{
    int a[5];
    int n;
};
void func(struct test t1)// here t1 is the copy of t so both are different
{
    t1.a[0]=10;
}
int main()
{
    struct test t={{1,2,3,4,5},15};
    func(t);
    return 0;
}