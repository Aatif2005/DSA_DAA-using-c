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

// Recursive insertion
struct Node* insert(struct Node* root, int data) {

    // If tree is empty
    if (root == NULL)
        return createNode(data);

    // Insert into left subtree
    if (data < root->data)
        root->left = insert(root->left, data);

    // Insert into right subtree
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Recursive searching
struct Node* search(struct Node* root, int key) {

    // Value not found
    if (root == NULL)
        return NULL;

    // Value found
    if (root->data == key)
        return root;

    // Search left subtree
    if (key < root->data)
        return search(root->left, key);

    // Search right subtree
    return search(root->right, key);
}

// Recursive inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Display BST
    printf("Inorder traversal: ");
    inorder(root);

    // Search for an element
    int key = 70;

    if (search(root, key) != NULL)
        printf("\n%d found in BST\n", key);
    else
        printf("\n%d not found in BST\n", key);

    return 0;
}