#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        head = insertAtBeginning(head, value);
    }

    printf("Linked list: ");
    display(head);

    return 0;
}