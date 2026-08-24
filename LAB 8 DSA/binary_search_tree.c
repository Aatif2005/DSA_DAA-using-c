#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;  // Fixed: Added missing return statement
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);  // Fixed: Changed insert to deleteNode
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);  // Fixed: Changed insert to deleteNode
    }
    else {
        // Node with no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Node with only right child
        else if (root->left == NULL) {
            struct Node *ptr = root->right;  // Fixed: Changed from root->left to root->right
            free(root);
            return ptr;
        }
        // Node with only left child
        else if (root->right == NULL) {
            struct Node *ptr = root->left;  // Fixed: Changed from root->right to root->left
            free(root);
            return ptr;
        }
        // Node with two children
        else {
            struct Node* successor = minValueNode(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

// New: Search function for BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    }
    
    return search(root->right, data);
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // 🔹 INSERT VALUES
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal after insertion:\n");
    inorder(root);
    printf("\n");

    // 🔹 SEARCH
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL)
        printf("%d found in the tree\n", key);
    else
        printf("%d not found\n", key);

    // 🔹 DELETE
    printf("\nDeleting 50...\n");
    root = deleteNode(root, 50);

    printf("Inorder Traversal after deletion:\n");
    inorder(root);
    printf("\n");

    return 0;
}