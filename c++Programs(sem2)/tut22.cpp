// main part of this tutorial is nesting of function when we have declared it as a private function then we call this function by public
// function
#include<iostream>
#include<string>
using namespace std;
class binary
{
    private:
    string s;
    void chk_bin(void);

    public:
    void set(void);
    void ones(void)
    {
        chk_bin();
        cout<<"The inter-changed number is\n";
        for(int i=0;i<s.length();i++)
        {
            if((s.at(i))=='0'){
            s.at(i)='1';
            cout<<s.at(i);
            continue;
            }
            else if((s.at(i))=='1')
            {
                s.at(i)='0';
                cout<<s.at(i);
            }
            
        }
    }

};
void binary::set(void)
{
    cout<<"enter the binary number"<<endl;
    cin>>s;
}
void binary::chk_bin(void)
{
    for(int i=0;i<s.length();i++)
    {
        if((s.at(i)!='0') && (s.at(i)!='1'))
        {
            cout<<"Entered number is not binary\n";
            exit(0);
        }
    }
}
int main()
{
    binary harry;
    harry.set();
    //harry.chk_bin(); // this cannot be done in this way as it is a private function so we have to nest the function
    harry.ones();
    return 0;

}