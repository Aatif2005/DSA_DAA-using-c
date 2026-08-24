#include <stdio.h>

void display(int n, int a[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }

        printf("\n");
    }
}

int indegree(int n, int a[n][n], int v)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (a[i][v] == 1)
            count++;
    }
    return count;
}

int outdegree(int n, int a[n][n], int v)
{
    int j, count = 0;
    for (j = 0; j < n; j++)
    {
        if (a[v][j] == 1)
            count++;
    }
    return count;
}

int main()
{
    int n, i, j, vertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int a[n][n];

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");6+
    display(n, a);

    printf("\nEnter vertex (0 to %d): ", n - 1);
    scanf("%d", &vertex);

    printf("Indegree = %d\n", indegree(n, a, vertex));
    printf("Outdegree = %d\n", outdegree(n, a, vertex));

    return 0;
}