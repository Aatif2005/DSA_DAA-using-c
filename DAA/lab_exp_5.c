#include <stdio.h>

#define MAX 20

// Function to print the optimal parenthesization
void printParenthesis(int i, int j, int bracket[MAX][MAX])
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");

    printParenthesis(i, bracket[i][j], bracket);

    printParenthesis(bracket[i][j] + 1, j, bracket);

    printf(")");
}

int main()
{
    int n;
    int p[MAX];

    // m[i][j] stores minimum multiplication cost
    int m[MAX][MAX];

    // bracket[i][j] stores the position of split
    int bracket[MAX][MAX];

    int i, j, k, length;
    int cost;

    printf("=====================================\n");
    printf("   MATRIX CHAIN MULTIPLICATION\n");
    printf("   USING DYNAMIC PROGRAMMING\n");
    printf("=====================================\n");

    // Input number of matrices
    printf("\nEnter number of matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX)
    {
        printf("Invalid number of matrices!\n");
        return 0;
    }

    /*
       For n matrices, we need n+1 dimensions.

       Example:
       A1 = 10 x 30
       A2 = 30 x 5
       A3 = 5 x 60

       Dimensions = 10 30 5 60
    */

    printf("\nEnter %d dimensions:\n", n + 1);

    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Display matrices
    printf("\nMatrices are:\n");

    for (i = 1; i <= n; i++)
    {
        printf("A%d = %d x %d\n", i, p[i - 1], p[i]);
    }

    /*
       Cost of multiplying one matrix is zero.
       Therefore m[i][i] = 0.
    */

    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    /*
       length represents the number of matrices
       being multiplied together.

       Example:
       length = 2 -> A1A2
       length = 3 -> A1A2A3
       etc.
    */

    for (length = 2; length <= n; length++)
    {
        for (i = 1; i <= n - length + 1; i++)
        {
            j = i + length - 1;

            // Set a very large initial value
            m[i][j] = 999999;

            /*
               Try every possible position for
               placing the parenthesis.
            */

            for (k = i; k < j; k++)
            {
                cost = m[i][k]
                     + m[k + 1][j]
                     + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;

                    // Store the position of the split
                    bracket[i][j] = k;
                }
            }
        }
    }

    // Display DP table
    printf("\n=====================================\n");
    printf("          DP COST TABLE\n");
    printf("=====================================\n\n");

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (j < i)
                printf("     -");
            else
                printf("%6d", m[i][j]);
        }

        printf("\n");
    }

    // Display minimum cost
    printf("RESULT\n");

    printf("\nMinimum number of scalar multiplications = %d\n",
           m[1][n]);

    // Display optimal parenthesization
    printf("\nOptimal Parenthesization = ");

    printParenthesis(1, n, bracket);

    printf("\n");

    printf("COMPLEXITY\n");

    printf("\nTime Complexity  = O(n^3)");
    printf("\nSpace Complexity = O(n^2)\n");

    return 0;
}
