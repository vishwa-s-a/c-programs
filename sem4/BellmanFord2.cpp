//this code was written for da-3 question you can refer da-3 for input graph
#include <bits/stdc++.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printSolution(int dist[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}

void BellmanFord(struct Graph *graph, int src)
{
    int v = graph->V;
    int e = graph->E;
    int dist[v];

    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int j = 0; j < e; j++)
    {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            dist[v] = dist[u] + weight;
            printf("There exits a negative cycle");
            return;
        }
            
    }
    printSolution(dist,v);
    return;
}

int main()
{
    int V=9;
    int E=15;
    struct Graph *graph=createGraph(V,E);

    printf("Name: Vishwa Shivanand Appaji\nReg no:21BCI0026\n");
    
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    graph->edge[0].weight=5;

    graph->edge[1].src = 0;
	graph->edge[1].dest = 8;
	graph->edge[1].weight = 2;

	// add edge 1-2 (or B-C in above figure)
	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;
	graph->edge[2].weight = 7;

	// add edge 1-3 (or B-D in above figure)
	graph->edge[3].src = 1;
	graph->edge[3].dest = 6;
	graph->edge[3].weight = 3;

	// add edge 1-4 (or B-E in above figure)
	graph->edge[4].src = 2;
	graph->edge[4].dest = 3;
	graph->edge[4].weight =8;

	// add edge 3-2 (or D-C in above figure)
	graph->edge[5].src = 2;
	graph->edge[5].dest = 7;
	graph->edge[5].weight =7;

	// add edge 3-1 (or D-B in above figure)
	graph->edge[6].src = 2;
	graph->edge[6].dest = 5;
	graph->edge[6].weight =5;

	// add edge 4-3 (or E-D in above figure)
	graph->edge[7].src = 5;
	graph->edge[7].dest = 7;
	graph->edge[7].weight =2;

    graph->edge[8].src = 7;
	graph->edge[8].dest = 3;
	graph->edge[8].weight =3;

    graph->edge[9].src = 6;
	graph->edge[9].dest = 2;
	graph->edge[9].weight =2;

    graph->edge[10].src = 6;
	graph->edge[10].dest = 5;
	graph->edge[10].weight = 6;

    graph->edge[11].src = 8;
	graph->edge[11].dest =5;
	graph->edge[11].weight =9;

    graph->edge[12].src = 8;
	graph->edge[12].dest = 1;
	graph->edge[12].weight = 2;

    graph->edge[13].src = 6;
	graph->edge[13].dest =8;
	graph->edge[13].weight = -2;

   graph->edge[14].src = 3;
	graph->edge[14].dest =4;
	graph->edge[14].weight = 4;
	
	// Function call
	BellmanFord(graph, 0);

}
