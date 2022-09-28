// files input and output
#include<iostream>
#include<fstream>// this is for file handling classes so useful to i/o files
/*
the useful classes for working with files in c++ are:
1. fstreambase--> it is a base class
2. ifstream--> derived from fstreambase
3. ofstream--> derived from fstreambase
all these three come under one header file named as fstream

in order to work with files in c++, you will have to open it. primarily, there are 2 ways to open
a file
1. using the constructor
2. using the member function open() of the class
*/
using namespace std;
int main()
{
    string st,str2;
    st="Harry Bhai";
     //opening files using constructor  and writing it. here out and in are just objects so we can name
     //it however we want.
    ofstream out("sample60.txt");// write operation
    out<<st;
    

    /*
    // opening files using constructor and reading it
    ifstream in("sample60b.txt");// read operation
    //in>>str2;  here this line only copies first word from the file so we use getline function
    getline(in,str2);
    cout<<str2;
    */
    return 0;
}
/*
* read operation                
    ifstream in("This.txt");
    string st;
    in>>st;  just like cin
*write operation
    ofstream out("this.txt");
    string st="Harry";
    out<<st;  writes to a file this.txt
*/