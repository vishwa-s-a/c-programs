#include<iostream>
#include<string>
using namespace std;
void prime(int x)
{
    int t,flag;
    if(x==0)
    cout<<"It is not a prime number"<<endl;
    else if(x==1)
    cout<<"It is a co-prime number"<<endl;
    else
    {
        for(int i=2;i<x;i++)
        {
            t=x%i;
            if(t==0)
            {
                cout<<"It is not a prime number"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        cout<<"It is a prime number"<<endl;
    }

}
void odd(int x)
{
    if(x%2==0)
    cout<<"It is a even number"<<endl;
    else if(x%2!=0)
    cout<<"It is a odd number"<<endl;
}
void palindrome(int x)
{
    string a="0";
    int quo, rem,num,sum;
    num=x;
    for(int i=0; num>0;i++)
    {
        quo=num/10;
        rem=num%10;
        num=quo;
        a=a+to_string(rem);
    }
    sum=stoi(a);
    if(x==sum)
    cout<<"It is a palindrome"<<endl;
    else
    cout<<"It is not a palindrome"<<endl;
}
int main()
{
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;
    prime(n);
    odd(n);
    palindrome(n);
    return 0;
}