#include <stdio.h>

int main()
{
    int hashTable[10];
    int n, key, index;

    // Initialize hash table with -1 (empty)
    for (int i = 0; i < 10; i++)
    { 
        hashTable[i] = -1;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insertion using Linear Probing
    for (int i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        index = key % 10;

        // Linear probing if collision occurs
        while (hashTable[index] != -1)
        {
            index = (index + 1) % 10;
        }

        hashTable[index] = key;
    }

    // Display hash table
    printf("\nHash Table:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Index %d : ", i);

        if (hashTable[i] == -1)
        {
            printf("Empty\n");
        }
        else
        {
            printf("%d\n", hashTable[i]);
        }
    }

    return 0;
}