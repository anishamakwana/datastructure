#include <stdio.h>

void main()
{
    int a[10], j , b , i;

    printf("Enter the number of elements: ");
    scanf("%d", &j);

    printf("Enter array elements:\n");
    for (i = 0; i < j; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete: ");
    scanf("%d", &b);

    if (b < 1 || b > j)
    {
        printf("Invalid position");
    }
    else
    {
        for (i = b - 1; i < j - 1; i++)
        {
            a[i] = a[i + 1];
        }

        j--;

        printf("Array after deletion:\n");
        for (i = 0; i < j; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
