// parameterized constructor and default constructor
#include <iostream>
using namespace std;
class complex
{
    int a, b;

public:
    complex(int x, int y); // declaration of a constructor
    void printdata(void)
    {
        cout << "Your number is " << a << "+i" << b << endl;
    }
};
// definition of the constructor
complex ::complex(int x, int y) // this is a parameterized constructor
{
    a = x;
    b = y;
}
int main()
{
    // we have 2 methods to pass the arguments for the parameterized constructors
    // this is implicit call
    complex a(4,6);
    
    // this is explicit call
    complex b = complex(5,7); 
    a.printdata();
    b.printdata();
    return 0;
}