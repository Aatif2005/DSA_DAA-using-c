#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *creatnode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node)); // ✅ malloc added
    n->data = data;
    n->right = NULL;
    n->left = NULL;
    return n;
}

void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main()
{
    struct node *p = creatnode(4);
    struct node *p1 = creatnode(1);
    struct node *p2 = creatnode(6);
    struct node *p3 = creatnode(5);
    struct node *p4 = creatnode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3; // ✅ attach to p1, not p again
    p1->right = p4;

    printf("Pre-order traversal: ");
    preOrder(p);
    printf("\nPost-order traversal: ");
    postorder(p);
    printf("\nIn-order traversal: ");
    inOrder(p);
    return 0;
}