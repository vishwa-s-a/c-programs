#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<conio.h>
using namespace std;
void login();
void signup();
//void forgot();
int main()
{
    int m;
    cout<<"\t\t\t______________________________________________________________"<<endl;
    cout<<"\t\t\t                     Welcome To Home page                     "<<endl;
    cout<<"\t\t\t______________________________________________________________"<<endl;
    cout<<"\t\t\tPlease enter your choice:\n";
    cout<<"\t\t\t1.Login\n";
    cout<<"\t\t\t2.Sign-up\n";
    cout<<"\t\t\t3.Forgot password\n";
    cout<<"\t\t\t4.Exit\n";
    cin>>m;
    switch (m)
    {
    case 1:
        login();
        break;
    case 2:
        signup();
        break;
    // case 3:
    //     forgot();
    //     break;
    case 4:
        cout<<"\t\t\tThank You\n";
        break;
    default:
        //system("cls");
        cout<<"\t\t\tPlease enter a valid choice\n";
        //system("cls");
        main();
        break;
    
    }
    return 0;
}
void login()
{
    char pwd[12];
    int userid,id,count;
    string p,password="";
    cout<<"Enter your ID: ";
    cin>>userid;
    cout<<"Enter the password: ";
    for(int i=0;i<12;i++)
    {
        pwd[i]=getch();
        cout<<"*";
    }
    cout<<endl;
    for(int i=0;i<12;i++)// here converting character array into string
    {
        password=password+pwd[i];
    }
    ifstream input("user.txt");
    while(input>>id>>p)
    {
        if(id==userid && p==password)
        {
            count=1;
            system("cls");
        }

    }
    if(count==1)
    {
            cout<<userid<<" Login is successfull\n";
            main();
    }
    else
    {
        cout<<"Entered userid and password does not exit\n";
    }
    input.close();
}
void signup()
{
    string a,b,name;
    int c,id,age;
    cout<<"Enter your name : ";
    cin>>name;
    cout<<"Enter your age : ";
    cin>>age;
    cout<<"Enter your UserId is : "<<endl;
    cin>>id;
    cout<<"Password should contain 12 characters, it may contain special characters, numbers\n";
    cout<<"Enter password : ";
    cin>>a;
    ofstream output("user.txt",ios::app);// by adding this ios::app, we can continuously addon data to this file without erasing previous data
    output<<id<<" "<<a<<endl;
    output.close();
    system("cls");
    cout<<"Registration is successfull\n";
    main();

}

