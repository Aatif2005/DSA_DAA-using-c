//Write a C program to reverse a string using Stack.

#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(char value) {
    if (top == 99) {
        printf("Stack Overflow! Cannot push %c\n", value);
        return;
    }
    top++;
    stack[top] = value;
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop\n");
        return;
    }
    printf("%c", stack[top]);
    top--;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        push(str[i]);
    }
    printf("Reversed string: ");
    while (top != -1) {
        pop();
    }
    printf("\n");
    return 0;
}