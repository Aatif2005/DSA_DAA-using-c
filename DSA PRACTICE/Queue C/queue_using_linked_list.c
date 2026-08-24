#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Queue pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted %d\n", value);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *ptr = front;
    printf("Deleted %d\n", ptr->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(ptr);
}
              
// Display queue
void queueTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    queueTraversal(front);

    dequeue();
    queueTraversal(front);

    return 0;
}