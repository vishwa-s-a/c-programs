// multilevel inheritance: 
#include<iostream>
using namespace std;

class student
{
    protected:
        int roll_number;
    public:
        void set_roll_number(int r)
        {
            roll_number=r;
        }
        void get_roll_number(void);

};

void student::get_roll_number() // here :: is called as scope resolution operator
{
    cout<<"The roll number is "<<roll_number<<endl;
}

class exam : public student
{
    protected:
        float maths;
        float physics;
    public:
        void set_marks(float, float);
        void get_marks(void);
};

void exam::set_marks(float m1,float m2)
{
    maths=m1;
    physics=m2;
}

void exam::get_marks()
{
    cout<<"The marks obtained in maths are "<<maths<<endl;
    cout<<"The marks obtained in physics are "<<physics<<endl;
}

class result: public exam
{
    float percentage;
    public:
        void display_result()
        {
            get_roll_number();
            get_marks();
            cout<<"Your percentage is "<<(maths+physics)/2<<"%"<<endl;
        }

};

int main()
{
    result harry;
    harry.set_roll_number(420);
    harry.set_marks(90.5, 94.0);
    harry.display_result();
    return 0;
}
/*
notes:
    if we are inheriting b from a and c from b. [a-->b-->c]
    1. a is the base class for b, and b is the base class for c
    2. [a-->b-->c] is called inheritance path
*/