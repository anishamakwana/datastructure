#include <stdio.h>

void main()
{
    int a[3], b[3], c[3];
    int i;

    printf("Enter 3 elements for array A:\n");
    for(i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter 3 elements for array B:\n");
    for(i = 0; i < 3; i++)
    {
        scanf("%d", &b[i]);
    }

    for(i = 0; i < 3; i++)
    {
        c[i] = a[i] + b[i];
    }

    printf("after addition C:\n");
    for(i = 0; i < 3; i++)
    {
        printf("%d ", c[i]);
    }
}
