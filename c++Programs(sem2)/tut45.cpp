// virtual base class demonstration
#include<iostream>
using namespace std;

/*
student --> test 
student--> sports
test---->result
sports-->result
*/
class student
{
    protected:
        int roll_no;
    public:
        void set_number(int a)
        {
            roll_no=a;
        }
        void print_number(void)
        {
            cout<<"Your roll number is "<<roll_no<<endl;
        }

};

class test : virtual public student
{
    protected:
        float maths,physics;
    public:
        void set_marks(float m1,float m2)
        {
            maths=m1;
            physics=m2;
        }
        void print_marks(void)
        {
            cout<<"Your result is :"<<endl
                <<"Maths: "<<maths<<endl
                <<"Physics: "<<physics<<endl;
        }
};

class sports : public virtual student
{
    protected:
        float score;
    public:
        void set_score(float sc)
        {
            score=sc;
        }
        void print_score(void)
        {
            cout<<"Your Pt score is "<<score<<endl;
        }
};

class result : public test, public sports
{
    private:
        float total;
    public:
        void display(void)
        {
            total=maths+physics+score;
            print_number();
            print_marks();
            print_score();
            cout<<"Your total score is: "<<total<<endl;
        }

};

int main()
{
    result harry;
    harry.set_number(420);
    harry.set_marks(78.9, 99.5);
    harry.set_score(9);
    harry.display();
    return 0;
}