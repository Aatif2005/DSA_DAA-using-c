#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void linkedlistTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Check empty
int isEmpty(struct Node *top)
{
    return (top == NULL);
}

// Check full
int isFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
        return 1;

    free(n); // important fix
    return 0;
}

// Push
struct Node *push(struct Node *top, int val)
{
    if (isFull(top))
    {
        printf("Stack overflow! Cannot push %d\n", val);
        return top;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;

    return top;
}

// ✅ FIXED POP
struct Node *pop(struct Node *top, int *val)
{
    if (isEmpty(top))
    {
        printf("Stack underflow!\n");
        return top;
    }

    struct Node *ptr = top;
    *val = ptr->data;

    top = top->next;
    free(ptr);

    return top;
}

// Peek
int peek(struct Node *top, int pos)
{
    struct Node *ptr = top;

    for (int i = 1; i < pos && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
        return ptr->data;

    return -1;
}

// Main
int main()
{
    struct Node *top = NULL;

    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);

    int element;
    top = pop(top, &element); // FIX: update top
    printf("Popped element is %d\n", element);

    for (int i = 1; i <= 3; i++) // FIX: start from 1
    {
        printf("Element at position %d is %d\n", i, peek(top, i));
    }

    linkedlistTraversal(top);

    return 0;
}