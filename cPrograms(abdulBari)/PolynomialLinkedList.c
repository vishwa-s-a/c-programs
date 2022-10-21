//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int coeff;
    int exp;
    struct node *next;
}*poly=NULL;
void create()
{
    struct node *t,*last;
    int num,i;
    printf("Enter the number of terms: ");
    scanf("%d",&num);
    printf("Enter each term with coeff and exp\n");
    for(i=0;i<num;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        scanf("%d %d",&t->coeff,&t->exp);
        t->next=NULL;
        if(poly==NULL)
        {
            poly=last=t;
        }
        else{
            last->next=t;
            last=t;
        }
    }
}
void display(struct node *p)
{
    while (p)
    {
        printf("%dx^%d+",p->coeff,p->exp);
        p=p->next;
    }
    printf("\n");
    
}
long eval(struct node *p, int x)
{
    long val=0;
    while(p)
    {
        val+=p->coeff*pow(x,p->exp);
        p=p->next;
    }
    return val;
}
int main()
{
    create();
    display(poly);
    printf("The final result %ld\n",eval(poly,1));
    return 0;
}