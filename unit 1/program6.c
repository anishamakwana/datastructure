void main()
{
    int a[10], i, max;

    printf("Enter 10 elements:\n");

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }

    max = a[0];

    for(i = 1; i < 10; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    printf("Largest value = %d", max);
getch();
}
