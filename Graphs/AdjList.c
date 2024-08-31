#include "AdjList.h"

undirected *init_u_graph(int v)
{
    undirected *graph = (undirected *)malloc(1 * sizeof(undirected));
    assert(graph);
    // initialize number of v
    graph->nVertices = v;
    graph->nEdges = 0;
    // initialize adjacency list
    graph->vertices = malloc((size_t)v * sizeof(vertex));
    // initialize each vertex
    for (int i = 0; i < v; i++)
    {
        graph->vertices[i].edgeCount = 0;
        graph->vertices[i].edgeCapacity = 0;
        graph->vertices[i].edges = NULL;
    }

    return graph;
}
void add_u_edge(undirected *g, int source, int dist, int weight)
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
        g->vertices[source].edges = realloc(g->vertices[source].edges, (size_t)g->vertices[source].edgeCapacity * (sizeof(edge)));
        assert(g->vertices[source].edges);
    }
    g->vertices[source].edges[g->vertices[source].edgeCount].val = dist;
    g->vertices[source].edges[g->vertices[source].edgeCount].weight = weight;
    g->vertices[source].edgeCount++;

    // check if the list is filled to double the size
    if (g->vertices[dist].edgeCapacity == g->vertices[dist].edgeCount)
    {
        g->vertices[dist].edgeCapacity = g->vertices[dist].edgeCapacity * 2 + 1;
        g->vertices[dist].edges = realloc(g->vertices[dist].edges, (size_t)g->vertices[dist].edgeCapacity * (sizeof(edge)));
        assert(g->vertices[dist].edges);
    }
    g->vertices[dist].edges[g->vertices[dist].edgeCount].val = source;
    g->vertices[dist].edges[g->vertices[dist].edgeCount].weight = weight;
    g->vertices[dist].edgeCount++;

    g->nEdges++;
}

void free_undirected_graph(undirected *g)
{
    for (int i = 0; i < g->nVertices; i++)
    {
        free(g->vertices[i].edges);
    }
    free(g->vertices);
    free(g);
}

void u_dfs(undirected *g, int v)
{
    Stack *stack = createStack();
    assert(stack);

    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

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

void u_bfs(undirected *g, int v)
{
    queue *q = initQueue();
    assert(q);

    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }

    enqueue(v, q);

    while (!Q_isEmpty(q))
    {
        int cur = dequeue(q);

        if (!visited[cur])
        {
            printf("%d -> ", cur);
            visited[cur] = true;

            for (int i = g->vertices[cur].edgeCount - 1; i >= 0; i--)
            {
                int neighbor = g->vertices[cur].edges[i].val;
                if (!visited[neighbor])
                {
                    enqueue(neighbor, q);
                }
            }
        }
    }

    printf("End\n");
    freeQueue(q);
    free(visited);
}

void u_dfs_recursive(undirected *g, int v)
{
    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }
    _u_traversal(g, visited, v);
    printf("End\n");
    free(visited);
}

void _u_traversal(undirected *g, bool *visited, int v)
{
    printf("%d -> ", v);
    visited[v] = true;
    for (int i = 0; i < g->vertices[v].edgeCount; i++)
    {
        int neighbor = g->vertices[v].edges[i].val;
        if (!visited[neighbor])
        {
            _u_traversal(g, visited, neighbor);
        }
    }
}

int u_shortest_path(undirected *g, int source, int dist)
{
    int *distance = malloc((size_t)g->nVertices * sizeof(int));
    assert(distance);
    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        distance[i] = INFINITE; // init all distances as infinity
        visited[i] = false;    // init visited as false
    }

    distance[source] = 0;

    // Dijkstra Loop
    for (int i = 0; i < g->nVertices - 1; i++)
    {
        int current = _minDistance(distance, visited, g->nVertices);
        if (current == dist)
        {
            break;
        }

        visited[current] = true;

        // loop over all edges of the current vertex
        for (int j = 0; j < g->vertices[current].edgeCount; j++)
        {
            int neighbor = g->vertices[current].edges[j].val;
            int neighbor_weight = g->vertices[current].edges[j].weight;

            // add the new distance if the neighbor isn't visited and if the current distance isn't infinity and if the new distance is less than the current distance
            if (!visited[neighbor] && distance[current] != INFINITE &&
                distance[current] + neighbor_weight < distance[neighbor])
            {
                distance[neighbor] = distance[current] + neighbor_weight;
            }
        }
    }
    int result = distance[dist];
    free(distance);
    free(visited);
    return (result == INFINITE) ? -1 : result;
}

int _minDistance(int *distance, bool *visited, int nVertices)
{
    int min = INFINITE, min_index;

    for (int v = 0; v < nVertices; v++)
    {
        if (!visited[v] && distance[v] <= min)
        {
            min = distance[v];
            min_index = v;
        }
    }

    return min_index;
}

directed *init_d_graph(int v)
{
    directed *graph = (directed *)malloc(1 * sizeof(directed));
    assert(graph);
    // initialize number of v
    graph->nVertices = v;
    graph->nEdges = 0;
    // initialize adjacency list
    graph->vertices = malloc((size_t)v * sizeof(vertex));
    // initialize each vertex
    for (int i = 0; i < v; i++)
    {
        graph->vertices[i].edgeCount = 0;
        graph->vertices[i].edgeCapacity = 0;
        graph->vertices[i].edges = NULL;
    }

    return graph;
}

void free_directed_graph(directed *g)
{
    for (int i = 0; i < g->nVertices; i++)
    {
        free(g->vertices[i].edges);
    }
    free(g->vertices);
    free(g);
}

