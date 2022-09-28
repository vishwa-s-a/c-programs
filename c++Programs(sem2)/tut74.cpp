// Function objects: function is wrapped in a class so that it is availabel like an object
// It is a object which acts like a function.
//function objects are also called as functor
#include<iostream>
#include<functional>// required for function objects
#include<algorithm>// required for getting all functions which has certain algorithm to execute 
using namespace std;
int main()
{
    int arr[]={1,73,4,2,54,7};
    cout<<"Elements in increasing order\n";
    //sort(arr,arr+5);// this sort() function is part of algorithm header file
    // here in the above () it sorts first 5 elements in the array in increasing order
    sort(arr,arr+6);// to sort the complete array
    for (int i = 0; i < 6; i++)
    {
         cout<<arr[i]<<endl;
    }
    // now to sort in decending order
    cout<<"Elements in decending order\n";
    sort(arr,arr+6,greater<int>());// here greater<int>() is a functor
    for (int i = 0; i < 6; i++)
    {
         cout<<arr[i]<<endl;
    }
    
    return 0;
}