// here we will convert the class into template so we can use any data type and get the same work done
#include<iostream>
using namespace std;
template<class T>
class Arithematic
{
    private:
        T a;
        T b;
    public:
        Arithematic(){}
        Arithematic(T a,T b)
        {
            this->a=a;
            this->b=b;
        }
        T add();
        T sub();
};// here the scope of template ends so again for the bottom part of code we should again define the template
template<class T>
T Arithematic<T>::add()
{
    return a+b;
}
template<class T>
T Arithematic<T>::sub()
{
    return a-b;
}
int main()
{
    // fisrt we create a int class template
    Arithematic<int> r(12,6);
    int x=r.add();
    int y=r.sub();
    cout<<"add: "<<x<<endl<<"sub: "<<y<<endl;
    cout<<"float class template"<<endl;
    //second we create float class template
    Arithematic<float>r1(12.6,2.3);
    float z=r1.add();
    float q=r1.sub();
    cout<<"add: "<<z<<endl<<"sub "<<q<<endl;
    return 0;
}