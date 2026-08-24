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

int isFull(struct queue *ptr)
{
    if (ptr->rear == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Queue overflow! Cannot enqueue %d to the queue\n", val);
    }
    else
    {
        if (ptr->front == -1)
        {
            ptr->front = 0; // if this is the first element being inserted, then the queue starts from index
        }
        ptr->rear++;
        ptr->arr[ptr->rear] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct queue *ptr)
{
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

int main()
{
    struct queue *q;
    q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 100;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 12);
    enqueue(q, 13);
    printf("Dequeuing element is %d \n", dequeue(q));
    // printf("Dequeuing element is %d \n", dequeue(q));

    if (isEmpty(&q))
    {
        printf("queue is empty\n");
    }
    if (isFull(&q))
    {
        printf("queue is full\n");
    }
    return 0;
}

