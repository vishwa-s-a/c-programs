//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head=NULL,*last=NULL;
bool isEmpty()
{
    if(head==NULL)
    return true;
    //
    return false;
}
int length(node *p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
void createNode(node *p, int data)
{
    node * temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    head=temp;
    last=temp;
}
void insertFirst(node *p,int data)
{
    if(isEmpty())
    createNode(p,data);
    else{
        node *temp=(node *)malloc(sizeof(node));
        temp->data=data;
        temp->next=head;
        head=temp;
    }

}
void insertLast(node *p,int data)
{
    if(isEmpty())
    createNode(p,data);
    else
    {
        node *temp=(node *)malloc(sizeof(node));
        temp->data=data;
        temp->next=NULL;
        last->next=temp;
        last=temp;
    }
}
void insert(node *p, int index, int data)
{
    int count=length(p);
    if(index<0 || index>count)
    return;
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    // if to insert at head then index==0
    if(index==0)
    {
        insertFirst(p,data);
    }
    else
    {
        node *q=NULL;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        temp->next=p->next;
        p->next=temp;
    }

}
//sorting one element with rest of the remaining element then to decide
void sort(node *p)
{
    node *q,*temp;
    int min;
    while(p)
    {
        min=p->data;
        q=p->next;
        while(q)
        {
            if(q->data<min)
            {
                min=q->data;
                temp=q;
            }
            q=q->next;
        }
        temp->data=p->data;
        p->data=min;
        p=p->next;
    }
}
void display(node *p)
{
    printf("[ ");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("]\n");
}
void delete(node *p, int data)
{
    node *q=NULL;
    node *temp;
    while(p && p->data!=data)
    {
        q=p;
        p=p->next;
    }
    if(p==NULL)
    printf("Elements not there to delete");
    if(p==head)
    {
        head=p->next;
        p->next=NULL;
        free(p);
    }
    else
    {
        temp=p;
        q->next=p->next;
        p->next=NULL;
        free(temp);
    }
}
int main()
{
    printf("Name: VISHWA SHIVANAND APPAJI\nRegister number: 21BCI0026\n");
    insertFirst(head,10);
    insertFirst(head,20);
    insertFirst(head,30);
    insertLast(head,40);
    insertLast(head,50);
    insert(head,0,99);
    insert(head,6,99);
    insert(head,2,99);
    printf("List after all insertion operation: \n");
    display(head);
    printf("List after sorting: \n");
    sort(head);
    display(head);
    delete(head,99);
    printf("List after deleting 99: \n");
    display(head);
    return 0;
}