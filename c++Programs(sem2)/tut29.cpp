// constructors 
#include<iostream>
using namespace std;

class complex
{// creating a constructor
 // constructor is a special member function with same name as of the class
 // it is used to initialize the objects of its class
 // it is automatically invoked whenever an object is created
 // constructor has no return value
 int a,b;
 public:
 complex(void);// declaration of a constructor
 void printdata(void){
     cout<<"Your number is "<<a<<"+i"<<b<<endl;
 }
};
// definition of the constructor
complex :: complex(void)// this is a default constructor as it accepts no parameters 
// which does not take any input
{
    a=10;
    b=19;
    cout<<"Hello World \n";
}
int main()
{
    complex c1,c2,c3;
    c1.printdata();
    c2.printdata();   
    c3.printdata();
    return 0;
}
/*
characteristics of the constructors
1. it should be declared in the public section of the class
2. they are automatically invoked whenever the object is created
3. They cannot return values and do not have return types
4. It can have default arguments
5. we cannot refer to their address
*/