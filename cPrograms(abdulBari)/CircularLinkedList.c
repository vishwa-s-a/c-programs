//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int data;
    struct Node *next;
}*head;

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    head=(struct Node *)malloc(sizeof(struct Node));
    head->data=A[0];
    head->next=head;// this is the line which is making the list circular
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;// this is the line which is making the list circular
        last->next=t;
        last=t;
    }

}
// iterative form of display function
void display(struct Node *p)
{
    printf("[ ");
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("]\n");
}

// recursive form of the display
void Rdisplay(struct Node *p)
{
    static int flag=0;
    if(p!=head || flag==0)
    {
        flag=1;
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
    flag=0;
}
int Length(struct Node *p)
{
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=head);
    return len;
}
void Insert(struct Node *p, int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>Length(p))
    return;
    if(index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(i=0;i<index-1;i++)
        {
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t; 
    }

}
int delete(struct Node *p, int index)
{
    struct Node *q;
    int i,x;
    if(index<0|| index>Length(head))
    return -1;
    if(index==1)
    {
        while(p->next!=head)p=p->next;
        x=head->data;
        if(head==p)
        {
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
        p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main()
{
    int A[]={2,4,6,8,10};
    create(A,5);
    Insert(head,2,12);
    delete(head,1);
    display(head);
    Rdisplay(head);
    return 0;
}