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
struct node *front=NULL,*rear=NULL;
void enQueue(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(front==NULL && rear==NULL)// means the queue is empty then front and rear both point to temp
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
void deQueue()
{
    struct node *temp=front;
    if(front==NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d is removed\n",front->data);
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
}
void display()
{
    struct node *current;
    current=front;
    printf("Elements present in Queue are: [ ");
    while(current)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("]\n");
    printf("Front: %d\nRear: %d\n",front->data,rear->data);
}
int main()
{
    int choice,data;
    while(true)
    {
        printf("Welcome to Queue operations: \n");
        printf("Press 1 for EnQueue operation\nPress 2 for DeQueue operation\n");
        printf("Press 3 to display the Queue\nPress 0 to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("Enter the data to be added to Queue: ");
                scanf("%d",&data);
                enQueue(data);
                break;
            case 2:
                deQueue();
                break;
            case 3:
                display();
                break;
            case 0:
                goto end;
        }
    }
    end:
    return 0;
}