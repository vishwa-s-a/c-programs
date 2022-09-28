#include<iostream>
using namespace std;
class student
{
    string name;
    int reg_no;
    string department;
    float percentage;
    public:
    void setdata(void)
    {
        
        cout<<"name :";
        cin>>name;
        cout<<"Reg no :";
        cin>>reg_no;
        cout<<"Department :";
        cin>>department;
        cout<<"Percentage :";
        cin>>percentage; 
    }
    void check_data(void)
    {
        if(percentage>95)
        cout<<"Your grade is A+"<<endl;
        else if((percentage>=90) && (percentage<=95))
        cout<<"Your grade is A"<<endl;
        else if((percentage>=85) && (percentage<=90))
        cout<<"Your grade is B+"<<endl;
        else if((percentage>=80) && (percentage<=85))
        cout<<"Your grade is B"<<endl;
        else if((percentage>=75) && (percentage<=80))
        cout<<"Your grade is C+"<<endl;
        else if((percentage>=65) && (percentage<=75))
        cout<<"Your grade is C"<<endl;
        else if((percentage>=55) && (percentage<=65))
        cout<<"Your grade is D"<<endl;
        else if((percentage>=45) && (percentage<=55))
        cout<<"Your grade is E"<<endl;
        else if(percentage<=45)
        cout<<"Your grade is F"<<endl;

    }
};
int main()
{
    int n,i;
    cout<<"Enter the total number of students, for collecting their details :"<<endl;
    cin>>n;
    student obj[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter the details of "<<(i+1)<<" student\n";
        obj[i].setdata();
        obj[i].check_data();
    }
    

    return 0;
}