// function templates and function templates with parameters
#include<iostream>
using namespace std;
float funcAverage(int a, int b)
{
    float avg=(a+b)/2.0;
    return avg;

}
// instead of creating these many functions we simply create a template which takes data type as arguments
template<class T>// here already a swap function exists in standard iostream
void swapp(T &a, T &b) // so we name the function as swapp
{
    T temp=a;
    a=b;
    b=temp;

}


template <class T1, class T2>
float funcAverage2(T1 a, T2 b)
{
    float avg=(a+b)/2.0;
    return avg;

}
int main()
{
    float a;
    a=  funcAverage2(5,2);
    printf("The average of these numbers is %0.3f\n",a);
    int x=5,y=9;
    swapp(x , y);
    cout<<x<<endl<<y;
    return 0;
}