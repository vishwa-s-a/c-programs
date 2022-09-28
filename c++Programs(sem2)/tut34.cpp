// copy constructor
// it copies one object into other object
#include<iostream>
using namespace std;
class Number
{
    int a;
    public:
    Number(){
        a=0;
    }// this is default constructor if not added then 
    // we get error when we dont have a default constructor
    Number(int num)
    {
        a=num;
    }
    // making of copy constructor
    Number(Number &obj)// here &obj is reference of a object 
    {
        cout<<"copy constructor is called\n";
        a=obj.a;
    }
    void display()
    {
        cout<<"The number for this object is "<<a<<endl;
    }
};
int main()
{
    Number x,y,z(45),z2;
    z.display();
    x.display();
    y.display();
   
    Number z1(z);// here the copy constructor is invoked successfully
    // here the value of a in z1 object is taken from the value of a of the 
    // object z. this is what copy constructor does.
   
    z1.display();

    z2=z;// copy constructor is not invoked. as in line30 the object z2 is initialized 
    // so cannot be further be once again declared
    z2.display();
    
    Number z3=z;
    z3.display();
    return 0;
}
// when no copy constructor is found, compiler supplies its own constructor
// as compiler has its own default copy constructor.