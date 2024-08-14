#if !defined(ADJACENCY_LIST_PROJECT)
#define ADJACENCY_LIST_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"

#define WIEGHT 1
#define INFINTY 2147483647

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
void add_edge(undirected *g, int source, int dist, int weight);
void dfs(undirected *g, int v);
void bfs(undirected *graph, int v);
void dfs_recursive(undirected *g, int v);
void _traversal(undirected *g, bool *visited, int v);
int shortest_path(undirected *graph, int source, int dist);
int _minDistance(int *distance, bool *visited, int nVertices);
#endif // ADJACENCY_LIST_PROJECT
