#if !defined(ADJACENCY_LIST_PROJECT)
#define ADJACENCY_LIST_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define WIEGHT 1

typedef struct edge
{
    int val;
    int weight;
} edge;

typedef struct vertex
{
    edge *edges;
    int edgeCount;
    int edgeCapacity;
} vertex;

typedef struct graph
{
    vertex *vertices;
    int nVertices;
    int nEdges;
} undirected;

undirected *init_graph(int v);
void add_edge(undirected *g, int source, int dist);
void dfs(undirected *g, int v);
void bfs(undirected *graph, int v);

#endif // ADJACENCY_LIST_PROJECT
