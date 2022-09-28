// virtual functions. , used to overwrite the default behaviour as base pointer is made to run the 
// functions of derived class.
#include<iostream>
using namespace std;
class Base
{
    public:
        int var1=1;
        virtual void display()// here this virtual word makes the base pointer to go to derived class display function  
        {
            cout<<"1 Displaying base class variable var1 "<<var1<<endl;
        }
};
class Derived: public Base
{
    public:
        int var2=2;
        void display()
        {
            cout<<"2 Displaying base class variable var1 "<<var1<<endl;
            cout<<"2 Displaying derived class variable var2 "<<var2<<endl;
        }
};
int main()
{
   Base *ptr1;
   Base obj1;
   Derived obj2;
   ptr1=&obj2;
   ptr1->display();
    
    return 0;
}