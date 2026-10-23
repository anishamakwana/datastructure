
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert node
struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Delete node
struct Node* deleteNode(struct Node *root, int value)
{
    struct Node *temp;

    if (root == NULL)
        return NULL;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = root->right;

        while (temp->left != NULL)
            temp = temp->left;

        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Height of tree
int height(struct Node *root)
{
    int left, right;

    if (root == NULL)
        return 0;

    left = height(root->left);
    right = height(root->right);

    if (left > right)
        return left + 1;
    else
        return right + 1;
}

// Count nodes
int countNodes(struct Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left)
             + countNodes(root->right);
}

// Inorder traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 6);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 13);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    printf("Inorder: ");
    inorder(root);

    printf("\nHeight of tree: %d", height(root));
    printf("\nTotal nodes: %d", countNodes(root));

    root = deleteNode(root, 10);

    printf("\nAfter deleting 10: ");
    inorder(root);

    return 0;
}
