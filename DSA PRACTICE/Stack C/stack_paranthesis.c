#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    return (ptr->top == -1);
}

int isFull(struct stack *ptr)
{
    return (ptr->top == ptr->size - 1);
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack underflow! Cannot pop from the stack\n");
        return '\0';
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesisMatch(char *exp)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }

    int result = isEmpty(sp);

    free(sp->arr);
    free(sp);

    return result;
}

int main()
{
    char *exp1 = "8*(9)";
    char *exp2 = "((x+y)*(z+(a-b)))";

    if (parenthesisMatch(exp1))
    {
        printf("exp1: matching\n");
    }
    else
    {
        printf("exp1: not matching\n");
    }

    if (parenthesisMatch(exp2))
    {
        printf("exp2: matching\n");
    }
    else
    {
        printf("exp2: not matching\n");
    }
    return 0;
}