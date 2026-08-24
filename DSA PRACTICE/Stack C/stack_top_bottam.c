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

int isFull(struct stack *ptr, int val)
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

int Peek(struct stack *s, int i)
{
    int arrInd = s->top - i + 1;
    if (arrInd < 0)
    {
        printf("No valid position for stack\n");
        return -1;
    }
    else
    {
        s->arr[arrInd];
    }
}

int StackTop(struct stack *s)
{
    return s->arr[s->top];
}

int StackBottam(struct *s) {
    return s->arr[0];
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
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

    return 0;
}