#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[10];
int top=-1;
//Function to push an element into the stack

void push()
{
    int val;
    if(top== MAX - 1)
    {
        printf("\nStack Overflow!Cannot insert element.\n");
    }

    else

    {
        printf("Enter element to push:");
        scanf("%d",&val);
        top++;
        stack[top] = val;
        printf("inserted successfully\n");
    }
}
//Function to pop element from the stack
void pop()
{
    if(top==-1)
    {
        printf("\nStack Underflow!Stack is empty.\n");
    }
    else
    {
        printf("Deleted element is:%d\n",stack[top]);
        top--;
    }
}
//Function to Display stack elements
void display()
{
    int i;

    if(top==-1)
    {
        printf("\nStack is empty.\n");
    }
    else
    {
        printf("\nStack elements are:\n");

        for(i=top;i<=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}
// Peek operation
void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is: %d\n", stack[top]);
    }
}
// Update operation
void update(int position, int value)
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else if (position < 1 || position > top + 1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        stack[position - 1] = value;
        printf("Element updated successfully.\n");
    }
}
//Main function
void main()
{
    int choice,value,position;
    while(1)
    {
        printf("\n------STACK MENU------\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Peek\n");
        printf("5.Update\n");
        printf("6.Exit\n");

        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
            {
                int position, value;
                printf("Enter position (1 to %d): ", top + 1);
                scanf("%d", &position);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(position, value);
            }
            break;

            case 6:
                printf("Exiting Program...\n");
                exit(0);

                default:
                printf("Invalid choice!Please enter a valid option.\n");
        }
    }
}
