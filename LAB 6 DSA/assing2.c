// Using array and functions implement Circular Queue data structure to perform operations like insert, delete, and display.

#include <stdio.h>

int queue[100];
int rear = -1;
int front = -1;

void insert()
{
    int x;
    if ((front == 0 && rear == 99) || (front == rear + 1))
    {
        printf("queue overflow");
    }

    else if (front == -1)
    {
        printf("Enter element: ");
        scanf("%d", &x);

        front = 0;
        rear = 0;

        queue[0] = x;
    }

    else if (front == 0 && rear < 99)
    {
        printf("Enter element: ");
        scanf("%d", &x);

        rear++;
        queue[rear] = x;
    }

    else if (front > 0 && rear == 99)
    {
        printf("Enter element: ");
        scanf("%d", &x);

        rear = 0;
        queue[rear] = x;
    }
}

void delte()
{
    if (front == -1)
    {
        printf("queue underflow");
    }
    else if (front == rear)
    {
        printf("Deleted element is %d", queue[front]);
        front = -1;
        rear = -1;
    }
    else if (front == 99)
    {
        printf("Deleted element is %d", queue[front]);
        front = 0;
    }
    else
    {
        printf("Deleted element is %d", queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("queue is empty");
    }
    else
    {
        printf("Queue elements are: ");
        for (i = front; i != rear; i = (i + 1) % 100)
        {
            printf("%d ", queue[i]);
        }
        printf("%d ", queue[rear]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delte();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}