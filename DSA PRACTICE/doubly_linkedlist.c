#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

// TRAVERSAL
void traversal(struct Node *head)
{
    struct Node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// INSERT AT BEGINNING
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;

    if (head != NULL)
        head->prev = ptr;

    return ptr; // new head
}

// INSERT AT END
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if (head == NULL)
    {
        ptr->prev = NULL;
        return ptr;
    }

    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;

    return head;
}

// DELETE AT BEGINNING
struct Node *deleteAtFirst(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *ptr = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(ptr);

    return head;
}

// DELETE AT END
struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *p = head;

    // only one node
    if (p->next == NULL)
    {
        free(p);
        return NULL;
    }

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->prev->next = NULL;
    free(p);

    return head;
}

----------------------------------------------------
// MAIN
int main()
{
    struct Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Initial Doubly Linked List:\n");
    traversal(head);

    head = insertAtFirst(head, 5);
    printf("\nAfter Insertion at First:\n");
    traversal(head);

    head = deleteAtFirst(head);
    printf("\nAfter Deletion at First:\n");
    traversal(head);

    head = deleteAtEnd(head);
    printf("\nAfter Deletion at End:\n");
    traversal(head);

    return 0;
}