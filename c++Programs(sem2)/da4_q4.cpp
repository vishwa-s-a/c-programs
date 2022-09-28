// operator overloading concept
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
            cout<<a<<endl;
        }
        String operator +(String s)
        {
            String x;
            strcat(a,s.a);
            strcpy(x.a,a);
            return x;
        }
        String operator -(String s)
        {
            String x;
            strcpy(x.a,s.a);
            return x;
        }
        int operator !()
        {
            int m;
            m=strlen(a);
            return m;
        }
        String operator <(String q)
        {
            String z;
            strcpy(z.a,strrev(q.a));
            return z;
        }

};

int main()
{
    String b,c,d,e,f;
    b.setdata();
    cout<<"The length of first string is "<<!b<<endl;
    c.setdata();
    cout<<"The length of second string is "<<!c<<endl;
    f=b<c;
    cout<<"Reverse of the string is "<<endl;
    f.display();
    d=b+c;
    cout<<"The concatenated string is \n";
    d.display();
    e= b-c;
    cout<<"The copy of string is  \n";
    e.display();
    return 0;
}