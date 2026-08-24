#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Traversal
void linkedlistTraversal(struct Node *head)
{
    struct Node *ptr = head;

    if (head == NULL)
        return;

    do
    {
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

// INSERT AT FIRST
struct Node *insertionatFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    // find last node
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }

    // adjust links
    p->next = ptr;
    ptr->next = head;

    return ptr; // new head
}

struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL)
    {
        ptr->next = ptr;
        return ptr;
    }
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

// DELETE FIRST
struct Node *deletionatFirst(struct Node *head)
{

    if (head == NULL)
        return NULL;

    // only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *ptr = head;
    struct Node *p = head;

    // find last node
    while (p->next != head)
    {
        p = p->next;
    }

    // adjust links
    p->next = head->next;
    head = head->next;

    free(ptr);
    return head;
}

struct Node *deletionatLast(struct Node *head)
{
    if (head == NULL)
        return NULL;

    // only one node
    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *p = head;
    struct Node *q = NULL;

    // move p to last node
    while (p->next != head)
    {
        q = p;
        p = p->next;
    }

    // q becomes second last node
    q->next = head;

    free(p);

    return head;
}
// MAIN
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // creating nodes
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linking nodes
    head->data = 31;
    head->next = second;

    second->data = 46;
    second->next = third;

    third->data = 52;
    third->next = fourth;

    fourth->data = 55;
    fourth->next = head;

    printf("Original Circular Linked List:\n");
    linkedlistTraversal(head);

    // INSERT
    head = insertionatFirst(head, 30);
    printf("\nAfter Insertion at First:\n");
    linkedlistTraversal(head);

    // DELETE
    head = deletionatFirst(head);
    printf("\nAfter Deletion at First:\n");
    linkedlistTraversal(head);

    // INSERT AT END
    head = insertAtEnd(head, 60);
    printf("\nAfter Insertion at End:\n");
    linkedlistTraversal(head);

    // DELETE AT END
    head = deletionatLast(head);
    printf("\nAfter Deletion at End:\n");
    linkedlistTraversal(head);

    return 0;
}