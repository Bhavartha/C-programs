#include <stdio.h>
#define MAX 10

int queue[MAX], graph[MAX][MAX] = {0}, visited[MAX] = {0}, front = 0, rear = -1;

int empty()
{
    if (front > rear)
        return 1;
    return 0;
}

void bfs(int vertex, int n)
{
    int i;
    queue[++rear] = vertex;
    visited[vertex] = 1;
    while (!empty())
    {
        vertex = queue[front++];
        printf("%d ", vertex);
        for (i = 0; i < n; i++)
            if (graph[vertex][i] != 0 && visited[i] == 0)
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
    }
}

void main()
{
    int n_edges, i, a, b, n;
    printf("\nBFS using Queue");
    printf("\nEnter no. of vertices(max 10) and edges: ");
    scanf("%d%d", &n, &n_edges);
    printf("\nConsider vertices from 0-%d", n - 1);
    for (i = 0; i < n_edges; i++)
    {
        printf("\nEnter vertices for edge %d: ", i + 1);
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
    }
    printf("\nEnter the starting vertex (0-%d): ", n - 1);
    scanf("%d", &i);
    printf("\nBFS: ");
    bfs(i, n);
}