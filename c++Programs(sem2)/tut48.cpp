// constructors in derived classes and their order.
#include<iostream>
using namespace std;
/*
case 1:
class B:public A
{
    order of execution of constructor
    first A() and B()
};

case2:
class A: public B,public C
{
    //order of execution of constructor-> B() then C()and A()
};

case3:
class A: public B,virtual public C
{
    // order of execution of constructor -> C() then B() and A()
};

*/

class Base1
{
    int data1;
    public:
        Base1(int i)
        {
            data1=i;
            cout<<"Base 1 class constructor is called"<<endl;
        }
        void printDataBase1(void)
        {
            cout<<"The value of data 1 is "<<data1<<endl;
        }
};

class Base2
{
    int data2;
    public:
        Base2(int i)
        {
            data2=i;
            cout<<"Base 2 class constructor is called"<<endl;
        }
        void printDataBase2(void)
        {
            cout<<"The value of data 2 is "<<data2<<endl;
        }
};

class Derived : public Base1 , public Base2{ // here the order depends on this line
    int derived1 , derived2 ;
    public:
        Derived(int a,int b,int c,int d): Base1(a),Base2(b)
        {
            derived1=c;
            derived2=d;
            cout<<"Derived class constructor called "<<endl;
        }
        void printDataDerived(void)
        {
            cout<<"The value of derived 1 is "<<derived1<<endl;
            cout<<"The value of derived 2 is "<<derived2<<endl;
        }
};
int main()
{
    Derived harry(1,2,3,4);
    harry.printDataBase1();
    harry.printDataBase2();
    harry.printDataDerived();
    return 0;
}