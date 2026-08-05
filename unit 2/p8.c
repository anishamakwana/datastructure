#include <stdio.h>
#include <conio.h>

int min, max;

void findMinMax(int a[], int n)
{
    if(n == 0)
        return;

    if(a[n - 1] < min)
        min = a[n - 1];

    if(a[n - 1] > max)
        max = a[n - 1];

    findMinMax(a, n - 1);
}

void main()
{
    int a[100], n, i;

    clrscr();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    min = max = a[0];

    findMinMax(a, n);

    printf("Minimum = %d\n", min);
    printf("Maximum = %d\n", max);

    getch();
}
