
#include <stdio.h>

int graph[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 0}
};

int visited[5] = {0};

void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < 5; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    printf("DFS Traversal: ");
    DFS(0);

    return 0;
}
