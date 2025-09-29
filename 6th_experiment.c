#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 100
int V, graph[MAX][MAX];
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!sptSet[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int dist[], int src)
{
    printf("\nShortest distances from source node %d:\n", src);
    for (int i = 0; i < V; i++)
    {
        printf("Node %d -> ", i);
        if (dist[i] == INT_MAX)
            printf("INF (Not reachable)\n");
        else
            printf("Distance = %d\n", dist[i]);
    }
}
void dijkstra(int src)
{
    int dist[MAX];
    bool sptSet[MAX];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        if (u == -1)
            break;
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist, src);
}
void inputGraph()
{
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);
    }
}
void displayGraph()
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }
}
int main()
{
    int choice, src;
    do
    {
        printf("\n==== MENU ====\n");
        printf("1.Enter Graph\n2.Display Graph\n3.Find Shortest Paths (Dijkstra)\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            inputGraph();
            break;
        case 2:
            if (V > 0)
                displayGraph();
            else
                printf("\nPlease enter the graph first!\n");
            break;
        case 3:
            if (V > 0)
            {
                printf("Enter the source node (0 to %d): ", V - 1);
                scanf("%d", &src);
                if (src >= 0 && src < V)
                    dijkstra(src);
                else
                    printf("\nInvalid source node!\n");
            }
            else
                printf("\nPlease enter the graph first!\n");
            break;
        case 4:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } 
    while (choice != 4);
    return 0;
}