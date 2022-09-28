// member function templates and overloading template function
#include<iostream>
using namespace std;

template<class T>
class Harry
{
    public:
        T data;
        Harry(T a)
        {
            data=a;
        }
        void display();
       
};
template<class T>
void Harry<T>:: display()
{
    cout<<data<<endl;
}

void func(int a)
{
    cout<<"I am first func() "<<a<<endl;
}

template <class T>
void func(T a)
{
    cout<<"I am templatised func() "<<a<<endl;
}
int main()
{
    Harry<float> h(5.7);
    Harry<char> g('c');
    //cout<<h.data<<endl;  
    h.display();
    g.display();
    func(4);// exact match takes the highest priority 
    func(4.3);// here no match is foung so template function is followed
    return 0;
}