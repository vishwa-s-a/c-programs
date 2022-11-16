//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;
struct node * makeNode(int item)// it is going to return a pointer of this kind
{
    node *root=(node *)malloc(sizeof(struct node));// dynamically allocate the memory
    root->left=root->right=NULL;//leaf nodes are made NULL
    root->data=item;
    return root;
}

node * Insert(node *t,int data)
{
    if(!t)// if null comes then it becomes true and runs
    {
        return makeNode(data);
    }
    if(t->data>data)
    {
        t->left=Insert(t->left,data);
    }
    else
    t->right=Insert(t->right,data);
    return t;
}

int Search(node *t,int data)
{
    if(!t) return 0;
    if(t->data==data) return 1;
    if(t->data>data)
    {
        return Search(t->left,data);

    }
    return Search(t->right,data);
}

void Inorder(node * root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
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
// abdul baris function for counting the nodes
int count(node *t)
{
    int x,y;
    if(t!=NULL){
        x=count(t->left);
        y=count(t->right);
        return x+y+1;
    }
    else
    return 0;
    //instead of above code we can also use these below lines
    /*
    if(t)
        return count(t->left)+count(t->right)+1;
    return 0;
    */
}
// abdul baris function for counting the nodes with degree 2
int count2(node *t)
{
    int x,y;
    if(t!=NULL)
    {
        x=count2(t->left);
        y=count2(t->right);
        if(t->left && t->right)//if both children are there for the particular node then only it is counted
            return x+y+1;
        else 
            return x+y;
    }
    else
        return 0;
}
// abdul baris function for adding all the values present in the nodes is
int count3(node *t)
{
    int x,y;
    if(t!=NULL)
    {
        x=count3(t->left);
        y=count3(t->right);
        return x+y+t->data;
    }
    else
        return 0;
}
//abdul baris function to find the height of the tree
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
int findMin(node * t)
{
    if(!t->left)// when null comes then it becomes true
    {
        return t->data;
    }
    return findMin(t->left);
}

node * deleteVal(node * t, int val)
{
    if(t)// if it is non-null then only it only run
    {
        if(t->data==val)
        {
            if(!t->left && !t->right) return NULL;// if leaf node then easily delete the node and make that place as null
            if(!t->left) return t->right;
            if(!t->right) return t->left;
            // if both child nodes are present then we
            t->data=findMin(t->right);
            t->right=deleteVal(t->right,t->data);
            return t;
        }
        if(t->data>val)
            t->left=deleteVal(t->left,val);
        else
        t->right=deleteVal(t->right,val);
    }
    return t;
}

void preOrder(node * root)
{
    if(root)// if non-null then only it will run
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node * root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    node * root=NULL;
    int choice,item,n,i,res=0;
    do
    {
        printf("\n\nBinary Search Tree operations\n");
        printf("\n1. Creation of BST");
        printf("\n2. Search in BST");
        printf("\n3. Traverse in Inorder");
        printf("\n4. Traverse in Preorder");
        printf("\n5. Traverse in Postorder");
        printf("\n6. Deletion in BST");
        printf("\n7. Exit");
        printf("\n8. To count the total nodes and leaf nodes\n");
        printf("First try to create a BST then you can try other operations\n");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            //root=NULL;
            printf("\n\nBST for How many Nodes? ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\n Enter the data for node %d: ",i);
                scanf("%d",&item);
                root=Insert(root,item);
            }
            printf("\nBST with %d nodes is ready to use!!\n",n);
            break;

            case 2:
            printf("\nSearch for which node?: \n");
            scanf("%d",&n);
            res=Search(root,n);
            printf("\n%d\n",res);
            if(res)
            {
                printf("found\n");
            }
            else
            printf("Not found\n");
            break;

            case 3:
            printf("\nBST Traversal in In Order\n");
            Inorder(root);
            break;

            case 4:
            printf("\nBST Traversal in PreOrder\n");
            preOrder(root);
            break;

            case 5:
            printf("\nBST Traversal in PostOrder\n");
            postOrder(root);
            break;

            case 6:
            printf("\n\nwhich node to delete?");
            scanf("%d",&n);
            root=deleteVal(root,n);
            break;

            case 7:
            printf("\n\nTerminating \n\n");
            goto end;

            case 8:
            totalNodes(root);
            printf("The number of total nodes is: %d\n",tnodes);
            printf("Total nodes is : %d\n",count(root));
            leafNodes(root);
            printf("The number of leaf nodes is: %d\n",lnodes);
            printf("Height of the tree is: %d\n",height(root));

            break;

            default:
            printf("\n\nInvalid Option!!! Try again!!\n\n");
            break;

        }
    }while(choice!=5);
    end:
    return 0;
}