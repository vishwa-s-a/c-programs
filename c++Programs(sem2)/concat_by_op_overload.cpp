// string concatenation by overloading a '+' operator
#include<iostream>
#include<cstring>
using namespace std;
class String
{
    char a[20];
    public:
        void setdata()
        {
            cout<<"Enter the string :"<<endl;
            cin>>a;
        }
        void display()
        {
            cout<<"String is :"<<a<<endl;
        }
        String operator +(String s)
        {
            String x;
            strcat(a,s.a);
            strcpy(x.a,a);
            return x;
        }

};
int main()
{
    String b,c,d;
    b.setdata();
    c.setdata();
    d=b+c;
    d.display();
    return 0;
}