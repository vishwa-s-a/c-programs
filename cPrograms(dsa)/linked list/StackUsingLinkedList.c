//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void push(int data)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    head=temp;
}
void pop()
{
    if(head==NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node* temp;
        temp=head;
        printf("The data poped is: %d\n",head->data);
        head=head->next;
        free(temp);
    }
    
}
void display(struct node *p)
{
    printf("[ ");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("]\n");
}
int main()
{
    push(1);
    push(2);
    push(3);
    display(head);
    pop();
    pop();
    display(head);
    return 0;
}