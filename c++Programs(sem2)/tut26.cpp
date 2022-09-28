// friend functions
// compiler doesnt allow any function to access the private data of a class
// 
#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    // here we are using friend function to give permission to foreign function to
    // access the private data of complex, it doesnt mean this foreign funciton will become 
    // member of the function
    friend complex sumComplex(complex o1, complex o2);
    void printNumber()
    {
        cout << "Your number is " << a << "+" << b << "i" << endl;
    }
};
// here if this function is not declared in the class then we get error;
// thats why we make this function a friend function of class
complex sumComplex(complex o1, complex o2) // here function has return type of a object so complex is added in begining
{
    complex o3;
    o3.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    complex c1, c2, sum;
    c1.setNumber(1, 4);
    c1.printNumber();

    c2.setNumber(5, 8);
    c2.printNumber();

    sum = sumComplex(c1, c2);
    sum.printNumber();
    return 0;
}
//------------------------------------------------
/* properties of friend functions
1. not in the scope of class
2. since it is not in the scope of the class, it cannot be called from the objects of
that class .   c1.sumComplex()-----is invalid
3. can be invoked without the help of any object.
4. usually contains the objects as arguments
5. can be declared inside public or private part of the class
6. it cannot access the members diectly by their names and need object_name.member_name 
to access any member.

*/