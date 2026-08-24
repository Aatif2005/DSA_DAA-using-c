// The peek operation in a stack is used to return the value of the top (most recently added) element without removing it.
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int Peek(struct stack *s, int i)
{
    int arrInd = s->top - i + 1;
    if (arrInd < 0)
    {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else
    {
        return s->arr[arrInd];
    }
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Stack has been created successfully\n");

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

    printf("Popped value from stack: %d\n", pop(s));

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at index %d is %d\n", j, Peek(s, j));
    }

    return 0;
}
/*agr hame stack me se top ka element niklana hai to uski time complexity O(1) hogi
isFull = O(1)
isEmpty O(1)
Push O(1)
Push O(1)
Peek O(1)*/