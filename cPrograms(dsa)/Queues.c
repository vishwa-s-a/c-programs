//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *q;
};
typedef struct Queue queue;
void create(queue *Q,int size)
{
    Q->size=size;
    Q->front=-1;
    Q->rear=-1;
    Q->q=(int *)malloc(size*sizeof(int));
}
int isFull(queue *Q)
{
    if(Q->rear==Q->size-1)
    return 1;
    return 0;
}
int isEmpty(queue *Q)
{
    if(Q->front==Q->rear)
    return 1;
    return 0;
}
void enqueue(queue *Q,int m)
{
    if(!isFull(Q))
    {
        Q->rear++;
        Q->q[Q->rear]=m;
    }
    else
    printf("Queue is full\n");
}
int dequeue(queue *Q)
{
    int x=-1;
    if(!isEmpty(Q))
    {
        Q->front++;
        x=Q->q[Q->front];

    }
    return x;
}
void display(queue *Q)
{
    for(int i=(Q->front)+1;i<=Q->rear;i++)
    {
        printf("%d ",Q->q[i]);
    }
    printf("\n");
}
int main()
{
    int size;
    queue Q;
    printf("enter the size of the queue: ");
    scanf("%d",&size);
    create(&Q,size);
    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);
    display(&Q);
    printf("%d \n",dequeue(&Q));
    display(&Q);
    return 0;
}