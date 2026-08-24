// Check whether the string is palindrome or not using array and Queue.

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char queue[100];
    int front = 0, rear = -1;
    int i, len, palindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        rear++;
        queue[rear] = str[i];
    }

    for (i = len - 1; i >= 0; i--)
    {
        if (str[i] != queue[front])
        {
            palindrome = 0;
            break;
        }
        front++;
    }

    if (palindrome == 1)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");

    return 0;
}