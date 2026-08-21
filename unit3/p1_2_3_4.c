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

    newnode = (struct Node *)malloc(sizeof(struct Node));

    printf("enter value");
    scanf("%d",&newnode->data);

    newnode->next=NULL;
     start=newnode;

}

void insert_begin()
{
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

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

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

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

    if (newnode == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value to insert: ");
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
        return;
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
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &val);

    new_node->data = val;

    printf("Enter the value before which you want to insert: ");
    scanf("%d", &num);

    ptr = start;

    if (ptr == NULL)
    {
        printf("List is empty.\n");
        free(new_node);
        return;
    }

    if (ptr->data == num)
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
    struct Node *ptr, *preptr;

    if (start == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (start->next == NULL)
    {
        free(start);
        start = NULL;

        printf("Last node deleted.\n");
        return;
    }

    ptr = start;
    preptr = NULL;

    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;

    free(ptr);

    printf("Last node deleted.\n");
}

void delete_before()
{
    struct Node *ptr,*preptr,*prepreptr;
    int value;

    if(start == NULL || start->next == NULL)
    {
        printf("Not enough nodes in the list.\n");
        return;
    }
    printf("Enter the value before which you want to delete:");
    scanf("%d",&value);

    ptr = start;
    preptr = NULL;
    prepreptr = NULL;

    while (ptr != NULL && ptr ->data!=value)
    {
        prepreptr=preptr;
        preptr = ptr;
        ptr = ptr ->next;
    }
    if(ptr==NULL)
    {
        printf("Node %d not found.\n",value);
        return;
    }
    if(preptr==NULL)
    {
        printf("No node exist before %d.\n",value);
        return;
    }
    if(prepreptr==NULL)
    {
        start = ptr;
    }
    else
    {
        prepreptr->next=ptr;
    }

    free(preptr);

    printf("Node before %d deleted.\n",value);
}

void delete_after()
{
    struct Node *ptr,*temp;
    int value;

    if(start == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    printf("Enter the value after which you want to delete:");
    scanf("%d",&value);

    ptr = start;

    while (ptr != NULL && ptr ->data!=value)
    {
        ptr = ptr ->next;
    }
    if(ptr==NULL)
    {
        printf("Node %d not found.\n",value);
        return;
    }
    if(ptr->next ==NULL)
    {
        printf("No node exist after %d.\n",value);
        return;
    }

    temp = ptr->next;
    ptr->next=temp->next;

    free(temp);

    printf("Node after %d deleted :\n",value);
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
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert after specific node\n");
        printf("5. Insert before specific node\n");
        printf("6. Delete first node\n");
        printf("7. Delete last node\n");
        printf("8. Delete before node\n");
        printf("9. Delete after node\n");
        printf("10. Display\n");
        printf("11. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                create_ll();
                break;

            case 2:
                insert_begin();
                break;

            case 3:
                insert_end();
                break;

            case 4:
                insert_after();
                break;

            case 5:
                insert_before();
                break;

            case 6:
                delete_first();
                break;

            case 7:
                delete_last();
                break;

            case 8:
                delete_before();
                break;

            case 9:
                delete_after();
                break;

            case 10:
                display();
                break;

            case 11:
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    }

    return 0;
}
