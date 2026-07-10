void main()
{
    int a[3], b[3], c[6];
    int i,j;

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
        c[i] = a[i];
    }

    for(i=0,j=3;i<3;i++,j++)
    {
        c[j] = b[i];
    }

    printf("Array C after merge:\n");
    for(i = 0; i < 6; i++)
    {
        printf("%d ", c[i]);
    }
}
