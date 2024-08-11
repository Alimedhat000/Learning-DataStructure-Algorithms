#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "AdjList.c"

int main()
{
    undirected *graph = init_graph(10);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 6);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 6, 1);
    add_edge(graph, 1, 6);
    dfs(graph, 1);
    bfs(graph, 3);

    return 0;
}
