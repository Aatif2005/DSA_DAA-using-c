#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node *minvalueNode(struct Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            struct Node *ptr = root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL)
        {
            struct Node *ptr = root->left;
            free(root);
            return ptr;
        }
        else
        {
            struct Node *successor = minvalueNode(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }
    }
    return root;
}

int main()
{
    struct Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}