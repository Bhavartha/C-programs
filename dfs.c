#include <stdio.h>

#define max 10

int graph[max][max] = {0}, visited[max] = {0};

void dfs(int vertex, int n)
{
    int i;
    visited[vertex] = 1;
    printf("%d  ", vertex);
    for (i = 0; i < n; i++)
    {
        if (graph[vertex][i] != 0 && visited[i] == 0)
        {
            dfs(i, n);
        }
    }
}

void main()
{
    int n_edges, i, a, b, n;
    printf("\nDFS using stack");
    printf("\nEnter no. of vertices(max 10) and edges: ");
    scanf("%d%d", &n, &n_edges);
    for (i = 0; i < n_edges; i++)
    {
        printf("\nEnter vertices for edge %d: ", i + 1);
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
    }
    printf("\nEnter the starting vertex (0-%d): ", n - 1);
    scanf("%d", &i);
    printf("\nDFS: ");
    dfs(i, n);
}