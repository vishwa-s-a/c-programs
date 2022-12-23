//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
struct queue{
    int size;
    int front;
    int rear;
    int *arr;
};
typedef struct queue q;
void create(int size,q *cq)
{
    cq->size=size;
    cq->front=cq->rear=0;
    cq->arr=(int *)malloc(size*sizeof(int));
}
int isfull(q *cq)
{
    if((cq->rear+1)%cq->size==cq->front)
    {
        return 1;
    }
    return 0;
}
int isempty(q *cq)
{
    if(cq->front==cq->rear)
    return 1;
    return 0;
}
void enqueue(q *cq, int data)
{
    if(isfull(cq)){
        printf("queue is full\n");
        return;
    }
    else
    {
        cq->rear=(cq->rear+1)%cq->size;
        cq->arr[cq->rear]=data;
    }
}
int dequeue(q *cq)
{
    int x=-1;
    if(isempty(cq))
    {
        return x;
    }
    else{
        cq->front=(cq->front+1)%cq->size;
        x=cq->arr[cq->front];
        return x;
    }
}
void display(q *cq)
{
    int i=cq->front+1;
    do{
        printf("%d ",cq->arr[i]);
        i=(i+1)%cq->size;
    }while(i!=(cq->rear+1)%cq->size);
}
int main()
{
    q *cq=(q *)malloc(sizeof(q));
    create(10,cq);
    enqueue(cq,1);
    enqueue(cq,2);
    enqueue(cq,3);
    printf("%d \n",dequeue(cq));
    display(cq);
    return 0;
}