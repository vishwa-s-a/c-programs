#include<iostream>
using namespace std;
class matrix
{
    int a[3][3];
    public:
    void setdata()
    {
        cout<<"Enter the elements of the 3x3 matrix"<<endl;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    friend matrix operator +(matrix, matrix);
    friend matrix operator -(matrix, matrix);
    void display()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }
};
matrix operator +(matrix c, matrix d)
{
    matrix x;
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                x.a[i][j]=c.a[i][j]+d.a[i][j];
            }
        }
    return(x);
}

matrix operator -(matrix c, matrix d)
{
    matrix x;
    for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                x.a[i][j]=c.a[i][j]-d.a[i][j];
            }
        }
    return(x);
}

int main()
{
    matrix o1,o2,o3,o4;
    o1.setdata();
    o2.setdata();
    o3=o1+o2;
    cout<<"The first matrix is\n";
    o1.display();
    cout<<"The second matrix is\n";
    o2.display();
    cout<<"The sum of the matrices is\n";
    o3.display();
    o4=o1-o2;
    cout<<"The subtraction of the matrices is\n";
    o4.display();
    return 0;
}