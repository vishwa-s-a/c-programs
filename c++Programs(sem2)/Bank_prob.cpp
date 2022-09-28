// here this program is illustration of constructor chain where we have added three constructors in chain
// so last constructor will call second last constructor which will finally calls last constructor
// CurrentAccount()->SavingsAccount()->Account()  order of the call


// Bank account problem.
#include<iostream>
using namespace std;
class Account
{
    protected:
        int balance;
    public:
        Account(){}
        Account(int x)
        {
            balance=x;
        }
        void setdata()
        {
            cout<<"Enter the balance of the account"<<endl;
            cin>>balance;
        }
        void display()
        {
            cout<<"The balance of the account is "<<balance<<endl;
        }
};
class SavingsAccount:public Account
{
    public:
        double rate;
        SavingsAccount()
        {
            rate=0.08;
        }
        SavingsAccount(int x,double y):Account(x)// constructor calls another constructor 
        {
            rate=y;
        }
        void interest()
        {
            balance=balance+(balance*rate);
        }
};
class CurrentAccount:public SavingsAccount
{
    public:
        int minimum;
        int read;
        CurrentAccount(){}
        CurrentAccount(int c)
        {
            minimum=c;
        }
        CurrentAccount(int c,int x,double y):SavingsAccount(x,y)
        {
            minimum=c;
        }
        void withdraw()
        {
            if(balance>minimum)
            {
                cout<<"Enter the amount to be withdrawn"<<endl;
                cin>>read;
                balance=balance-read;

            }
        }
};
int main()
{
    CurrentAccount obj;
    obj=CurrentAccount(1000,1500,0.18);
    obj.interest();
    obj.display();
    obj.withdraw();
    obj.display();
    return 0;
}