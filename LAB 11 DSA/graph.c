// write a c program to accept the graph as an adjocency matrix and check if the graph is undirected

#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[n][n];
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    int isUndirected = 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] != adj[j][i])
            {
                isUndirected = 0;
                break;
            }
        }
        if (isUndirected == 0)
        {
            break;
        }
    }
    if (isUndirected)
    {
        printf("The graph is Undirected.\n");
    }
    else
    {
        printf("The graph is Directed.\n");
    }

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,j,i;

    printf("Enter the number of vertices in the graph:");
    scanf("%d",&n);

    int **adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        adj[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int isUndirected = 1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] != adj[j][i]) {
                isUndirected = 0;
                break;
            }
        }
        if(isUndirected == 0) {
            break;
        }
    }

    if(isUndirected) {
        printf("The graph is Undirected.\n");
    } else {
        printf("The graph is Directed.\n");
    }

    for(i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);

    return 0;
}*/
