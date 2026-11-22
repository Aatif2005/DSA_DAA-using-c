#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int wt[], int profit[], int n,
             int W, int i, int currentWeight,
             int currentProfit)
{
    if (i == n)
        return currentProfit;

    // Exclude current item
    int exclude = knapsack(wt, profit, n, W,
                           i + 1, currentWeight,
                           currentProfit);

    int include = 0;

    // Include current item if capacity allows
    if (currentWeight + wt[i] <= W)
    {
        include = knapsack(wt, profit, n, W,
                           i + 1,
                           currentWeight + wt[i],
                           currentProfit + profit[i]);
    }

    return max(include, exclude);
}

int main()
{
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int wt[n], profit[n];

    printf("Enter weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    printf("Maximum Profit = %d\n",
           knapsack(wt, profit, n, W, 0, 0, 0));

    return 0;
}