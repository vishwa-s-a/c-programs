//Name:vishwa shivanand appaji
//Reg no:21BCI0026
// in switch case statements if return statement are not there, then put break statement
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 50
int j=0;
char infix[MAX],postfix[MAX],final[MAX];
struct stack
{
    char arr[MAX];
    int top;
    int count;
};
typedef struct stack st;
void create(st *s)
{
    s->top=-1;
    s->count=0;
}
int space(char m)
{
    if(m==' ' || m=='\t')
    return 1;
    return 0;
}
int isEmpty(st *s)
{
    if(s->top==-1)
    return 1;
    return 0;
}
int isFull(st *s)
{
    if(s->top==MAX-1)
    return 1;
    return 0;
}
void push(st *s,char m)
{
    if(!isFull(s))
    {
        (s->top)++;
        s->arr[s->top]=m;
        (s->count)++;
    }
    else
    printf("Stack is full\n");
}
char pop(st *s)
{
    if(!isEmpty(s))
    {
        char temp;
        temp=s->arr[(s->top)];
        (s->top)--;
        return temp;
    }
    else{
        printf("Stack is empty\n");
        return '\0';
    }
}
int precedence(char m)
{
    switch(m)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;

    }
}
void intoPost(st *s)
{
    char next;
    char symbol;
    for(int i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(!space(symbol))
        {
            switch(symbol)
            {
                case '(':
                    push(s,symbol);
                    break;
                case ')':
                    while((next=pop(s))!='(')
                    postfix[j++]=next;
                    break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    while(!isEmpty(s) && precedence(symbol)<=precedence(s->arr[s->top]))
                        postfix[j++]=pop(s);
                    push(s,symbol);
                    break;
                default:
                    postfix[j++]=symbol;

            }
        }
    }
    while (!isEmpty(s))
    {
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';// add null character to mark the end of the character array
    
}
int post_eval(st *s)
{
    int a,b;
    for(int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]>='0'&& postfix[i]<='9')
        {
            push(s,postfix[i]);
        }
        else{
            a=pop(s)-'0';
            b=pop(s)-'0';
            switch(postfix[i])
            {
                case '+':
                    push(s,(b+a)+'0');
                    break;
                case '-':
                    push(s,(b-a)+'0');
                    break;
                case '*':
                    push(s,(b*a)+'0');
                    break;
                case '/':
                    push(s,(b/a)+'0');
                    break;
                case '^':
                    push(s,pow(b,a)+'0');
                    break;
            }
        }
    }
    return pop(s)-'0';
}
int main()
{
    int i=0;
    int result;
    st *s;
    s=(st *)malloc(sizeof(st));
    create(s);
    printf("Enter the infix expression: ");
    gets(infix);
    intoPost(s);
    printf("The postfix expression is: ");
    while(postfix[i])
    {
        printf("%c",postfix[i++]);
    }
    result=post_eval(s);
    printf("\nThe final evaluated answer is: %d\n",result);
    return 0;
}