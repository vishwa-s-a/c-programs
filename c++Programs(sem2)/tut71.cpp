// vector in STL(standard template library)
// in arrays the size is fixed and cannot be varied but in vectors it manages the change in size itself
// so we can continuously add on elements  
// refer c++ vector methods in google and follow cplusplus website
//link for the same is https://m.cplusplus.com/reference/vector/vector/
#include<iostream>
#include<vector>
using namespace std;
template <class T>
void display(vector<T> &v)
{
    for(int i=0;i<v.size();i++)// size(),a member function of vector, returns the size of the vector
    {
        cout<<v[i]<<" ";
        //instead of above sentence we can also use member function of vector both do same task
        //cout<<v.at(i)<<" ";
    }
    cout<<endl;
}
int main()
{
    // ways to create vector
    vector <int> vec1;// zero length vector
    vector<char> vec2(4);// 4-element character vector
    vector<char> vec3(vec2);//4-element character vector from vec2
    vector<int> vec4(6,3);// 6-element vector of 3s
    display(vec4);
    int element,m;
    cout<<"Enter the size of the vector\n";
    cin>>m;
    for (int i = 0; i <m; i++)
    {
        cout<<"Enter an element to add to this vector\n";
        cin>>element;
        vec1.push_back(element);
    }
    //vec1.pop_back();
    display(vec1);
    vector<int>::iterator iter=vec1.begin();// it points to the first element in the vector
    vec1.insert(iter,5,566);// here insert takes a iterator as argument so here iter is a iterator
    //vec1.insert(iter+1,566)// here it insert the 566 number at second position
    // vec1.insert(iter+1,4,566) // here it inserts 4 copy of 566 starting from second position
    display(vec1);
    return 0;
}