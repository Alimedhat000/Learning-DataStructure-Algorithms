#include "AdjMatrix.h"

M_undirected *M_init_graph(int v)
{
    M_undirected *g = (M_undirected *)malloc(1 * sizeof(M_undirected));
    assert(g);

    g->nVertices = v + 1;
    g->AdjMatrix = (int **)malloc((size_t)(v + 1) * sizeof(int *));
    assert(g->AdjMatrix);

    for (int i = 0; i < v + 1; i++)
    {
        g->AdjMatrix[i] = (int *)malloc((size_t)(v + 1) * sizeof(int));
        assert(g->AdjMatrix[i]);
        for (int j = 0; j < v + 1; j++)
        {
            g->AdjMatrix[i][j] = 0;
        }
    }
    return g;
}

void M_add_edge(M_undirected *g, int source, int dist)
{
    // Check if indices are within bounds and distinct
    assert(source >= 0 && dist >= 0);
    assert(source < g->nVertices && dist < g->nVertices);
    assert(dist != source);

    g->AdjMatrix[source][dist] = 1;
    g->AdjMatrix[dist][source] = 1;
}

void M_dfs(M_undirected *g, int v)
{
    bool *visited = (bool *)malloc((size_t)g->nVertices * (sizeof(bool)));
    assert(visited);
    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }
    Stack *stack = createStack();
    assert(stack);
    push(v, stack);
    while (!isEmpty(stack))
    {
        int cur = pop(stack);

        if (!visited[cur])
        {
            printf("%d -> ", cur);
            visited[cur] = true;
            for (int i = 0; i < g->nVertices; i++)
            {
                if (g->AdjMatrix[cur][i] == 1 && !visited[i])
                {
                    push(i, stack);
                }
            }
        }
    }

    printf("End\n");
    freeStack(stack);
    free(visited);
}

void M_bfs(M_undirected *g, int v)
{
    bool *visited = (bool *)malloc((size_t)g->nVertices * (sizeof(bool)));
    assert(visited);
    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }

    queue *q = initQueue();
    assert(q);

    enqueue(v, q);
    while (!Q_isEmpty(q))
    {
        int cur = dequeue(q);
        printf("%d -> ", cur);

        if (!visited[cur])
        {
            for (int i = 0; i < g->nVertices; i++)
            {
                if (g->AdjMatrix[cur][i] == 1 && !visited[i])
                {
                    enqueue(i, q);
                }
            }
        }
    }
}