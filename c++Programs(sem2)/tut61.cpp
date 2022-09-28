#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    // connecting our file with hout stream
    ofstream hout("sample60.txt");

    // creating a name variable and filling it with the string entered by the user
    cout<<"Enter your name ";
    string name;
    cin>>name;

    // writhng a string to the file
    hout<<"My name is "+name;
    hout.close(); //this line closses the file which was connected in above lines
    
    ifstream hin("sample60.txt");
    string content;
    hin>>content;
    cout<<"The content of this file is\n"<<content;
    hin.close();
    return 0;
}