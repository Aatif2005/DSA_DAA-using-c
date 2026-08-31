#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Allocate matrix */
int **createMatrix(int n)
{
    int **A = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
        A[i] = (int *)malloc(n * sizeof(int));

    return A;
}

/* Free matrix */
void deleteMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
        free(A[i]);

    free(A);
}

/* Addition */
void add(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

/* Subtraction */
void subtract(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

/* Normal matrix multiplication */
void normalMultiply(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

/* Strassen multiplication */
void strassen(int **A, int **B, int **C, int n)
{
    /* Base case */
    if (n <= 2)
    {
        normalMultiply(A, B, C, n);
        return;
    }

    int s = n / 2;

    int **A11 = createMatrix(s);
    int **A12 = createMatrix(s);
    int **A21 = createMatrix(s);
    int **A22 = createMatrix(s);

    int **B11 = createMatrix(s);
    int **B12 = createMatrix(s);
    int **B21 = createMatrix(s);
    int **B22 = createMatrix(s);

    int **M1 = createMatrix(s);
    int **M2 = createMatrix(s);
    int **M3 = createMatrix(s);
    int **M4 = createMatrix(s);
    int **M5 = createMatrix(s);
    int **M6 = createMatrix(s);
    int **M7 = createMatrix(s);

    int **X = createMatrix(s);
    int **Y = createMatrix(s);

    int **C11 = createMatrix(s);
    int **C12 = createMatrix(s);
    int **C21 = createMatrix(s);
    int **C22 = createMatrix(s);

    /* Divide matrices */

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + s];
            A21[i][j] = A[i + s][j];
            A22[i][j] = A[i + s][j + s];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + s];
            B21[i][j] = B[i + s][j];
            B22[i][j] = B[i + s][j + s];
        }
    }

    /* M1 */
    add(A11, A22, X, s);
    add(B11, B22, Y, s);
    strassen(X, Y, M1, s);

    /* M2 */
    add(A21, A22, X, s);
    strassen(X, B11, M2, s);

    /* M3 */
    subtract(B12, B22, Y, s);
    strassen(A11, Y, M3, s);

    /* M4 */
    subtract(B21, B11, Y, s);
    strassen(A22, Y, M4, s);

    /* M5 */
    add(A11, A12, X, s);
    strassen(X, B22, M5, s);

    /* M6 */
    subtract(A21, A11, X, s);
    add(B11, B12, Y, s);
    strassen(X, Y, M6, s);

    /* M7 */
    subtract(A12, A22, X, s);
    add(B21, B22, Y, s);
    strassen(X, Y, M7, s);

    /* C11 = M1 + M4 - M5 + M7 */
    add(M1, M4, X, s);
    subtract(X, M5, Y, s);
    add(Y, M7, C11, s);

    /* C12 = M3 + M5 */
    add(M3, M5, C12, s);

    /* C21 = M2 + M4 */
    add(M2, M4, C21, s);

    /* C22 = M1 - M2 + M3 + M6 */
    subtract(M1, M2, X, s);
    add(X, M3, Y, s);
    add(Y, M6, C22, s);

    /* Combine */
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + s] = C12[i][j];
            C[i + s][j] = C21[i][j];
            C[i + s][j + s] = C22[i][j];
        }
    }

    /* Free memory */

    deleteMatrix(A11, s);
    deleteMatrix(A12, s);
    deleteMatrix(A21, s);
    deleteMatrix(A22, s);

    deleteMatrix(B11, s);
    deleteMatrix(B12, s);
    deleteMatrix(B21, s);
    deleteMatrix(B22, s);

    deleteMatrix(M1, s);
    deleteMatrix(M2, s);
    deleteMatrix(M3, s);
    deleteMatrix(M4, s);
    deleteMatrix(M5, s);
    deleteMatrix(M6, s);
    deleteMatrix(M7, s);

    deleteMatrix(X, s);
    deleteMatrix(Y, s);

    deleteMatrix(C11, s);
    deleteMatrix(C12, s);
    deleteMatrix(C21, s);
    deleteMatrix(C22, s);
}

/* Compare matrices */
int compare(int **A, int **B, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != B[i][j])
                return 0;

    return 1;
}

/* Print matrix */
void printMatrix(int **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d ", A[i][j]);

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);

    /* Check power of 2 */
    if (n <= 0 || (n & (n - 1)) != 0)
    {
        printf("Enter a power of 2: 2, 4, 8, 16, 32...\n");
        return 0;
    }

    int **A = createMatrix(n);
    int **B = createMatrix(n);
    int **C_normal = createMatrix(n);
    int **C_strassen = createMatrix(n);

    /* Generate random values */
    srand(time(NULL));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    /* Normal multiplication */
    clock_t start = clock();

    normalMultiply(A, B, C_normal, n);

    clock_t end = clock();

    double normalTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    /* Strassen multiplication */
    start = clock();

    strassen(A, B, C_strassen, n);

    end = clock();

    double strassenTime =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nMatrix Size: %d x %d\n", n, n);

    printf("\nNormal Multiplication Time   : %f seconds",
           normalTime);

    printf("\nStrassen Multiplication Time : %f seconds",
           strassenTime);

    /* Check results */
    if (compare(C_normal, C_strassen, n))
        printf("\n\nBoth methods produce the same result.\n");
    else
        printf("\n\nResults are different!\n");

    /* Print result only for small matrices */
    if (n <= 4)
    {
        printf("\nResult Matrix:\n");
        printMatrix(C_normal, n);
    }

    /* Free memory */
    deleteMatrix(A, n);
    deleteMatrix(B, n);
    deleteMatrix(C_normal, n);
    deleteMatrix(C_strassen, n);

    return 0;
}