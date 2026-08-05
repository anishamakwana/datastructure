#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        queue[++rear] = value;
    }
}

void deleteQueue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("Deleted: %d\n", queue[front++]);

        // Reset queue when it becomes empty
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void print()
{
    int i;

    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue Elements: ");
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;

        case 2:
            deleteQueue();
            break;

        case 3:
            print();
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
