// inheritance 
#include<iostream>
using namespace std;

// here this is base class
class Employee
{
    public:
     int id;
    float salary;
    Employee(int s)
    {
        id=s;
        salary=34;

    }
    Employee(){}// default constructor is made as programmer class is going to call this
    //constructor

};

//derived class 
/* syntax
class {{derived-class-name}} : {{visibility-mode}} {{base-class-name}}
{
    class members/methods/etc..
}
notes:
1.default visibility mode is private
2.private visibility mode: public members of the base class becomes
private members of the derived class
3.public visibility mode: public members of the base class becomes 
public members of the derived class
4. private members of the base class cannot be inherited.
*/

//Creating a programmer class derived from Employee base class

class Programmer : Employee
{
    public:
        Programmer(int i)
        {
            id=i;
        }
        int languageCode=9;
        void getdata()
        {
            cout<<id<<endl;
        }
};
int main()
{
    Employee harry(1),rohan(2);
    cout<<harry.salary<<endl;
    cout<<rohan.salary<<endl;
    Programmer skillf(12);
    cout<<skillf.languageCode<<endl;
    skillf.getdata();
    return 0;
}