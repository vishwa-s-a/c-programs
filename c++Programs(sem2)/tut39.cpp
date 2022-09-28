#include<iostream>
using namespace std;

class base
{
    protected:// here int a is kept private in this class and further if 
    // required we can take int a in any derived class
        int a;
    private:
        int b;


};
/*                    public derivation    private derivation   protected derivation
1.private members     not inherited           not inherited       not inherited
2.protected members    protected                 private            protected
3.public members       public                    private            protected

*/

class derived: protected base
{

};
int main()
{
    base b;
    derived d;
    cout<<d.a;// it will not work since a is protected in both base as well as derived class

    return 0;
}