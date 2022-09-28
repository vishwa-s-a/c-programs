// abstract base class and pure virtual functions 
#include<iostream>
#include<cstring>
using namespace std;
// this type of base class is referred as abstract base class, these classes are created so we can derive 
// other classes from this B class and objects
// in abstract base class, minimum one pure virtual function is present 
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
        // here we are creating display function as it is going to be overwritten in the derived class
        // so we can define it as 
        virtual void display()=0;// now it is a do-nothing function--> also known as pure virtual function
        // once it is defined as virtual then in derived class display function should be defined
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
