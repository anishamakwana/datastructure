#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void insert_begin()
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = start;
    start = newnode;

    printf("Node inserted at beginning.\n");
}

void insert_end()
{
    struct Node *newnode, *ptr;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        ptr = start;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }

    printf("Node inserted at end.\n");
}

void insert_after()
{
    struct Node *newnode, *ptr;
    int value;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    printf("Enter the value after which you want to insert: ");
    scanf("%d", &value);

    ptr = start;

    while (ptr != NULL && ptr->data != value)
    {
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        free(newnode);
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    printf("Node inserted after %d.\n", value);
}

void insert_before()
{
    struct Node *new_node, *ptr, *preptr;
    int val, num;

    new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL)
    {
        printf("OVERFLOW\n");
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);
    new_node->data = val;

    printf("Enter the value before which you want to insert: ");
    scanf("%d", &num);

    ptr = start;

    if (ptr != NULL && ptr->data == num)
    {
        new_node->next = ptr;
        start = new_node;

        printf("Node inserted before %d.\n", num);
        return;
    }

    preptr = ptr;

    while (ptr != NULL && ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", num);
        free(new_node);
        return;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    printf("Node inserted before %d.\n", num);
}

void delete_first()
{
    struct Node *ptr;
    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    ptr = start;
    start = start->next;

    free(ptr);

    printf("First node deleted.\n");
}
void delete_last()
{
    struct Node *ptr ,*preptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
    }

    ptr = start;
    preptr = ptr;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;

    free(ptr);

    printf("Last node deleted.\n");
}

void display()
{
    struct Node *ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
    }

    ptr = start;

    printf("Linked List: ");

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n----- Singly Linked List -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after specific node\n");
        printf("4. Insert before specific node\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_after();
                break;

            case 4:
                insert_before();
                break;

            case 5:
                delete_first();
                break;

            case 6:
                delete_last();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
