// this program converts infix expression to postfix using stack
// here the input is complete infix expression and not a single character which was previously collected in PostfixStack.c
#include<stdio.h>
#include<stdlib.h>
#define MAX 21
int count=0;
int i=0;
char postfix[MAX];
char infix[MAX];
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
        if(s->num[s->top] !='(')
        {
        postfix[i]=s->num[s->top];
        i++;
        }
        s->top=(s->top)-1;
        count--;
    }
    else
    printf("Stack is empty, no element to pop\n");
}
int operand(char c)
{
    switch(c)
    {
        case('+'):
        return 1;
        break;
        case('-'):
        return 1;
        break;
        case('*'):
        return 2;
        break;
        case('/'):
        return 2;
        break;
        case('^'):
        return 3;
        break;
        default:
        return 0;
    }
}
void pred(st *s,char c)
{
    if(isStackEmpty(s)==0)
    {
        while('true')
        {
            if((s->top)>=0 && (operand(c)<=operand(s->num[s->top])))
            {
                    pop(s);
            }
            else 
            {
            push(s,c);
            break;
            }
            
        }
    }
    else
    push(s,c);
}

int main()
{
    st *s;
    s=(st *)malloc(sizeof(st));
    createStack(s);
    printf("Enter the infix expression: \n");
    gets(infix);
    for(int v=0;v<MAX;v++)
    {
        char c=infix[v]; 
        if(c=='(' )
        push(s,c);
        else if(c=='+' || c=='*' || c=='-' || c=='/'|| c=='^')
        {
            pred(s,c);
        }
        else if(c==')')
        {
            while(s->num[s->top]!='(')
            {
            pop(s);
            }
            if(s->num[s->top]=='(')
            pop(s);
        }    
        else{
            postfix[i]=c;
            i++;
        }
    }
    while(isStackEmpty(s)==0)
    pop(s);
    for(int j=0;j<=i;j++)
    {
        printf("%c",postfix[j]);
    }
    return 0;
}
