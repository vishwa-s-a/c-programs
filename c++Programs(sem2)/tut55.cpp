// pointers to derived classes here 1 means base and 2 means derived class
#include<iostream>
using namespace std;
class Base
{
    public:
        int var1;
        void display()
        {
            cout<<"Displaying base class variable var1 "<<var1<<endl;
        }
};
class Derived: public Base
{
    public:
        int var2;
        void display()
        {
            cout<<"Displaying base class variable var1 "<<var1<<endl;
            cout<<"Displaying derived class variable var2 "<<var2<<endl;
        }
};
int main()
{
    // here base class pointer points to a derived class. here if we run display function from the
    //pointer(which is pointing to the derived class),
    // then the display function of base class is run not the derived class display function
    // here in run time it decided which function should be run for which call
    Base *ptr1;// it is a base class pointer
    Base obj1;
    Derived obj2;
    ptr1=&obj2;// base class pointer pointing to derived class
    ptr1->var1=34;
    //ptr->var2=123;// will throw error 
    ptr1->display();
    Derived *ptr2;// derived class pointer(can access both base and derived class members)
    ptr2=&obj2;
    ptr2->var2=98;
    ptr2->var1=9800;
    ptr1->display();
    ptr2->display();
    
    return 0;
}