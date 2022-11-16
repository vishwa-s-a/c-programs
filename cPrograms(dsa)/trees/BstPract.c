//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node * left;
    struct node *right;
};
typedef struct node node;
node * makeNode(int data)
{
    node *root;
    root=(node *)malloc(sizeof(node));
    root->data=data;
    root->left=root->right=NULL;
    return root;
    
}
node * Insert(node * t,int data)
{
    if(!t)
    {
        return makeNode(data);
    }
    if(t->data>data)
    t->left=Insert(t->left,data);
    else
    t->right=Insert(t->right,data);
}
int findMin(node * t)
{
    if(!t->left)
    {
        return t->data;
    }
    return findMin(t->left);
}
void Inorder(node * t)
{
    if(t!=NULL)
    {
        Inorder(t->left);
        printf("%d ",t->data);
        Inorder(t->right);
    }
}
//function used for counting the total nodes in the bst
int tnodes=0;
void totalNodes(node * t)
{
    if(t!=NULL)
    {
        totalNodes(t->left);
        totalNodes(t->right);
        tnodes++;
    }
}
// function to count only the leaf nodes in bst
int lnodes=0;
void leafNodes(node *t)
{
    if(t!=NULL)
    {
        leafNodes(t->left);
        if(t->left==NULL && t->right==NULL)
        {
            lnodes++;
        }
        leafNodes(t->right);
    }
}
void Preorder(node *t)
{

}
void Postorder(node *t)
{

}
int Search(node *t , int key)
{
    if(!t) return 0;
    if(t->data==key) return 1;
    if(t->data>key)
    return Search(t->left,key);
    return Search(t->right,key);

}
node * deleteVal(node * t, int key)
{
    if(t)
    {
        if(t->data==key)
        {
            if(!t->left && !t->right) return NULL;
            if(!t->left) return t->right;
            if(!t->right) return t->left;
            t->data=findMin(t->right);
            t->right=deleteVal(t->right,t->data);
            return t;
        }
        if(t->data>key)
        return deleteVal(t->left,key);
        else
        return deleteVal(t->right,key);

    }
    return t;
}
int main()
{
    return 0;
}