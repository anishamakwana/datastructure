#include <stdio.h>
#include <stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i, data;

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

struct Node* merge(struct Node *head1, struct Node *head2)
{
    struct Node *temp;

    if(head1 == NULL)
        return head2;

    temp = head1;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

int main()
{
    struct Node *head1, *head2, *merged;
    int n1, n2;

    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    head1 = createList(n1);

    printf("First Linked List: ");
    display(head1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    head2 = createList(n2);

    printf("Second Linked List: ");
    display(head2);

    merged = merge(head1, head2);

    printf("Merged Linked List: ");
    display(merged);

    return 0;
}
