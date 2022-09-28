// ambiguity resolution 2
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
 
class b
{
    public:
        void say()
        {
            cout<<"Hello world"<<endl;
        }
};

class d:public b
{
    int a;
    public:
        void say()
        {
            cout<<"Hello my beautiful people"<<endl;
        }
};
int main()
{
   b vish;
   d ram;
   vish.say();
   ram.say();

   return 0;
}