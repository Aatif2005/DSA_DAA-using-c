//Implement the Stack data structure using an array in C and perform basic operations like Push, Pop, Peek and Display.

#include <stdio.h>
#include <stdlib.h>

int stack[100];   
int top = -1;     
int MAX = 100;    

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is: %d\n", stack[top]);
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}