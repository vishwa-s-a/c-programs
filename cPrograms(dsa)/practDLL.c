//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>// this is needed for boolean operations
struct node
{
    int data;
    int key;
    struct node * next;
    struct node * prev;
};
struct node *head=NULL;
struct node *last=NULL;
struct node *current=NULL;
bool isEmpty()
{
    return head==NULL?true:false;
}
int length()
{
    int length=0;
    current=head;
    for(;current!=NULL;current=current->next)
    {
        length++;

    }
    return length;

}

void displayForward()
{
    current=head;
    printf("[ ");
    for(;current!=NULL;current=current->next)
    {
        printf("(%d,%d)",current->key,current->data);
    }
    printf(" ]");
}

void displayBackward()
{
    current=last;
    printf("[ ");
    for(;current!=NULL;current=current->prev)
    {
        printf("(%d,%d)",current->key,current->data);
    }
    printf(" ]");
}

void insertFirst(int key, int data)
{
    struct node *link=(struct node *)malloc(sizeof(struct node));
    link->data=data;
    link->key=key;
    if(isEmpty())
    {
        last=link;
    }
    else
    {
        head->prev=link;
    }
    link->next=head;
    head=link;
    head->prev=NULL;
}

void lastInsert(int key, int data)
{
    
}
int main()
{
    return 0;
}