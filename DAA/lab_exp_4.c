#include <stdio.h>
#include <limits.h>
#include <time.h>

#define MAX 100

/* Print optimal parenthesization */
void printParenthesis(int i, int j, int s[MAX][MAX])
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");

    printParenthesis(i, s[i][j], s);
    printParenthesis(s[i][j] + 1, j, s);

    printf(")");
}

/* Matrix Chain Multiplication using Dynamic Programming */
long long matrixChainOrder(int p[], int n, int s[MAX][MAX])
{
    long long m[MAX][MAX];

    int i, j, k, length;

    /* Cost of multiplying one matrix is zero */
    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    /* length = number of matrices in the chain */
    for (length = 2; length <= n; length++)
    {
        for (i = 1; i <= n - length + 1; i++)
        {
            j = i + length - 1;

            m[i][j] = LLONG_MAX;

            /* Try every possible split */
            for (k = i; k < j; k++)
            {
                long long cost =
                    m[i][k]
                    + m[k + 1][j]
                    + (long long)p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    return m[1][n];
}

/* Display DP cost table */
void printCostTable(int p[], int n)
{
    long long m[MAX][MAX];

    int i, j, k, length;

    for (i = 1; i <= n; i++)
        m[i][i] = 0;

    for (length = 2; length <= n; length++)
    {
        for (i = 1; i <= n - length + 1; i++)
        {
            j = i + length - 1;
            m[i][j] = LLONG_MAX;

            for (k = i; k < j; k++)
            {
                long long cost =
                    m[i][k]
                    + m[k + 1][j]
                    + (long long)p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                    m[i][j] = cost;
            }
        }
    }

    printf("\nDP Cost Table:\n\n");

    printf("       ");
    for (i = 1; i <= n; i++)
        printf("%10d", i);

    printf("\n");

    for (i = 1; i <= n; i++)
    {
        printf("A%-4d", i);

        for (j = 1; j <= n; j++)
        {
            if (j < i)
                printf("%10s", "-");
            else
                printf("%10lld", m[i][j]);
        }

        printf("\n");
    }
}

/* Calculate cost for a specific parenthesization */
long long multiplyCost(int p[], int i, int j, int s[MAX][MAX])
{
    if (i == j)
        return 0;

    int k = s[i][j];

    long long leftCost =
        multiplyCost(p, i, k, s);

    long long rightCost =
        multiplyCost(p, k + 1, j, s);

    long long multiplicationCost =
        (long long)p[i - 1] * p[k] * p[j];

    return leftCost + rightCost + multiplicationCost;
}

int main()
{
    int n;
    int p[MAX];
    int s[MAX][MAX] = {0};

    printf("=============================================\n");
    printf("     MATRIX CHAIN MULTIPLICATION USING DP\n");
    printf("=============================================\n");

    printf("\nEnter number of matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX)
    {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    /*
       If there are n matrices, we need n+1 dimensions.

       Example:
       A1 = 10 x 30
       A2 = 30 x 5
       A3 = 5 x 60

       p = {10, 30, 5, 60}
    */

    printf("\nEnter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++)
    {
        printf("p[%d] = ", i);
        scanf("%d", &p[i]);
    }

    /* Display matrices */
    printf("\nMatrices:\n");

    for (int i = 1; i <= n; i++)
    {
        printf("A%d = %d x %d\n",
               i,
               p[i - 1],
               p[i]);
    }

    /* Measure DP execution time */
    clock_t start = clock();

    long long minimumCost =
        matrixChainOrder(p, n, s);

    clock_t end = clock();

    double executionTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    /* Results */
    printf("RESULT\n");

    printf("\nMinimum number of scalar multiplications: %lld\n",
           minimumCost);

    printf("\nOptimal Parenthesization:\n");
    printParenthesis(1, n, s);

    printf("\n");

    printf("\nDP Execution Time: %.9f seconds\n",
           executionTime);

    /* Cost table */
    printCostTable(p, n);

    printf(" ANALYSIS\n");

    printf("\nDynamic Programming complexity:\n");
    printf("Time Complexity  : O(n^3)\n");
    printf("Space Complexity : O(n^2)\n");

    printf("\nThe optimal parenthesization minimizes the\n");
    printf("number of scalar multiplications required.\n");

    return 0;
}