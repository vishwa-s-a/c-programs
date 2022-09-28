/*
*   this program converts infix expression to prefix using stack
*   here we basically use infix to postfix program, but we make some modification
*   we first take the input of complete expression and then reverse it and store it in another array,while reversing '(' is converted to ')'
    and ')' is converted to '('
*   then we pass the reversed array into the for loop
*   for reference"https://www.geeksforgeeks.org/convert-infix-prefix-notation/"
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 13// IMPORTANT NOTE BEFORE GIVING EXPRESSION COUNT THE CHARACTERS OF EXPRESSION AND MAKE CHANGES ACCORDINGLY TO MAX VALUE
int count=0;
int i=0;
char postfix[MAX];
char infix[MAX];
char reverse[MAX];
struct stack
{
    char num[MAX];
    int top;
};
typedef struct stack st;
void createStack(st *s)
{
    s->top=-1;
}
int isStackEmpty(st *s)
{
    if(s->top==-1)
    return 1;
    return 0;
}
int isStackFull(st *s)
{
    if(s->top==MAX-1)
    return 1;
    return 0;
}
void push(st *s,char n)
{
    int verify=isStackFull(s);
    if(verify==0)
    {
        s->top=(s->top)+1;
        s->num[s->top]=n;
        count++;
        
    }
    else
    printf("the stack is full,cant do push operation\n");
}
void pop(st *s)
{
    int verify=isStackEmpty(s);
    if(verify==0)
    {
        if((s->num[s->top])!='(')
        {
            postfix[i]=s->num[s->top];
            i++;
        }
        s->top=(s->top)-1;
        count--;
        if((s->num[s->top])=='(')
        pop(s);
    }
    else
    printf("Stack is empty, no element to pop\n");
}
void Reverse(char a[],int n)
{
    int v=0;
    for(int j=n-1;j>=0;j--)
    {
        //printf("%c\n",a[j]);
        if(a[j]==')')
        {
            reverse[v]='(';
        }
        else if(a[j]=='(')
        {
            reverse[v]=')';
        }
        else
        reverse[v]=a[j];
        v++;
    }
}
int main()
{
    st *s;
    s=(st *)malloc(sizeof(st));
    createStack(s);
    printf("Enter the infix expression: \n");
    gets(infix);
    int size=MAX;
    Reverse(infix,size);
    for(int z=0;z<MAX;z++)
    {
        char c=reverse[z];
        if(c=='(' || c=='+' || c=='*' || c=='-' || c=='/')
        push(s,c);
        else if(c==')')
        pop(s);
        else{
            postfix[i]=c;
            i++;
        }
    }
    for(int j=i;j>=0;j--)
    {
        printf("%c ",postfix[j]);
    }
    
    return 0;
}