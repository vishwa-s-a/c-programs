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
struct node *first,*last;
void create(int a[], int n)
{
    struct node *t;
    first=(struct node *)malloc(sizeof(struct node));
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int count(struct node *p)
{   
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
int sum(struct node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}
void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void ReverseDisplay(struct node *p)
{
    if(p!=NULL)
    {
        ReverseDisplay(p->next);
        printf("%d ",p->data);
    }
}
int max(struct node *p)
{
    int max=-32455;
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
            p=p->next;
        }
        else
        {
            p=p->next;
        }
    }
    return max;
}
void insert(struct node *p, int index, int x)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    int i=1;
    if(p==NULL)
    {
        p=t;
    }
    else
    {
        if(index<0 || index>count(p))
        return;
        if(index==0)
        {
            t->next=first->next;
            first->next=t;
        }
        else
        {
           for(i=0;i<index-1;i++)
           {
                p=p->next;
           }
           t->next=p->next;
           p->next=t;
        }
    }
}

int delete(struct node *p, int index)
{
    int i=0;
    int x=-1;
    struct node *q;
    if(index<0 || index>count(p))
    return x;
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        while(i<index-1)
        {
            q=p;
            p=p->next;
            i++;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}
void removeDuplicates(struct node *p)
{
    struct node *q=p->next;
    while(q)
    {
        if(q->data!=p->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
// function to reverse the list using array
void reverse(struct node *p)
{
    struct node *q;
    q=p;
    int *A,i=0;
    A=(int *)malloc(count(p)*sizeof(int));
    while(q)
    {
        A[i]=q->data;
        i++;
        q=q->next;
    }
    i--;
    q=p;
    while(q)
    {
       q->data=A[i];
       q=q->next;
       i--; 
    }
}
int main()
{
    int b[]={1,2,3,4,5};
    create(b,5);
    printf("count: %d\n",count(first));
    printf("Sum: %d\n",sum(first));
    display(first);
    ReverseDisplay(first);
    printf("\n");
    printf("max: %d\n",max(first));
    insert(first,3,9);
    display(first);
    insert(first,0,1);
    display(first);
    delete(first,5);
    display(first);
    removeDuplicates(first);
    display(first);
    reverse(first);
    display(first);
    return 0;
}