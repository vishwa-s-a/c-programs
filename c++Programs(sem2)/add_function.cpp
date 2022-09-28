#include<iostream>
using namespace std;
class complex
{
    public:
        int a,b;
        complex(){}
        complex(int x, int y)
        {
            a=x;
            b=y;
        }
        //complex add(complex,complex);
        void display()
        {
            cout<<"The complex number is "<<a<<"+"<<b<<"i"<<endl;
        }
};
complex add(complex x,complex y)
{
    complex z;
    z.a=x.a+y.a;
    z.b=x.b+y.b;
    return(z);
}
int main()
{
    complex c1,c2(3,2),c3;
    c1=complex(2,3);
    c3 = add(c1,c2);
    c1.display();
    c2.display();
    c3.display();

    return 0;
}