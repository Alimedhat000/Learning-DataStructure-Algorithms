#if !defined(ADJACENCY_MATRIX_PROJECT)
#define ADJACENCY_MATRIX_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct AdjMatrix
{
    int nVertices;
    int **AdjMatrix;
} M_undirected;

M_undirected *M_init_graph(int v);
void M_add_edge(M_undirected *g, int source, int dist);
void M_dfs(M_undirected *g, int v);
void M_bfs(M_undirected *g, int v);

#endif // ADJACENCY_MATRIX_PROJECT
