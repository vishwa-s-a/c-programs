// pointers to objects and arrow operators
#include<iostream>
using namespace std;
class Complex
{
    int real, imaginary;
    public:
        void getdata()
        {
            cout<<"The real part is "<<real<<endl;
            cout<<"The imaginary part is "<<imaginary<<endl;
        }
        void setdata(int a , int b)
        {
            real=a;
            imaginary=b;
        }
};
int main()
{
    Complex c1;
    Complex *ptr = &c1;
    // instead of above 2 lines we can use
    // Complex *ptr = new Complex;
    (*ptr).setdata(1,54); //parenthesis is must
    // use of arrow operator
    //(*ptr).getdata(); , instead of this we can use 
    ptr->getdata();


    // array of objects
    Complex *ptr1=new Complex[4];// creates array of 4 objects
    ptr1->setdata(1,4);
    ptr1->getdata();
    (ptr1+1)->setdata(2,5);
    (ptr1+1)->getdata();

    
    return 0;
}