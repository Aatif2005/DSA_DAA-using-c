#include <stdio.h>
#include <stdlib.h>

struct circularqueue {
    int size;
    int r;
    int f;
    int *arr;
};

int isEmpty(struct circularqueue *q) {
    return q->f == q->r;            // f == r means empty
}

int isFull(struct circularqueue *q) {
    return (q->r + 1) % q->size == q->f;
}

void enqueue(struct circularqueue *q, int val) {
    if (isFull(q)) {
        printf("The queue is full\n");
    } else {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueue element is %d \n", val);
    }
}

int dequeue(struct circularqueue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return -1;
    }
    q->f = (q->f + 1) % q->size;
    return q->arr[q->f];
}

int main() {
    struct circularqueue *qu;                                   // BUG FIX 1: cirularqueue → circularqueue
    qu = (struct circularqueue *)malloc(sizeof(struct circularqueue));

    qu->size = 6;
    qu->f = 0;
    qu->r = 0;
    qu->arr = (int *)malloc(qu->size * sizeof(int));

    enqueue(qu, 10);
    enqueue(qu, 20);
    enqueue(qu, 30);
    enqueue(qu, 40);
    enqueue(qu, 50);

    printf("Dequeued: %d\n", dequeue(qu));
    printf("Dequeued: %d\n", dequeue(qu));

    enqueue(qu, 60);
    enqueue(qu, 70);


    free(qu->arr);
    free(qu);
    return 0;
}