void add_d_edge(directed *g, int source, int dist, int weight)
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
        g->vertices[source].edges = realloc(g->vertices[source].edges, (size_t)g->vertices[source].edgeCapacity * (sizeof(edge)));
        assert(g->vertices[source].edges);
    }
    g->vertices[source].edges[g->vertices[source].edgeCount].val = dist;
    g->vertices[source].edges[g->vertices[source].edgeCount].weight = weight;
    g->vertices[source].edgeCount++;

    g->nEdges++;
}

void d_dfs(directed *g, int v)
{
    Stack *stack = createStack();
    assert(stack);

    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

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

void d_bfs(directed *g, int v)
{
    queue *q = initQueue();
    assert(q);

    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        visited[i] = false; // init visited
    }

    enqueue(v, q);

    while (!Q_isEmpty(q))
    {
        int cur = dequeue(q);

        if (!visited[cur])
        {
            printf("%d -> ", cur);
            visited[cur] = true;

            for (int i = g->vertices[cur].edgeCount - 1; i >= 0; i--)
            {
                int neighbor = g->vertices[cur].edges[i].val;
                if (!visited[neighbor])
                {
                    enqueue(neighbor, q);
                }
            }
        }
    }

    printf("End\n");
    freeQueue(q);
    free(visited);
}

int d_shortest_path(directed *g, int source, int dist)
{
    int *distance = malloc((size_t)g->nVertices * sizeof(int));
    assert(distance);
    bool *visited = malloc((size_t)g->nVertices * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < g->nVertices; i++)
    {
        distance[i] = INFINITE; // init all distances as infinity
        visited[i] = false;    // init visited as false
    }

    distance[source] = 0;

    // Dijkstra Loop
    for (int i = 0; i < g->nVertices - 1; i++)
    {
        int current = _minDistance(distance, visited, g->nVertices);
        if (current == dist)
        {
            break;
        }

        visited[current] = true;

        // loop over all edges of the current vertex
        for (int j = 0; j < g->vertices[current].edgeCount; j++)
        {
            int neighbor = g->vertices[current].edges[j].val;
            int neighbor_weight = g->vertices[current].edges[j].weight;

            // add the new distance if the neighbor isn't visited and if the current distance isn't infinity and if the new distance is less than the current distance
            if (!visited[neighbor] && distance[current] != INFINITE &&
                distance[current] + neighbor_weight < distance[neighbor])
            {
                distance[neighbor] = distance[current] + neighbor_weight;
            }
        }
    }
    int result = distance[dist];
    free(distance);
    free(visited);
    return (result == INFINITE) ? -1 : result;
}

int *d_top_sort(directed *g)
{
    int N = g->nVertices;
    bool *visited = malloc((size_t)N * sizeof(bool));
    assert(visited); // we init a boolean array to determine visited nodes

    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }

    int *ans = malloc((size_t)N * sizeof(int));
    assert(ans);
    int index = N - 1;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            index = d_top_sort_dfs(g, visited, ans, index, i);
        }
    }
    free(visited);
    return ans;
}

int d_top_sort_dfs(directed *g, bool *visited, int *ans, int ans_index, int cur)
{
    visited[cur] = true;
    edge *edges = g->vertices[cur].edges;
    for (int i = 0; i < g->vertices[cur].edgeCount; i++)
    {
        if (!visited[edges[i].val])
        {
            ans_index = d_top_sort_dfs(g, visited, ans, ans_index, edges[i].val);
        }
    }
    ans[ans_index] = cur;
    return ans_index - 1;
}

void prim_MST(undirected *g)
{
    int n = g->nVertices;
    int *parent = malloc((size_t)n * sizeof(int));
    assert(parent);

    int *value = malloc((size_t)n * sizeof(int));
    assert(value);

    bool *inMST = malloc((size_t)n * sizeof(bool));
    assert(inMST); // we init a boolean array to determine visited nodes

    for (int i = 0; i < n; i++)
    {
        value[i] = INT_MAX;
        parent[i] = -1;
        inMST[i] = false;
    }

    min_heap *q = init_min_heap(n);
    element start;
    start.value = 0;
    start.index = 0;
    parent[0] = 0;
    value[0] = 0;
    heap_insert(q, start.value, start.index);

    while (!is_heap_empty(q))
    {
        element u = heap_pop(q);

        if (inMST[u.index])
        {
            continue;
        }

        inMST[u.index] = true;

        for (int i = 0; i < g->vertices[u.index].edgeCount; i++)
        {
            element v;
            v.value = g->vertices[u.index].edges[i].weight;
            v.index = g->vertices[u.index].edges[i].val;

            if (!inMST[v.index] && value[v.index] > v.value)
            {
                value[v.index] = v.value;
                heap_insert(q, v.value, v.index);
                parent[v.index] = u.index;
            }
        }
    }
    // Calculate and print the MST and its total cost
    int total_cost = 0;
    printf("Edge   Weight\n");
    for (int i = 0; i < n; i++) // Start from 1 since parent[0] is -1
    {
        if (parent[i] != -1)
        {
            // Print edge and weight
            int weight = value[i];
            printf("%d - %d   %d\n", parent[i], i, weight);
            total_cost += weight;
        }
    }
    printf("Total cost of MST: %d\n", total_cost);

    // Free dynamically allocated memory
    free(parent);
    free(value);
    free(inMST);
    free_min_heap(q); // Free the heap
}

bool isCyclic(){

}