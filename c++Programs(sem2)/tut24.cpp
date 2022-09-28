// static variables cannot be written inside the class.
// when ever a static variable is initialized then its default value is 0;
// so no need of declaring it again as 0;
// here the static count is shared by all objects of the class
// so the count is going as 0,1,2,3,...
// else, if count was declared as normal variable then for every object we get from 0,1,2,...
// as it is a static variable then we get 0,1,2,3,... continously for all objects.
//static variable is also termed as class variable,as it is linked to the class and rather than
// linking to the object
// life time of the static variable is only upto termination of the variable
// if we have to initialize the value of static variable to 1000 then we do this
// int Employee::count=1000;
// here static variables come under static data variables
//--------------------------------------------------------
// static functions are created only when we want a function which can only access all static data members
//some times we want to create a function which will run without any object,and runs from class itself
// static function only has access to other static function and variables
#include<iostream>
using namespace std;
class Employee
{
    int id;
    static int count;
    public:
    void setdata(void){
        cout<<"Enter the id of the employee"<<endl;
        cin>>id;
        count++;
    }
    void getdata(void)
    {
        cout<<"The id of this employee is "<<id<<" and this is employee number "<<count<<endl;
    }
    static void getcount(void){
        cout<<"The value of count is "<<count<<endl; 
    }

};

int Employee::count;//default value is zero;
// here count is the static data member of class Employee   
int main()
{
    Employee harry,rohan,lovish;
    //harry.id=1; cannot do this as id and count are private
    harry.setdata();
    harry.getdata();
    Employee::getcount();// here as it is a static function it is called without any object

    rohan.setdata();
    rohan.getdata();
    Employee::getcount();
    lovish.setdata();
    lovish.getdata();
    Employee::getcount();
    return 0;
} 