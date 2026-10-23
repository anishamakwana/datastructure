
#include <stdio.h>

int main()
{
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int visited[5] = {0};
    int queue[5], front = 0, rear = 0;
    int i, v;

    queue[rear++] = 0;
    visited[0] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < 5; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
