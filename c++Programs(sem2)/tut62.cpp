// file handling with open function
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    ofstream out; // here out is a object of ofstream class
    out.open("sample60.txt");
    out<<"this is me\n";
    out<<"this is me also\n";
    out<<"This is alsi me";
    out.close();

    ifstream in;
    string st, st2;
    in.open("sample60b.txt");
    // in>>st;
    // in>>st2;
    // cout<<st;
    // cout<<st2;

    // to read the complete line from the selected file we use while loop as follows
    while(in.eof()==0)// here eof means end of file
    {
        getline(in,st);
        cout<<st<<endl;

    }
    in.close();
    return 0;
}