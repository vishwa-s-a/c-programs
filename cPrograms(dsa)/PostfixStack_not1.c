// useless and primitive program

#include<stdio.h>
#include<stdlib.h>
#define MAX 30
int count=0;
int i=0;
char postfix[MAX];
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
int main()
{
    st *s;
    s=(st *)malloc(sizeof(st));
    createStack(s);
    while('True')
    {
        char c;
        printf("Enter the character: \n");
        fflush(stdin);
        scanf("%c",&c);
        if(c=='q')
        break;
        else if(c=='(' || c=='+' || c=='*' || c=='-' || c=='/')
        push(s,c);
        else if(c==')')
        pop(s);
        else{
            postfix[i]=c;
            i++;
        }
    }
    for(int j=0;j<=i;j++)
    {
        printf("%c ",postfix[j]);
    }
    
    return 0;
}