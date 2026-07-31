#include <stdio.h>
#include <conio.h>

void main()
{
    int n, i;

    clrscr();

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 2; i <= n; i++)
    {
        if(n % i == 0)
        {
            printf("Smallest Divisor = %d", i);
            break;
        }
    }

    getch();
}
