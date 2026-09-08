#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;


void create()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
    {
        start->prev = newnode;
    }

    start = newnode;
}


void insertBeginning()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = start;

    if (start != NULL)
    {
        start->prev = newnode;
    }

    start = newnode;

    printf("Node inserted at beginning.\n");
}


void insertEnd()
{
    struct node *newnode;
    struct node *ptr;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (start == NULL)
    {
        newnode->prev = NULL;
        start = newnode;
        printf("Node inserted at end.\n");
        return;
    }

    ptr = start;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;

    printf("Node inserted at end.\n");
}


void display()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");

    for (ptr = start; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }

    printf("\n");
}

int main()
{
    int n, i, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        create();
    }

    display();

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

