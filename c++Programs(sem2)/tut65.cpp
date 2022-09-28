// class templates with multiple parameters
#include<iostream>
using namespace std;
/*
syntax for class templates with multiple parameters(one,two or more than two):
template <class T1, class T2,...(comma separated)>
class nameofclass
{
    code
};

*/
template<class T1,class T2>
class myClass
{
    public: 
        T1 data1;
        T2 data2;
        myClass(T1 a,T2 b)
        {
            data1=a;
            data2=b;
        }
        void display()
        {
            cout<<this->data1<<endl<<this->data2;
        }
};
int main()
{
    myClass <int,float>obj1(1,1.8);
    obj1.display();
    
    
    return 0;
}