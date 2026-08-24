#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node (order)
struct Node {
    int orderID;
    struct Node *next;
};

// Global pointer to the first node (head of the list)
struct Node *head = NULL;

// Function to insert a new order at the end
void insertEnd(int id) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->orderID = id;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL) {
        head = newNode;
    } 
    else {
        struct Node *temp = head;
        // Traverse to the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to display all orders
void display() {
    struct Node *temp = head;
    printf("Order Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->orderID);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int choice, id;

    while (1) {
        printf("\n--- Online Food Order Queue System ---\n");
        printf("1. Add new order\n");
        printf("2. Display order queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Order ID: ");
                scanf("%d", &id);
                insertEnd(id);
                printf("Order added successfully.\n");
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting system...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
