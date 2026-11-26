#include <stdio.h>

int w[20], x[20], n, m;

void sumOfSubsets(int s, int k, int r)
{
    int i;

    x[k] = 1;

    if (s + w[k] == m)
    {
        printf("\nSubset: ");
        for (i = 1; i <= k; i++)
        {
            if (x[i] == 1)
                printf("%d ", w[i]);
        }
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }

    if ((s + r - w[k] >= m) && (s + w[k + 1] <= m))
    {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

int main()
{
    int i, total = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        total += w[i];
    }

    printf("Enter target sum: ");
    scanf("%d", &m);

    printf("\nSubsets are:\n");
    sumOfSubsets(0, 1, total);

    return 0;
}