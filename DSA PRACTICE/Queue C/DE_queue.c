#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct deque {
    struct node *front;
    struct node *rear;
};

int isEmpty(struct deque *dq) {
    if (dq->front == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void insertFront(struct deque *dq, int val) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = val;
    n->prev = NULL;
    if (isEmpty(dq)) {
        n->next = NULL;
        dq->front = dq->rear = n;
    }
    else {
        n->next = dq->front;
        dq->front->prev = n;
        dq->front = n;
    }
    printf("Inserted at front: %d\n", val);
}

void insertRear(struct deque *dq, int val) {
    struct node *n = (struct node *) malloc(sizeof(struct node));
    n->data = val;
    n->prev = NULL;
    if (isEmpty(dq)) {
        n->next = NULL;
        dq->front = dq->rear = n;
    }
    else {
        n->prev = dq->rear;
        dq->rear->next = n;
        dq->rear = n;
    }
}

int deleteFront(struct deque *dq) {

    if (isEmpty(dq)) {
        printf("Deque underflow!\n");
        return -1;
    }

    struct node *ptr = dq->front;
    int val = ptr->data;

    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    }
    else {
        dq->front->prev = NULL;
    }

    free(ptr);

    printf("Deleted from front: %d\n", val);
    return val;
}

int deleteRear(struct deque *dq) {

    if (isEmpty(dq)) {
        printf("Deque underflow!\n");
        return -1;
    }

    struct node *ptr = dq->rear;
    int val = ptr->data;

    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    }
    else {
        dq->rear->next = NULL;
    }

    free(ptr);

    printf("Deleted from rear: %d\n", val);
    return val;
}

int main() {

    struct deque *dq = (struct deque *) malloc(sizeof(struct deque));
    dq->front = NULL;
    dq->rear = NULL;

    insertFront(dq, 10);
    insertRear(dq, 20);
    insertFront(dq, 5);
    insertRear(dq, 30);

    deleteFront(dq);
    deleteRear(dq);

    return 0;
}