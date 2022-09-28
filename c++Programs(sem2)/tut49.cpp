// initialization list in constructors
#include<iostream>
using namespace std;
/*
syntax for initialization list in constructor:
constructor(argument-list):initialization-section
{
    assignment + other code;
}

class test
{
    int a;
    int b;
    public:
        test(int i,int j) : a(i),b(j)
        { constructor - body}

}
*/

class test
{
    int a;
    int b;
    public:
        //test(int i,int j) : a(i),b(j)
        //test(int i,int j) : a(i),b(i+j)
        //test(int i,int j) : a(i),b(2*j)
        // test(int i,int j) : b(j),a(i+b)--> RED flag this will create problems because
        // a will be initialized first
        //test(int i,int j) : a(i),b(a+j)
        test(int i,int j): a(i),b(i+j)
        { 
           //b=j;
           cout<<"Constructor is executed"<<endl;
           cout<<"Value of a is "<<a<<endl;
           cout<<"value of b is "<<b<<endl; 
        }

};

int main()
{
    test t(6,4);

    return 0;
}

