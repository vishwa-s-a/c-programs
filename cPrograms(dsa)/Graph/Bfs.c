//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// now we have to implement queue data structure for bfs
struct node{
    int data;
    struct node *next; 
};
struct node *front=NULL;
struct node *rear=NULL;
int  isEmpty()
{
    if(front==NULL && rear==NULL)
    return 1;

    return 0;
}
void enQueue(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(isEmpty())
    {
        front=rear=temp;
    }
    else{
        rear->next=temp;
        rear=temp;
    }
}
int deQueue()
{
    struct node *temp=front;
    if(isEmpty())
    {
        return -1;
    }
    int x=front->data;
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);
    return x;

}
// all queue opertion got over;
// now function for bfs;
void BFS(int g[8][8],int start, int n)
{
    int i=start;
    int visited[8]={0};
    printf("%d ",i);
    visited[i]=1;
    enQueue(i);
   
    while(!isEmpty())
    {
        i=deQueue();
        for(int j=1;j<n;j++)
        {
            if(g[i][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enQueue(j);
            }
        }
    }
}

int main()
{
    //adjacency matrix for the graph
    int g[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,1,1,1,0,0,0},
                 {0,1,0,1,0,0,0,0},
                 {0,1,1,0,1,1,0,0},
                 {0,1,0,1,0,1,0,0},
                 {0,0,0,1,1,0,1,1},
                 {0,0,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,0}};
    printf("Name: Vishwa Shivanand Appaji\nReg no: 21BCI0026\n");
    printf("The Breadth first Search(BFS) traversal from 1 is: ");
    BFS(g,1,8);
    return 0;
}