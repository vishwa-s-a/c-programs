#include<iostream>
using namespace std;
class simple
{
   int data1,data2;
   public:
   simple(int a,int b=9)
   {
     data1=a;
     data2=b;
   }  
   void printdata();
};
void simple::printdata()
{
    cout<<"The value of data is "<<data1<<" and "<<data2<<endl;
}
int main()
{
    simple s(1,4);// when both values are given then it goes with given value, rather than default values
    simple q(7);// when only one value is passed then it makes use of default value given by user
    s.printdata();
    q.printdata();
    return 0;
}
