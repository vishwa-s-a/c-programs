// overloading of constructors
#include<iostream>
using namespace std;
class complex
{
    int a,b;
    public:
    complex()// here as it is not having any arguments so when a call has no arguments 
    // then this constructor is invoked
    {
        a=0;
        b=0;
    }
    complex(int x,int y)
    // this is invoked when a call is coming and having 2 arguments
    {
        a=x;
        b=y;
    }
    complex(int x)
    // this is invoked when a call is coming and has only 1 argument.
    {
        a=x;
        b=0;
    }
    void printdata(void)
    {
         cout<<"Your number is "<<a<<"+"<<b<<"i"<<endl;
    }

};
int main()
{
    complex c1(4,6);// invokes 2nd class
    c1.printdata();
    complex c2(9);// invokes 3rd class
    c2.printdata();
    complex c3;// invokes 1st class
    c3.printdata();
    return 0;
}