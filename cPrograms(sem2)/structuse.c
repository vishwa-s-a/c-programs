// use of the structure for solving the problem, of getting various details of the student like name, 
//rollnumber, age having different 
// data types and different sizes.
#include<stdio.h>
int i;
void main()
{
    struct student
    {
        char name[20];
        int rollnumber;
        int age;
    };
    struct student stud[2];
    for(i=0;i<2;i++)
    {
        printf("Enter the details of the student\n");
        printf("details are in the form of name rollnumber age\n");
        fflush(stdin);
        scanf("%s %d %d",&stud[i].name,&stud[i].rollnumber,&stud[i].age);

    }
    printf("The entered details of the student is as follows\n");
    for(i=0;i<2;i++)
    {
        printf("name:%s, rollnumber:%d, age:%d\n",stud[i].name,stud[i].rollnumber,stud[i].age);
    }
}
