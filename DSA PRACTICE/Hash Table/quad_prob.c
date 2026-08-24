#include <stdio.h>
int main()
{
    int hasTable[10];
    int n, key, index;

    for (int i = 0; i < 10; i++)
    {
        hasTable[i] = -1;
    }
    printf("Enter number of elements:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter key");
        scanf("%d", &key);

        index = key % 10;
        j = 1;
        while (hasTable[index] != -1)
        {
            index = (key % 10 + j * j) % 10;
            j++;
        }
        hasTable[index] = key;
    }
    printf("\nHash Table:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Index %d : ", i);

        if (hasTable[i] == -1)
        {
            printf("Empty\n");
        }
        else
        {
            printf("%d\n", hasTable[i]);
        }
    }

    return 0;
}
