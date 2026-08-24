#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr; /* This is a pointer to an integer array.
               It will store the actual stack elements. */
};

int isEmpty(struct stack* ptr) {
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack* ptr) {
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int main() {
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 89;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // manually pushing elements in the stack

    s->arr[0] = 5;
    s->top++; 

    if (isEmpty(s))
    {
       printf("The stack is empty");
    }
    else
    {
        printf("The stack is full");
    }
    return 0;
}
