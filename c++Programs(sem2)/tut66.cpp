// class templates with default parameters
#include<iostream>
using namespace std;

template<class T1=int,class T2=float,class T3=char>
class vishwa
{
    public:
        T1 a;
        T2 b;
        T3 c;
        vishwa(T1 x,T2 y,T3 z)
        {
            a=x;
            b=y;
            c=z;
        }
        void display()
        {
            cout<<"The value of a is "<<a<<endl;
            cout<<"The value of b is "<<b<<endl;
            cout<<"The value of c is "<<c<<endl;
        }
};
int main()
{
    vishwa <> v(4,4.6,'c');  //following the default arguments
    // here we are intentionally leaving the angular brackets empty
    // as we have already given default parameters
    v.display();
    cout<<endl;
    vishwa<float,char,char> g(9.9,'o','t');// giving our own arguments
    g.display();
    return 0;
}