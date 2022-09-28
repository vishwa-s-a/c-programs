#include<iostream>
using namespace std;
class Employee
{
    private:
    int a,b,c;
    public:
    int d;
    void setdata(int a1,int b1,int c1);
    void getdata()
    {
        cout<<"The value of a is "<<a<<endl;
        cout<<"The value of b is "<<b<<endl;
        cout<<"The value of c is "<<c<<endl;

    }
   
};
void Employee::setdata(int a1,int b1,int c1)
{
    a=a1;
    b=b1;
    c=c1;
}
int main()
{
    Employee harry;
    harry.setdata(12,13,14);
    harry.getdata();
    harry.d=10;

return 0;
    
}