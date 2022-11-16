//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
struct node{
    char data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
node *makenode(char data)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
node * insert(node *t,char data)
{
    if(t==NULL)
    {
        return makenode(data);
    }
    if(t->data>data)
    t->left=insert(t->left,data);
    else
    t->right=insert(t->right,data);
    return t;
}
int search(node *t, char data)
{
    if(t==NULL)
    return 0;
    if(t->data==data)
    return 1;
    if(t->data>data)
    return search(t->left,data);
    return search(t->right,data);
}
void inorder(node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        printf("%c ",t->data);
        inorder(t->right);
    }
}
void preorder(node *t)
{
    if(t!=NULL)
    {
        printf("%c ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void  postorder(node *t)
{
    if(t!=NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%c ",t->data);
    }
}
char findmin(node *t)
{
    if(t->left==NULL)
    {
        return t->data;
    }
    else
    return findmin(t->left);
}
int tnodes=0;
void totalnodes(node *t)
{
    if(t!=NULL)
    {
        totalnodes(t->left);
        totalnodes(t->right);
        tnodes++;
    }
}
int lnodes=0;
void leafnodes(node *t)
{
    if(t!=NULL)
    {
        leafnodes(t->left);
        if(!t->left && !t->right)
        lnodes++;
        leafnodes(t->right);
    }
}
int height(node *t)
{
    int x,y;
    if(t!=NULL)
    {
        x=height(t->left);
        y=height(t->right);
        if(x>y)
        return x+1;
        else
        return y+1;
    }
    else
    return 0;
}
node *delete(node *t, char data)
{
    if(t)
    {
        if(t->data==data)
        {
            if(!t->left && !t->right)
            return NULL;
            if(!t->left)
            return t->right;
            if(!t->right)
            return t->left;
            t->data=findmin(t->right);
            t->right=delete(t->right,t->data);
            return t;
        }
        if(t->data>data)
        t->left=delete(t->left,data);
        else
        t->right=delete(t->right,data);
    }
    return t;
}
int main()
{
    node *root=NULL;
    int choice,n;
    do{
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("No of nodes to create: ");
            scanf("%d",&n);
            char temp;
            for(int i=1;i<=n;i++)
            {
                printf("Enter the data: ");
                fflush(stdin);
                scanf("%c",&temp);
                root=insert(root,temp);
            }
            printf("BST is prepared.\n");
            break;

            case 2:
            printf("Tree traversals are: \n");
            printf("inorder: \n");
            inorder(root);
            printf("\nPreorder: \n");
            preorder(root);
            printf("\npostorder: \n");
            postorder(root);
            printf("\n");
            break;

            case 3:
            printf("\nenter the data to search: ");
            char temp1;
            fflush(stdin);
            scanf("%c",&temp1);
            if(search(root,temp1))
            printf("Found\n");
            else
            printf("Not found\n");
            break;

            case 4:
            printf("enter the data to delete: \n");
            char temp2;
            fflush(stdin);
            scanf("%c",&temp2);
            root=delete(root,temp2);
            break;

            case 5:
            totalnodes(root);

            printf("Totalnodes are: %d\n",tnodes);
            printf("Height of the tree: %d\n",height(root));
            break;

            case 9:
            goto end;
            default:
            printf("Incorrect entry\n");



        }
    }while(true);
    end:
    return 0;
}