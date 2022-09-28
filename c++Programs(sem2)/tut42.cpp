// exercise for solve
/*
create 2 classes:
    1.simple calculator: takes input of 2 numbers using a utility
    functions and performs +,-,*,/ and displays the result using 
    another function
    2.scientific calculator: takes input of 2 numbers using a utility
    function and performs any four scientific operation of your
    choice and displays the results using another function.

    create another class hybridCalculator and inherit it using these 2 classes:
    Q1. What type of inheritance are you using?  ans: multiple inheritance
    Q2. Which mode of inheritance are you using? ans: public calculator, public scientific
    Q3. Create an object of hybridCalculator and display results of simple and 
    scientific calculator
    Q4. how is code reusability implemented ans:
*/
#include<iostream>
#include<cmath>
using namespace std;

class calculator
{
   int a,b;
   public:
        void getdata1()
        {
            cout<<"Enter the value of a"<<endl;
            cin>>a;
            cout<<"Enter the value of b "<<endl;
            cin>>b;
        }
        void display1()
        {
            cout<<"The sum of the 2 numbers is "<<a+b<<endl;
            cout<<"The subtraction of the 2 numbers is "<<a-b<<endl;
            cout<<"The multiplication of the 2 numbers is "<<a*b<<endl;
            cout<<"The division of the 2 numbers is "<<a/b<<endl;

        }
};

class scientific
{
   int a,b;
   public:
        void getdata2()
        {
            cout<<"Enter the value of a"<<endl;
            cin>>a;
            cout<<"Enter the value of b "<<endl;
            cin>>b;
        }
        void display2()
        {
            cout<<"The value of cos(a) is "<<cos(a)<<endl;
            cout<<"The value of sin(a) "<<sin(a)<<endl;
            cout<<"The value of exp(a) "<<exp(a)<<endl;
            cout<<"The value of tan(a) "<<tan(a)<<endl;

        }
};

class hybrid : public calculator, public scientific
{

};
int main()
{
    hybrid calc;
    calc.getdata1();
    calc.display1();
    calc.getdata2();
    calc.display2();

    return 0;
}