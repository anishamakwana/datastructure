#include <stdio.h>

int stack[10];
int top = -1;

void push(int b)
{
    top++;
    stack[top] = b;
}

int pop()
{
    int v;
    v= stack[top];
    top --;
    return v;
}

void main()
{
    int b, p, i, val, mul = 1;

    printf("Enter base: ");
    scanf("%d", &b);

    printf("Enter power: ");
    scanf("%d", &p);

    for(i = 1; i <= p; i++)
    {
        push(b);
    }

    for(i = 1; i <= p; i++)
    {
        val = pop();
        mul = mul * val;
    }

    printf("%d ^ %d = %d", b, p, mul);

    return 0;
}
