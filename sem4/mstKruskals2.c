/*this code was written for da-3 purpose so you can refer da-3 for getting the input graph*/
#include <stdio.h>
#include <stdlib.h>
int comparator(const void *p, const void *q)
{
    const int(*x)[3] = p;
    const int(*y)[3] = q;
    return (*x)[2] - (*y)[2];
}

void makeset(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if(parent[component]==component)
    return parent[component];

    return findParent(parent,parent[component]);
}

void unionSet(int u, int v, int parent[], int rank[])
{
    if(rank[u]<rank[v])
    {
        parent[u]=v;
    }
    else if(rank[v]<rank[u])
    {
        parent[v]=u;
    }
    else{
        parent[v]=u;
        rank[u]++;
    }
}
void kruskalAlgo(int n, int edge[n][3])
{
    qsort(edge,n,sizeof(edge[0]),comparator);
    int parent[n];
    int rank[n];

    makeset(parent,rank,n);
    int min_cost=0;

    printf("Following are the edges constructed in MST\n");
    for(int i=0;i<n;i++)
    {
        int u=findParent(parent,edge[i][0]);
        int v=findParent(parent,edge[i][1]);
        int wt=edge[i][2];

        if(u != v)
        {
            unionSet(u,v,parent,rank);
            min_cost+=wt;
            printf("%d -- %d == %d\n",edge[i][0],edge[i][1],wt);
        }
    }
    printf("The minimum cost spanning tree: %d\n",min_cost);
}

int main()
{
    int edge[10][3]={{1,3,1},
					{1,2,10},
					{1,4,5},
					{2,6,1},
					{2,3,8},
                    {2,5,1},
                    {3,4,3},
                    {3,6,6},
                    {4,5,4},
                    {5,6,2}};

    printf("Name:Vishwa Shivanand Appaji\nReg no:21BCI0026\n");
	kruskalAlgo(10,edge);
    return 0;
}