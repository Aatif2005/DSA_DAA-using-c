/*food dilivery order managment system using single linked list
1. add a new orde (ordr id, customer name, food items,)(insert at end)
2. prepare (delte order from begining)
3. display all pending order
4. exit*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int order_id;
    char customer_name[50];
    char item_name[50];
    struct node *next;
};
struct node *head = NULL;
void addOrder()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter order_id, customer_name, item_name ");
    scanf("%d %s %s", &newNode->order_id, newNode->customer_name, newNode->item_name);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
    printf("Order added sucessfully! ");
}

void prepareOrder()
{
    if (head == NULL)
    {
        printf("No pending order\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    printf("Order prepared");
    printf("Order ID %d\n", ptr->order_id);
    printf("Customer: %s\n", ptr->customer_name);
    printf("Food items: %s\n", ptr->item_name);

    free(ptr);
}

void displayOrder()
{
    if (head == NULL)
    {
        printf("No pending order ");
        return;
    }
    struct node *ptr = head;
    printf("Pending order ");

    while (ptr != NULL)
    {
        printf("Order ID %d\n", ptr->order_id);
        printf("Customer: %s\n", ptr->customer_name);
        printf("Food items: %s\n", ptr->item_name);
        ptr = ptr->next;
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("1. Add New Order\n");
        printf("2. Prepare Order\n");
        printf("3. Display All Pending Orders\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addOrder();
            break;
        case 2:
            prepareOrder();
            break;
        case 3:
            displayOrder();
            break;
        case 4:
            printf("\nExiting Program...\n");
            exit(0);
        default:
            printf("\nInvalid Choice! Try Again.\n");
        }

        
    }

    return 0;
}