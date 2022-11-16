//Name:vishwa shivanand appaji
//Reg no:21BCI0026
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// for dfs we use stack, and we dont have to use a stack data structure directly instead we use 
//recursive function.
void DFS(int g[8][8],int start, int n)
{
    static int visited[8]={0};// so it is accessible and same for all recursive calls 
    if(visited[start]==0)
    {
        printf("%d ",start);
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(g[start][j]==1 && visited[j]==0)
            {
                DFS(g,j,n);
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
    printf("The Depth first Search(DFS) traversal from 4 is: ");
    DFS(g,4,8);
    return 0;
}