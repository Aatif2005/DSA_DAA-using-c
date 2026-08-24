#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr) {
    if(ptr-> top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct stack *ptr) {
    if(ptr->top == ptr->size-1) {
        return 1;
    }
    else {
        return 0;
    }
}

void Push(struct *ptr, int val) {
    if(isFull(ptr)) {
        printf("stack overflow! cannot push element %d to the stack\n ", val)
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int main() {
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*) malloc(s->size * sizeof(int));

    printf(" Before pushing:  %d\n", isEmpty(s));
    printf("Before pushing: %d\n", isFull(s));

    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);
    push(s, 16);
    push(s, 17);

    printf(" After pushing: %d\n", isEmpty(s));
    printf("After pushing: %d\n", isFull(s));

}