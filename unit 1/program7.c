void main()
{
    int a[20], n, i, pos, x;

    printf("Enter size: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position and element: ");
    scanf("%d%d", &pos, &x);

    for(i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;

    for(i = 0; i <= n; i++)
        printf("%d ", a[i]);

    getch();
}
