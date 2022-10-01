//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL;
// function to create linked list using array given by user
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;

    }
}
// iterative display
void display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

// recursive display(it displays the array in proper order)
void Rdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}

// reverse recursive display (it displays the array in reverse order)
void Rdisplay2(struct Node *p)
{
    if(p!=NULL)
    {
        Rdisplay2(p->next);
        printf("%d ",p->data);
    }
}
int count(struct Node *p)
{
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
}
// recursive of count
int Rcount(struct Node *p)
{
    if(p!=NULL)
    {
        return Rcount(p->next)+1;
    }
    else
    return 0;
}
// finding sum of all elements
int sum(struct Node *p)
{
    int s=0;
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
}
// sums recursive function
int Rsum(struct Node *p)
{
    if(p==NULL)
    return 0;
    else
    {
        return Rsum(p->next)+p->data;
    }
}
// function to find the maximum of the linked list
int Max(struct Node *p)
{
    int max=-32769;
    while(p)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}
// recursive form of max of elements
int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
    return -32679;
    x=Rmax(p->next);
    return x>p->data?x:p->data;
}
// searching function(iterative form)
struct Node * LSearch(struct Node *p,int key)
{
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        // this additional statements are only for improving the search mechanism
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
//recursive function for searching
struct Node * RSearch(struct Node *p,int key)
{
    if(p==NULL)
    return NULL;
    if(key==p->data)
    return p;
    return RSearch(p->next,key);

}
//Insert function
void Insert(struct Node *p,int index,int x)
{
    struct Node *t;
    int i;
    if(index<0 || index>count(p))
    return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
        p=p->next;
        //
        t->next=p->next;
        p->next=t;
    }

}
//function to insert in sorted list
void SoretedInsert(struct Node *p,int x)
{
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
    }
    else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;

        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }

}
// function to delete a node
int Delete(struct Node *p, int index)
{
    struct Node *r,*q=NULL;
    int x=-1;
    int i=0;
    if(index<1 || index>count(p))
    {
        return x;
    }
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
//function to check whether list is sorted or not
int isSorted(struct Node *p)
{
    int x=-65536;
    while(p!=NULL)
    {
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
//function to remove duplicates from the sorted list
void RemoveDuplicate(struct Node *p)
{
    struct Node *q=p->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
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
// function to reverse the list using arrays
void Reverse1(struct Node *p)
{
    int *A,i=0;
    struct Node *q;
    q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}
// function to reverse the list using the sliding pointers
void Reverse2(struct Node *p)
{
    struct Node *q=NULL,*r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
//function to reverse the list using recursive method
void Reverse3(struct Node *q,struct Node *p)
{
    if(p)
    {
        Reverse3(p,p->next);
        p->next=q;
    }
    else
    first=q;
}
int main()
{
    struct Node *temp;
    int a[]={1,2,3,4,4,8,12,13};
    create(a,8);
    display(first);
    printf("\n");
    Rdisplay(first);
    printf("\n");
    Rdisplay2(first);
    printf("\nLength is : %d",count(first));
    printf("\nRlength is : %d",Rcount(first));
    printf("\nsum is %d",sum(first));
    printf("\nRsum is %d",Rsum(first));
    printf("\nMax is %d",Max(first));
    printf("\nRmax is %d\n",Rmax(first));
    /*
    temp=LSearch(first,13);
    if(temp)
    printf("Key is found %d\n",temp->data);
    else
    printf("key not found\n");
    display(first);//to check whether list is modified after search or not
    temp=LSearch(first,5);
    printf("\n");
    display(first);
    temp=RSearch(first,9);
    if(temp)
    printf("Key is found %d\n",temp->data);
    else
    printf("key not found\n");
    */
    //Insert(first,6,99);//using this function we can create a new linked list from scratch
    // like start from Insert(first,0,1);Insert(first,1,2);Insert(first,2,3); 
    display(first);
    SoretedInsert(first,35);
    printf("\n");
    display(first);
    int ram=Delete(first,6);
    printf("ram:%d\n",ram);
    display(first);
    printf("\n%d\n",isSorted(first));
    RemoveDuplicate(first);
    display(first);
    //Reverse1(first);
    //Reverse2(first);
    Reverse3(NULL,first);
    printf("\n");
    display(first);
    return 0;
    
}
