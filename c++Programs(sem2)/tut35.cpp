// destructors (once run the program to see the results)
// destructor never takes an argument nor does it return any value
#include<iostream>
using namespace std;
int count=0;
class num
{
    public:
    num()
    {
        count++;
        cout<<"This is the time when constructor is called for object number "<< count<<endl;
    }
    // below lines is creating destructor and ~ is called tilde
    ~num()
    {
        cout<<"This is the time when my destructor is called for object number "<< count<<endl;
        count--;
    }

};
int main()
{
    cout<<"We are inside our main function"<<endl;
    cout<<"Creating first object n1"<<endl;
    num n1;
    // below we have created a block, once we are out of this block
    // then the objects created in the block when we are running the block are destroyed on their own
    {
        cout<<"Entering this block\n";
        cout<<"Creating two more objects\n";
        num n2,n3;
        cout<<"Exiting this block\n";

    }
    // here before it goes to next line the n2,n3 are destroyed and then 
    // execution moves to next part of main program
    cout<<"Back to main\n";
    // after this the destructor for n1 object is also called so we get the following 
    // line in last of the program

    return 0;
}
// when it is required the compiler creates the object and when 
// it realises that the object is not useful then it destroys the object