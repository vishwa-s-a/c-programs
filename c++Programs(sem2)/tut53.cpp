// this pointer
#include<iostream>
using namespace std;
class A
{
    int a;
    int b;// here 'a' and 'b' is a class variable
    public:
        void setData(int a)// here local variable is given preference
        {
            //a=a;// this is a error giving line and we get garbage value
            this->a=a;
        }
        A setData1(int b)
        {
            this->b=b;
            return *this;   
        }
        void getData()
        {
            cout<<"The value of a is "<<a<<endl;
        }
        void getData1()
        {
            cout<<"The value of b is "<<b<<endl;
        }
};
int main()
{
    /*
    'this' is a keyword which is a pointer which points to the object
    which invokes the member function 
    */
    A a,b;
    a.setData(4);
    a.getData();
    b.setData1(5).getData1(); // here the setdata1 func returns object itself so .
    
    
    return 0;
}