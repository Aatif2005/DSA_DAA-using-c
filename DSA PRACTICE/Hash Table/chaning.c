#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *hashTable[10];
    struct Node *newNode, *ptr;

    int n, key, index;

    // Initialize hash table with NULL
    for (int i = 0; i < 10; i++)
    {
        hashTable[i] = NULL;
    }

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Insert elements
    for (int i = 0; i < n; i++)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        index = key % 10;

        // Create new node
        newNode = (struct Node *)malloc(sizeof(struct Node));

        newNode->data = key;
        newNode->next = NULL;

        // If no element at index
        if (hashTable[index] == NULL)
        {
            hashTable[index] = newNode;
        }
        else
        {
            // Move to last node
            ptr = hashTable[index];

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            // Attach new node
            ptr->next = newNode;
        }
    }

    // Display hash table
    printf("\nHash Table:\n");

    for (int i = 0; i < 10; i++)
    {
        printf("Index %d : ", i);

        ptr = hashTable[i];

        if (ptr == NULL)
        {
            printf("Empty");
        }
        else
        {
            while (ptr != NULL)
            {
                printf("%d -> ", ptr->data);
                ptr = ptr->next;
            }
            printf("NULL");
        }

        printf("\n");
    }

    return 0;
}