// maps in c++
// map is an associative array and used to store key-value pairs(example studentName-marks) 
#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, int> marksMap;  
    marksMap["Harry"]=98;
    marksMap["Rohan"]=2;
    marksMap["jack"]=59;
    marksMap.insert({{"vishwa",56},{"ram",99}});//another method to add on to map
    map<string,int>:: iterator itr;
    for (itr=marksMap.begin();itr!=marksMap.end(); itr++)
    {
        cout<<(*itr).first<<" "<<(*itr).second<<endl;// firt goes to key and second goes to value
    }
    
    cout<<"The size is: "<<marksMap.size();
    return 0;
}