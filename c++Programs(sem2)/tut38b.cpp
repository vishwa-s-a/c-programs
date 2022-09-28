// here we are going to declare the derived class as private
// to see how the code works form the tut38.cpp file
#include<iostream>
using namespace std;

class Base
{
    int data1;// private by default and is not inherited
    public:
        int data2;
        void setData();
        int getData1();
        int getData2();
    
};

void Base::setData(void)
{
    data1=10;
    data2=100;
}

int Base::getData1()
{
    return data1;
}

int Base::getData2()
{
    return data2;
}

class Derived : Base// class is derived privately
{
    int data3;
    public:
        void process();
        void display();
};

void Derived::process()
{
    setData();
    data3=data2*getData1();// here data2 is in public section of base class so it is derived as public in derived class as we have given 
    // visibility mode as public
}

void Derived::display()
{
    cout<<"Value of data 1 is "<<getData1()<<endl;
    cout<<"Value of data 2 is "<<data2<<endl;
    cout<<"Value of data 3 is "<<data3<<endl;
    
}
int main()
{
    Derived der;
    //der.setData();
    der.process();
    der.display();
    return 0; 
}