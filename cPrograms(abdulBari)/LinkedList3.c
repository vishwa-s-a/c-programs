//Name:vishwa shivanand appaji
//Reg no:21BCI0026
// program to check whether loop is there in linked list or not.
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;
// function to create linked list using array given by user
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
// function to find the loop in the list
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }while(p && q && p!=q);
    if(p==q)
    {
        return 1;
    }
    else return 0;
}
int main()
{
    struct Node *t1,*t2;
    int A[]={10,20,30,40,50};
    create(A,5);
    // looping the list
    t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    int flag=isLoop(first);
    if(flag==1)
    printf("loop is present.");
    return 0;
}