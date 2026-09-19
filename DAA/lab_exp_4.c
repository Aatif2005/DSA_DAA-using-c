#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start times (space separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }

    printf("Enter finish times (space separated): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &finish[i]);
    }

    printf("\nSelected Activities:\n");

    // Select the first activity
    int i = 0;
    printf("Activity %d ", i + 1);

    // Select remaining activities using greedy approach
    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("Activity %d ", j + 1);
            i = j;
        }
    }

    printf("\n");

    return 0;
}