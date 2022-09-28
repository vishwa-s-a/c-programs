#include<stdio.h>
void main()
{
    int a,b;
    char c;
    printf("Welcome to Simple Calculator\n");
    printf("Please only enter integers for simple calculations\n");
    printf("Enter the Two numbers as a,b for Calculation\n");
    scanf("%d,%d",&a,&b);
    printf("____________________________________\n");
    printf("|operators   | Their operations     |\n");
    printf("|------------|----------------------|\n");
    printf("|     +      |to add 2 numbers      |\n");
    printf("|     -      |to subtract 2 numbers |\n");
    printf("|     *      |to multiply 2 numbers |\n");
    printf("|     /      |to divide 2 numbers   |\n");
    printf("|------------|----------------------|\n");
    printf("Please enter the operator which you want to use\n");
    fflush(stdin);
    scanf("%c",&c);
    switch(c)
    {
        case '+':
        printf("The sum of the numbers is :%d",a+b);
        break;
        case '-':
        printf("The subtraction of the numbers is :%d",a-b);
        break;
        case '*':
        printf("The multiplication of the numbers is :%d",a*b);
        break;
        case '/':
        printf("The division of the numbers is :%d",a/b);
        break;
        
    }

}
    