// binary operators using friend functions
#include<iostream>
using namespace std;
class complex
{
    int a,b;
    public:
        complex(){}// default constructor
        complex(int x, int y)
        {
            a=x;
            b=y;
        }
        friend complex operator +(complex,complex);
        void display()
        {
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<endl;
        }
};
complex operator +(complex c, complex d)
{
    complex t;
    t.a=c.a+d.a;
    t.b=c.b+d.b;
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