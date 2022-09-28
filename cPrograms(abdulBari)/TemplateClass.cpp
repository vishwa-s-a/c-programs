// this is a normal class where we use int as data type for the class 
// so in the next file of this name we will convert this int class into template class
// refer TemplateClass2.cpp 
#include<iostream>
using namespace std;
class Arithematic
{
    private:
        int a;
        int b;
    public:
        Arithematic(){}
        Arithematic(int a,int b)// here if we use a,b as the parameter 
        {   //and use the following lines we will get erroraneous answer
            //a=a;
            //b=b;
            // so we use this-> operator
            this->a=a;
            this->b=b;
            // to avoid 'this' usage simply use x,y as parameter in function call() instead of a,b itself
        }
        int add();
        int sub();
};
int Arithematic::add()
{
    return a+b;
}
int Arithematic::sub()
{
    return a-b;
}
int main()
{
    Arithematic r(12,6);
    int x=r.add();
    int y=r.sub();
    cout<<"add: "<<x<<"sub: "<<y<<endl;
    return 0;
}