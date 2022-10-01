//Name:vishwa shivanand appaji
//Reg no:21BCI0026
// this is well practised and corrected form of doubly linked list compared to the link given by mam for the same
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

void insertLast(int key, int data)
{
    struct node *link=(struct node *)malloc(sizeof(struct node));
    link->data=data;
    link->key=key;
    if(isEmpty())
    {
        head=link;
        head->prev=NULL;
    }
    else{
        last->next=link;
        link->prev=last;
    }
    last=link;
    last->next=NULL;
}

struct node * deleteFirst()
{
    struct node * temp=head;
    if(head->next==NULL)//this only one node present then
    {
        last=NULL;
    }
    else
    {
        head->next->prev=NULL;

    }
    head=head->next;
    return temp;
}

struct node * deleteLast()
{
    struct node *temp=last;
    if(head->next==NULL)
    {
        last=NULL;
    }
    else
    {
        last->prev->next=NULL;
    }
    last=last->prev;
    return temp;
}

struct node * delete(int key)
{
    struct node *current=head;
    struct node *previous=NULL;
    if(head==NULL)
    {
        return NULL;
    }
    while(current->key!=key)
    {
        if(current->next==NULL)
        {
            return NULL;
        }
        else
        {
            previous=current;
            current=current->next;
        }
    }
    // when we find a match then we come out of the above while loop
    if(current==head)
    {
        head=head->next;
        head->prev=NULL;
    }
    else if(current==last)
    {
        last=current->prev;
        last->next=NULL;
    }
    else
    {
        current->prev->next=current->next;
    }
    return current;
}

bool insertAfter(int key, int newKey, int data)
{
    struct node *current=head;
    if(head==NULL)
    {
        return false;
    }
    while(current->key!=key)
    {
        current=current->next;
    }
    struct node *link=(struct node *)malloc(sizeof(struct node));
    link->key=newKey;
    link->data=data;
    if(current==last)
    {
        last=link;
        last->next=NULL;
    }
    else
    {
        link->next=current->next;
        current->next->prev=link;
    }
    current->next=link;
    link->prev=current;
    return true;
}
void main() {
    // it works both the way
   insertFirst(1,10);
   insertFirst(2,20);
   insertFirst(3,30);
   insertFirst(4,1);
   insertFirst(5,40);
   insertFirst(6,56); 
  /*
   insertLast(1,10);
   insertLast(2,20);
   insertLast(3,30);
   insertLast(4,1);
   insertLast(5,40);
   insertLast(6,56); 
    */
   printf("\nList (First to Last): ");  
   displayForward();
	
   printf("\n");
   printf("\nList (Last to first): "); 
   displayBackward();

   printf("\nList , after deleting first record: ");
   deleteFirst();        
   displayForward();

   printf("\nList , after deleting last record: ");  
   deleteLast();
   displayForward();

   printf("\nList , insert after key(4) : ");  
   insertAfter(4,7, 13);
   displayForward();

   printf("\nList  , after delete key(4) : ");  
   delete(4);
   displayForward();
}