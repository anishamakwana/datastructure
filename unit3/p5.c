#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *start = NULL;
struct node *newnode;

void create()
{
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
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        create();
    }

    display();

    return 0;
}
