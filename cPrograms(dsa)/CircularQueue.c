//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
typedef struct queue q;
void create(q *cq,int size)
{
    cq->size=size;
    cq->front=0;
    cq->rear=0;
    cq->arr=(int *)malloc(size*sizeof(int));
}
int isFull(q *cq)
{
    if((cq->rear+1)%cq->size==cq->front)
    return 1;
    return 0;
}
int isEmpty(q *cq)
{
    if(cq->front==cq->rear)
    return 1;
    return 0;
}
void enqueue(q *cq,int m)
{
    if(!isFull(cq))
    {
        cq->rear=(cq->rear+1)%cq->size;
        cq->arr[cq->rear]=m;
    }
    else
    printf("Queue is full\n");
}
int dequeue(q *cq)
{
    int x=-1;
    if(!isEmpty(cq))
    {
        cq->front=(cq->front+1)%cq->size;
        x=cq->arr[cq->front];
    }
    return x;
}
void display(q *cq)
{
    int i=cq->front+1;
    do
    {
        printf("%d ",cq->arr[i]);
        i=(i+1)%cq->size;
    } while (i!=(cq->rear+1)%cq->size);
    printf("\n");
    
}
int main()
{
    int size;
    q cq;
    printf("Enter the size of the queue: ");
    scanf("%d",&size);
    create(&cq , size);
    enqueue(&cq,10);
    enqueue(&cq,20);
    enqueue(&cq,30);
    enqueue(&cq,40);
    enqueue(&cq,50);
    enqueue(&cq,60);
    display(&cq);
    printf("%d \n",dequeue(&cq));
    display(&cq);

    return 0;
}