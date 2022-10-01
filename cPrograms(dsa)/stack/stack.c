/*
demonstration of stack using c, and concepts of structures, pointers;
here we mainly perform push and pop options
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int count=0;
struct stack
{
    int top;
    int n[MAX];
};
typedef struct stack st;
void createStack(st *s)
{
    s->top=-1;
}
int isStackFull(st *s)
{
    if(s->top==(MAX-1))
    {
        return 1;
    }
    else{return 0;}
}
int isStackEmpty(st *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else{return 0;}
}
void push(st *s, int v)
{
    int n=isStackFull(s);
    if(n==1){
        printf("The stack is full so can't perform push opertion\n");
    }
    else{
        s->top++;
        s->n[s->top]=v;
        //printf("%d is pushed into stack\n",s->n[s->top]);
        count++;
    }
}
void pop(st *s)
{
    int m=isStackEmpty(s);
    if(m==1)
    {
        printf("The stack is empty so can't perform pop operation\n");
    }
    else
    {
        printf("%d is poped from stack\n",s->n[s->top]);
        s->top--;
        count--;
    }
}
void display(st *s)
{
    printf("Stack is as follows\n");
    for(int i=0;i<count;i++)
    {
        printf("%d\n",s->n[i]);
    }
}

int main()
{
    st *s=(st *)malloc(sizeof(st));
    createStack(s);
    push(s,10);
    push(s,9);
    push(s,8);
    push(s,7);
    push(s,6);
    pop(s);
    push(s,5);
    push(s,4);
    push(s,3);
    push(s,2);
    push(s,1);
    push(s,0);
    push(s,11);
    display(s);
    return 0;
}