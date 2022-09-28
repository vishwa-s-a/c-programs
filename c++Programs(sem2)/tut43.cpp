// ambiguity resolution 1
#include<iostream>
using namespace std;
class base1
{
    public:
        void greet()
        {
            cout<<"How are you?"<<endl;

        }
};

class base2
{
    public:
        void greet()
        {
            cout<<"Kaise ho?"<<endl;
        }
};

class derived : public base1, public base2
{
    int a;
    public:
    // here we are giving clarity that when we call greet() function from
    // derived class then use greet() of base1 class
        void greet()
        {
            base1::greet();   
        }
};
int main()
{
    base1 base1obj;
    base2 base2obj;
    base1obj.greet();
    base2obj.greet();
    derived d;
    d.greet();// here ambiguity is created and compiler is confused what to use.

    return 0;
}