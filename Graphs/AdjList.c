#include "AdjList.h"
#include "Stack.c"
#include "Queue.c"

undirected *init_graph(int v)
{
    undirected *graph = (undirected *)malloc(1 * sizeof(undirected));
    assert(graph);
    // intialize number of v
    graph->nVertices = v;
    graph->nEdges = 0;
    // intialize adjacency list
    graph->vertices = (vertex *)malloc(v * sizeof(vertex));
    // intialize each vertix
    for (int i = 0; i < v; i++)
    {
        graph->vertices[i].edgeCount = 0;
        graph->vertices[i].edgeCapacity = 0;
        graph->vertices[i].edges = NULL;
    }

    return graph;
}
void add_edge(undirected *g, int source, int dist)
{
    assert(g->nVertices > source);
    assert(g->nVertices > dist);
    assert(source >= 0);
    assert(dist >= 0);
    assert(source != dist);

    // check if the list is filled to double the size
    if (g->vertices[source].edgeCapacity == g->vertices[source].edgeCount)
    {
        g->vertices[source].edgeCapacity = g->vertices[source].edgeCapacity * 2 + 1;
        g->vertices[source].edges = realloc(g->vertices[source].edges, g->vertices[source].edgeCapacity * (sizeof(edge)));
        assert(g->vertices[source].edges);
    }
    g->vertices[source].edges[g->vertices[source].edgeCount].val = dist;
    g->vertices[source].edgeCount++;

    // check if the list is filled to double the size
    if (g->vertices[dist].edgeCapacity == g->vertices[dist].edgeCount)
    {
        g->vertices[dist].edgeCapacity = g->vertices[dist].edgeCapacity * 2 + 1;
        g->vertices[dist].edges = realloc(g->vertices[dist].edges, g->vertices[dist].edgeCapacity * (sizeof(edge)));
        assert(g->vertices[dist].edges);
    }
    g->vertices[dist].edges[g->vertices[dist].edgeCount].val = source;
    g->vertices[dist].edgeCount++;

    g->nEdges++;
}

void dfs(undirected *g, int v)
{
    Stack *stack = createStack();
    assert(stack);

    bool *visited = (bool *)malloc(g->nVertices * sizeof(bool));
    assert(visited); // we init a boolian array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }

    push(v, stack);

    while (!isEmpty(stack))
    {
        int cur = pop(stack);

        if (!visited[cur])
        {
            printf("%d -> ", cur);
            visited[cur] = true;

            for (int i = g->vertices[cur].edgeCount - 1; i >= 0; i--)
            {
                int neighbor = g->vertices[cur].edges[i].val;
                if (!visited[neighbor])
                {
                    push(neighbor, stack);
                }
            }
        }
    }

    printf("End\n");
    freeStack(stack);
    free(visited);
}

void bfs(undirected *g, int v)
{
    queue *queue = initQueue();
    assert(queue);

    bool *visited = (bool *)malloc(g->nVertices * sizeof(bool));
    assert(visited); // we init a boolian array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }

    enqueue(v, queue);

    while (!Q_isEmpty(queue))
    {
        int cur = dequeue(queue);

        if (!visited[cur])
        {
            printf("%d -> ", cur);
            visited[cur] = true;

            for (int i = g->vertices[cur].edgeCount - 1; i >= 0; i--)
            {
                int neighbor = g->vertices[cur].edges[i].val;
                if (!visited[neighbor])
                {
                    enqueue(neighbor, queue);
                }
            }
        }
    }

    printf("End\n");
    freeQueue(queue);
    free(visited);
}
