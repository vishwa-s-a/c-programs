#include<iostream>
#include<cstring>
using namespace std;
class CWH
{
    protected:
        string title;
        float rating;
    public:
        CWH(string s,float r )
        {
            title=s;
            rating=r;
        }
        virtual void display(){
            // here this function will not run as we have given virtual keyword
            //cout<<"Bogus code"<<endl;
        }
};

class CWHvideo:public CWH
{
    float videolength;
    public:
        CWHvideo(string s, float r,float vl ) : CWH(s,r)
        {
            videolength=vl;
        }
        void display()
        {
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings "<<rating<<" Out of 5 stars"<<endl;
            cout<<"Length of this video is: "<<videolength<<" minutes"<<endl;  
        }
};

class CWHtext:public CWH
{
    int words;
    public:
        CWHtext(string s, float r,int w ) : CWH(s,r)
        {
            words=w;
        }
        // if any one of the display in the derived class is not defined then the pointer runs 
        // the display function of base class
        void display(){
            cout<<"This is an amazing video with title "<<title<<endl;
            cout<<"Ratings "<<rating<<" Out of 5 stars"<<endl;
            cout<<"No of words in this text tutorial is: "<<words<<" words"<<endl;
        }
};
int main()
{
    string title;
    float rating,vlen;
    int words;

    // for code with harry video
    title="C++ tutorial";
    vlen=4.56;
    rating=4.89;
    CWHvideo Cvideo(title,rating,vlen);
    //Cvideo.display();

    //for code with harry text
    title="C++ tutorial Text";
    words=433;
    rating=4.19;
    CWHtext Ctext(title,rating,words);
    //Ctext.display();

    CWH *tuts[2];// creating 2 base class pointers and if virtual keyword is not used for display func of 
    // base class then these below lines will point to this display function of base class.
    tuts[0]=&Cvideo;
    tuts[1]=&Ctext;
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}
/*
rules for virtual functions
1. they cannot be static
2. they are accessed by object pointers(i.e this pointers)
3. virtual fucntions can be a friend of another class
4. a virtual function in base class might not be used.
5. if a virtual function is defined in a base class, there is no necessity of redefining it in the derived 
class
6. if a function is not defined in the derived class then it goes to base class function to do the task of function
of the base class  here in the above example if display function of any  derived class is removed then we get output 
based on display function present in the base class 
*/