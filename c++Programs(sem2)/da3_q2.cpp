#include<iostream>
using namespace std;
class c1
{
    float rad;
    float height;
    public:
        void cube()
        {
            cout<<"Enter the side length of cube :"<<endl;
            cin>>rad;
            cout<<"The area of the cube is :"<<(rad * rad)<<endl;
            cout<<"The volume of the cube is :"<<(rad * rad * rad)<<endl;
        }
        void sphere()
        {
            cout<<"Enter the radius of the sphere :\n";
            cin>>rad;
            cout<<"The area of the sphere is :"<<(4 * 3.14 * rad * rad )<<endl;
            cout<<"The volume of the sphere is :"<<((4/3) * 3.14 * rad * rad * rad)<<endl;
        }
        void cylinder()
        {
            cout<<"Enter the radius of the cylinder :\n";
            cin>>rad;
            cout<<"Enter the height of the cylinder :\n";
            cin>>height;
            cout<<"The area of the cylinder is :"<<((44/7) * rad * (rad + height)) <<endl;
            cout<<"The volume of the cylinder is :"<<(22/7 * rad * rad * height)<<endl;
        }
};
int main()
{
    int n;
    cout<<"Enter the following choice for further operation\n";
    cout<<"The operations are:\n";
    cout<<"1.Area and Volume of cube\n";
    cout<<"2.Area and Volume of sphere\n";
    cout<<"3.Area and Volume of cylinder\n";
    cin>>n;
    switch(n)
    {
        case 1:
            c1 obj1;
            obj1.cube();
            break;
        case 2:
            c1 obj2;
            obj2.sphere();
            break;
        case 3:
            c1 obj3;
            obj3.cylinder();
            break;


    }
    return 0;

}