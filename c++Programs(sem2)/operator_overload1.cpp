// binary operators using member functions
#include<iostream>
using namespace std;
class complex
{
    public:
        int a,b;
        complex(){}// default constructor
        complex(int x, int y)
        {
            a=x;
            b=y;
        }
        complex operator +(complex);// it is member function so we can give only one argument,(if it was a friend function
        // then we could have passed 2 arguments without any error)
        void display()
        {
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<endl;
        }
};
complex complex:: operator +(complex c)
{
    complex t;
    t.a=a+c.a;
    t.b=b+c.b;
    return (t);
}
int main()
{
    complex c1,c2(3,2),c3;
    c1=complex(2,3);
    c3=c1+c2;
    c1.display();
    c2.display();
    c3.display();

    return 0;
}