#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define INF INT_MAX
struct Edge
{
int u, v, w;
};
void dijkstra(int V, int E, int adj[100][100],
int src, int dist[])
{
int visited[100] = {0};
for (int i = 0; i < V; i++)
    dist[i] = INF;
dist[src] = 0;
for (int count = 0; count < V; count++)
{
    int u = -1;
    int min = INF;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            u = i;
        }
    }

    if (u == -1)
        break;

    visited[u] = 1;

    for (int v = 0; v < V; v++)
    {
        if (adj[u][v] != INF &&
            dist[u] != INF &&
            dist[u] + adj[u][v] < dist[v])
        {
            dist[v] = dist[u] + adj[u][v];
        }
    }
}


}
int bellmanFord(int V, int E, struct Edge edges[],
int src, int dist[])
{
for (int i = 0; i < V; i++)
dist[i] = INF;
dist[src] = 0;

for (int i = 1; i < V; i++)
{
    int updated = 0;

    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF &&
            dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            updated = 1;
        }
    }

    if (!updated)
        break;
}
for (int j = 0; j < E; j++)
{
    int u = edges[j].u;
    int v = edges[j].v;
    int w = edges[j].w;

    if (dist[u] != INF &&
        dist[u] + w < dist[v])
    {
        return 0;
    }
}
return 1;
}

int main()
{
int V, E, src;
int adj[100][100];
int dist1[100], dist2[100];
struct Edge edges[1000];
clock_t start, end;
double time1, time2;
printf("Enter number of vertices: ");
scanf("%d", &V);
printf("Enter number of edges: ");
scanf("%d", &E);
if (V < 1 || V > 100 || E < 0 || E > 1000)
{
    printf("Invalid graph size.\n");
    return 1;
}
for (int i = 0; i < V; i++)
{
    for (int j = 0; j < V; j++)
        adj[i][j] = INF;
}

printf("Enter edges (source destination weight):\n");

for (int i = 0; i < E; i++)
{
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);

    if (u < 0 || u >= V || v < 0 || v >= V)
    {
        printf("Invalid vertex.\n");
        return 1;
    }
    edges[i].u = u;
    edges[i].v = v;
    edges[i].w = w;
    adj[u][v] = w;
}
printf("Enter source vertex: ");
scanf("%d", &src);
if (src < 0 || src >= V)
{
    printf("Invalid source vertex.\n");
    return 1;
}
// Check for negative weights
int negative = 0;

for (int i = 0; i < E; i++)
{
    if (edges[i].w < 0)
        negative = 1;
}
start = clock();
dijkstra(V, E, adj, src, dist1);
end = clock();
time1 = ((double)(end - start)) / CLOCKS_PER_SEC;
// Bellman-Ford execution
start = clock();
int valid = bellmanFord(V, E, edges, src, dist2);
end = clock();
time2 = ((double)(end - start)) / CLOCKS_PER_SEC;
// Display results
printf("\n===== SHORTEST PATH RESULTS =====\n");
printf("Vertex\tDijkstra\tBellman-Ford\n");
for (int i = 0; i < V; i++)
{
    printf("%d\t", i);

    if (negative)
        printf("N/A\t\t");
    else if (dist1[i] == INF)
        printf("INF\t\t");
    else
        printf("%d\t\t", dist1[i]);

    if (!valid)
        printf("Negative Cycle\n");
    else if (dist2[i] == INF)
        printf("INF\n");
    else
        printf("%d\n", dist2[i]);
}
printf("\n===== PERFORMANCE COMPARISON =====\n");
if (negative)
    printf("Dijkstra: Not applicable (negative edge detected)\n");
else
    printf("Dijkstra Execution Time: %lf seconds\n", time1);

printf("Bellman-Ford Execution Time: %lf seconds\n", time2);
if (!negative && valid)
{
    if (time1 < time2)
        printf("\nDijkstra is faster.\n");
    else if (time2 < time1)
        printf("\nBellman-Ford is faster.\n");
    else
        printf("\nBoth took approximately equal time.\n");
}
if (!valid)
    printf("\nNegative weight cycle detected!\n");

return 0;
}
