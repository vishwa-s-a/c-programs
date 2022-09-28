// pointers revisiting
#include<iostream>
using namespace std;
int main()
{
    // basic example
    int a=4;
    int *ptr=&a;
    cout<<"The value of a is "<<*(ptr)<<endl;

    //new operator 
    // here we are creating a int variable dynamically and assigning the value to a pointer.
    //int *p = new int(40);
    float *p = new float(45.5);
    cout<<"The value at address p is "<<*(p)<<endl;

    // continous block of memory
    int *arr = new int[3];
    arr[0]=10;
    *(arr+1)=20; // we can assign like this also
    arr[2]=30;
    //delete arr;// here this line deletes the dynamically alloted memory
    // here use delete[] arr to delete the complete array
    cout<<"The value of arr[0] is "<< arr[0]<<endl;
    cout<<"The value of arr[1] is "<< arr[1]<<endl;
    cout<<"The value of arr[2] is "<< arr[2]<<endl;

    //delete operator
    

    return 0;
}