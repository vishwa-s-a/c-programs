// multiple inheritance
// here we can create derived class from more than 2 base class, not compulsory
// to use only 2 base class.
#include<iostream>
using namespace std;

/*
syntax of multiple inheritance
class derived: visibility-mode base1,visibility-mode base2
{
    class body of class "derived"
};
*/

class base1
{
    protected:
        int base1int;
    public:
        void set_base1int(int a)
        {
            base1int=a;
        }
};

class base2
{
    protected:
        int base2int;
    public:
        void set_base2int(int a)
        {
            base2int=a;
        }
};

class base3
{
    protected:
        int base3int;
    public:
        void set_base3int(int a)
        {
            base3int=a;
        }
};

class derived : public base1, public base2,  public base3
{
    public:
        void show()
        {
            cout<<"The value of Base1 is "<<base1int<<endl;
            cout<<"The value of Base2 is "<<base2int<<endl;
            cout<<"The value of Base3 is "<<base3int<<endl;
            cout<<"The sum of these values is "<<base1int+base2int+base3int<<endl;
        }
};

/*
the inherited derived class will look something like this
data members:
    base1int-->protected
    base2int-->protected
member functions:
    set_base1int()-->public
    set_base2int()-->public
    show()-->public
*/
int main()
{
    derived harry;
    harry.set_base1int(25);
    harry.set_base2int(23);
    harry.set_base3int(2);
    harry.show();
    return 0;
}