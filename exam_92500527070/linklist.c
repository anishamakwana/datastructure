//leet code program definition 203.
//remove link list element.

#include<stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*start,*newnode;

struct Node *start = NULL;

void create_ll()
{

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("enter value:");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
    start=newnode;
}

void delete_specific()
{
    struct Node *ptr, *preptr;
    int value;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter the value to delete: ");
    scanf("%d", &value);

    ptr = start;

    if (ptr->data == value)
    {
        start = ptr->next;
        free(ptr);

        printf("Node %d deleted.\n", value);
        return;
    }

    preptr = ptr;
    ptr = ptr->next;

    while (ptr != NULL && ptr->data != value)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL)
    {
        printf("Node %d not found.\n", value);
        return;
    }

    preptr->next = ptr->next;
    free(ptr);

    printf("Node %d deleted.\n", value);
}

void display()
{
    struct Node *ptr;

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
        printf("1. Create \n");
        printf("2. Delete_specific\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create_ll();
                break;

            case 2:
                delete_specific();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}

