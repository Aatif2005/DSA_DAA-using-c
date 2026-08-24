#include <stdio.h>
#include <stdlib.h>

// Structure of a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Iterative insertion
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    // If tree is empty
    if (root == NULL)
        return newNode;

    struct Node* current = root;
    struct Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data)
            current = current->left;
        else if (data > current->data)
            current = current->right;
        else {
            // Duplicate value
            free(newNode);
            return root;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Iterative search
struct Node* search(struct Node* root, int key) {
    struct Node* current = root;

    while (current != NULL) {
        if (key == current->data)
            return current;

        if (key < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return NULL;
}

// Inorder traversal using a stack
void inorder(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {

        // Go to the leftmost node
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        // Process node
        current = stack[top--];
        printf("%d ", current->data);

        // Move to right subtree
        current = current->right;
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    int key = 60;

    if (search(root, key) != NULL)
        printf("\n%d found in BST\n", key);
    else
        printf("\n%d not found in BST\n", key);

    return 0;
}