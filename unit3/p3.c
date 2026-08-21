#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*start,*newnode;

void insert_begin()
{
    struct Node * ptr;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = start;
    start = newnode;

    printf("Node inserted at beginning.\n");
}

void insert_after()
{
    int val;
    struct Node*ptr,*preptr;
    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    printf("enter value after which want to insert:");
    scanf("%d",&val);
    ptr = start;
    preptr = ptr;

    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;

    printf("node inserted after %d.\n",val);
}
void insert_end()
{
    struct Node * ptr;

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

void display()
{
    struct Node * ptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
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
        printf("2. Insert after\n");
        printf("3. Insert at end\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_after();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
