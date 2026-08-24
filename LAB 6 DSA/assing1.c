//Using array and functions implement Queue data structure to perform operations like insert, delete, and display.

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct queue *ptr)
{
    if (ptr->front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *ptr) {
    if (ptr->rear == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *ptr, int val) {
    if (isFull(ptr))
    {
       printf("Queue overflow! Cannot enqueue %d to the queue\n", val);
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
        if (ptr->front == -1)
        {
            ptr->front = 0;
        }
    }
}

void dequeue(struct queue *ptr) {
    if (isEmpty(ptr))
    {
        printf("Queue underflow! Cannot dequeue from an empty queue\n");
    }
    else
    {
        int val = ptr->arr[ptr->front];
        ptr->front++;
        if (ptr->front > ptr->rear)
        {
            ptr->front = ptr->rear = -1;
        }
        printf("Dequeued element: %d\n", val);
    }
}

void display(struct queue *ptr) {
    if (isEmpty(ptr))
    {
        printf("Queue is empty! Nothing to display\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = ptr->front; i <= ptr->rear; i++)
        {
            printf("%d ", ptr->arr[i]);
        }
        printf("\n");
    }
}
int main() {
    struct queue *q;
    q = (struct queue *) malloc(sizeof(struct queue));
    q->size = 80;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    printf(" Before inserting:  %d\n", isEmpty(q));
    printf("Before inserting: %d\n", isFull(q));
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    enqueue(q, 20);
    printf("After inserting: %d\n", isEmpty(q));
    printf("After inserting: %d\n", isFull(q));
    display(q);
    dequeue(q);
    display(q);
    return 0;
}