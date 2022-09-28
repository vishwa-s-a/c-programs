// the is constructor chain program 
// where a constructor of one class calls another constructor of another class
// here a constructor of secondary class calls a constructor of primary class
#include<iostream>
using namespace std;
class Primary
{
    public:
        int balance;
        Primary(int x)
        {
            balance=x;
        }
       
};
class Secondary: public Primary
{
    public:
        double rate;
        Secondary(int x, float y) : Primary(x)
        {
            rate=y;
            cout<<"Done"<<endl;
        }
        void display()
        {
            cout<<"The entered balance is "<<balance<<endl;
            cout<<"The entered rate "<<rate<<endl;
        }
};
int main()
{
    Secondary obj(1200,0.08);   
    obj.display();
    return 0;
}