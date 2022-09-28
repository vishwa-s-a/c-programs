// friend classes
#include<iostream>
using namespace std;
// forward declaration is used to tell the compiler that so and so class is present 
// in bellow codes
class complex;

class Calculator
{
    public:
    int add(int a,int b)
    {
        return (a+b);
    }
    int sumRealComplex(complex ,complex );
    // if we define this function completely then compiler will not 
    // know what is complex o1.a, or o2.a as it is completely unaware of objects;
};
class complex
{
    int a, b;
    // here we are making function of a one class as friend of another class
    // here below code is a example;
    // here we are individually declaring functions as friend 
    friend int Calculator :: sumRealComplex(complex o1,complex o2);
    // this line can be commented out if we declaring the whole class
    //as a friend of one class 

    //Alternative method is : declaring the entire calculator class as friend
    friend class Calculator;
    public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void printNumber()
    {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};
int Calculator :: sumRealComplex(complex o1,complex o2)
{
    return (o1.a+o2.a);
}

int main()
{
    complex o1,o2;
    o1.setNumber(1,4);
    o2.setNumber(5,7);
    Calculator calc;
    int res;
    res=calc.sumRealComplex(o1,o2);
    cout<<"The sum of the real part of o1 and o2 is "<<res<<endl;
    return 0;
}