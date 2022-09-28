// demonstration of call by reference in c++, this is way similar to C's call by reference where we use pointers
// here we use reference method
// here int a,*b; here a is a normal variable, then *b is a pointer variable then 
// if int &c=b; then here c is a reference variable only used in c++ and it cannot be declared alone , it has to be initialized in the first go.
// reference doesn't take any memory as it is just another name for a existing variable
#include<stdio.h>
#include<iostream>
using namespace std;
void swap(int &x,int &y)// here x becomes reference to a and y becomes reference to b and reference means alias;
{
    int temp=x;
    x=y;
    y=temp;
}
int main()
{
    int a,b;
    a=10;
    b=20;
    int &c=b;
    cout<<c<<endl;
    swap(a,b);// here a,b are actual parameters
    cout<<a<<endl<<b;   
    return 0;
}