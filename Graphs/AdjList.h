#if !defined(ADJACENCY_LIST_PROJECT)
#define ADJACENCY_LIST_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"
#include "MinHeap.h"

// Constants for weight and infinity
#define WEIGHT 1
#define INFINITE 2147483647

// Definition of an edge in the graph
typedef struct edge
{
    int val;    // Destination vertex
    int weight; // Weight of the edge
} edge;

// Definition of a vertex in the graph
typedef struct vertex
{
    edge *edges;      // Array of edges (adjacent vertices)
    int edgeCount;    // Number of edges
    int edgeCapacity; // Current capacity of the edge array
} vertex;

// Definition of an undirected graph
typedef struct undirected
{
    vertex *vertices; // Array of vertices
    int nVertices;    // Number of vertices
    int nEdges;       // Number of edges
} undirected;

// Definition of a directed graph
typedef struct directed
{
    vertex *vertices; // Array of vertices
    int nVertices;    // Number of vertices
    int nEdges;       // Number of edges
} directed;

/**
 * Initializes an undirected graph with a given number of vertices.
 *
 * @param v Number of vertices in the graph.
 * @return A pointer to the initialized undirected graph.
 */
undirected *init_u_graph(int v);

/**
 * Adds an edge to an undirected graph.
 *
 * @param g Pointer to the undirected graph.
 * @param source Source vertex of the edge.
 * @param dist Destination vertex of the edge.
 * @param weight Weight of the edge.
 */
void add_u_edge(undirected *g, int source, int dist, int weight);

/**
 * Frees the memory allocated for the undirected graph.
 *
 * @param g Pointer to the undirected graph to be freed.
 */
void free_undirected_graph(undirected *g);

/**
 * Performs a Depth-First Search (DFS) on an undirected graph starting from a given vertex.
 *
 * @param g Pointer to the undirected graph.
 * @param v Starting vertex for the DFS.
 */
void u_dfs(undirected *g, int v);

/**
 * Performs a Breadth-First Search (BFS) on an undirected graph starting from a given vertex.
 *
 * @param g Pointer to the undirected graph.
 * @param v Starting vertex for the BFS.
 */
void u_bfs(undirected *g, int v);

/**
 * Performs a recursive Depth-First Search (DFS) on an undirected graph starting from a given vertex.
 *
 * @param g Pointer to the undirected graph.
 * @param v Starting vertex for the DFS.
 */
void u_dfs_recursive(undirected *g, int v);

/**
 * Helper function for recursive DFS traversal.
 *
 * @param g Pointer to the undirected graph.
 * @param visited Array of visited vertices.
 * @param v Current vertex being visited.
 */
void _u_traversal(undirected *g, bool *visited, int v);

/**
 * Finds the shortest path in an undirected graph using Dijkstra's algorithm.
 *
 * @param g Pointer to the undirected graph.
 * @param source Source vertex for the shortest path search.
 * @param dist Destination vertex for the shortest path search.
 * @return The shortest path distance or -1 if no path exists.
 */
int u_shortest_path(undirected *g, int source, int dist);

/**
 * Helper function to find the vertex with the minimum distance that has not been visited.
 *
 * @param distance Array of distances from the source vertex.
 * @param visited Array of visited vertices.
 * @param nVertices Number of vertices in the graph.
 * @return The index of the vertex with the minimum distance.
 */
int _minDistance(int *distance, bool *visited, int nVertices);

/**
 * Initializes a directed graph with a given number of vertices.
 *
 * @param v Number of vertices in the graph.
 * @return A pointer to the initialized directed graph.
 */
directed *init_d_graph(int v);

/**
 * Frees the memory allocated for the directed graph.
 *
 * @param g Pointer to the directed graph to be freed.
 */
void free_directed_graph(directed *g);

/**
 * Adds an edge to a directed graph.
 *
 * @param g Pointer to the directed graph.
 * @param source Source vertex of the edge.
 * @param dist Destination vertex of the edge.
 * @param weight Weight of the edge.
 */
void add_d_edge(directed *g, int source, int dist, int weight);

/**
 * Performs a Depth-First Search (DFS) on a directed graph starting from a given vertex.
 *
 * @param g Pointer to the directed graph.
 * @param v Starting vertex for the DFS.
 */
void d_dfs(directed *g, int v);

/**
 * Performs a Breadth-First Search (BFS) on a directed graph starting from a given vertex.
 *
 * @param g Pointer to the directed graph.
 * @param v Starting vertex for the BFS.
 */
void d_bfs(directed *g, int v);

/**
 * Finds the shortest path in a directed graph using Dijkstra's algorithm.
 *
 * @details Complexity : O(V^2)
 * Space Complexity: O(V)
 * @param g Pointer to the directed graph.
 * @param source Source vertex for the shortest path search.
 * @param dist Destination vertex for the shortest path search.
 * @return The shortest path distance or -1 if no path exists.
 */
int d_shortest_path(directed *g, int source, int dist);

/**
 * @brief Performs a topological sort on a directed acyclic graph (DAG).
 *
 * @details function takes a directed acyclic graph (DAG) as input and returns
 * an array representing the topological ordering of its vertices.
 * The function uses a depth-first search (DFS) approach to visit each
 * vertex and determine the correct order.
 *
 * Time Complexity : O(V + E)
 * Space Complexity: O(V)
 *
 * @param g A pointer to the directed graph to be sorted.
 * @return A pointer to an integer array containing the topological order.
 *         The caller is responsible for freeing this array after use.
 */
int *d_top_sort(directed *g);

/**
 * @brief Depth-First Search (DFS) helper function for topological sorting.
 *
 * @details This function is a helper for `d_top_sort` that recursively visits
 * vertices in a depth-first manner. It marks each visited vertex,
 * and adds it to the result array in reverse topological order.
 *
 * @param g A pointer to the directed graph.
 * @param visited A boolean array to keep track of visited vertices.
 * @param ans An integer array to store the topological order.
 * @param ans_index The current index in the result array where the vertex should be placed.
 * @param cur The current vertex being visited.
 * @return The updated index for the next vertex to be placed in the result array.
 */
int d_top_sort_dfs(directed *g, bool *visited, int *ans, int ans_index, int cur);

/**
 * @brief Calculates the Minimum Spanning Tree (MST) using Prim's algorithm.
 *
 * @details
 * Complexity : O(E log V)
 * Space Complexity: O(V)
 *
 * @param g Pointer to the undirected graph.
 */
void prim_MST(undirected *g);

/**
 * @brief Detects if there is a cycle in the directed graph.
 *
 * @details function uses a depth-first search (DFS) approach with a stack to detect
 * cycles in a directed graph. It marks vertices as NOT_VISITED, IN_PATH, or FINISHED
 * to keep track of the traversal state.
 *
 * Time Complexity : O(V + E)
 * Space Complexity: O(V)
 *
 * @param g The directed graph to be checked for cycles.
 * @return True if a cycle is detected, false otherwise.
 */
bool isCyclic(directed *g);

/**
 * @brief Finds all the Strongly Connected Components (SCCs) in a directed graph.
 *
 * @details This function implements an iterative version of Tarjan's algorithm to find all
 * Strongly Connected Components (SCCs) in a directed graph. An SCC is a maximal subgraph
 * in which every vertex is reachable from every other vertex within the same SCC.
 *
 * The function uses the following arrays of size `N` (number of vertices):
 * - `labels`: Holds the discovery index of each node. This index is set when the node is first visited.
 * - `lowLinkValues`: Stores the smallest discovery index reachable from the node. This is crucial to determine
 *   if a node is the root of an SCC.
 * - `onStack`: A boolean array to track whether a node is currently on the stack, which helps in correctly identifying SCCs.
 *
 * The algorithm operates as follows:
 * 1. Initialize `labels` to `UNVISITED`, `lowLinkValues` to 0, and `onStack` to `false` for all vertices.
 * 2. For each unvisited node `i`, push it onto the stack, set its `labels[i]` and `lowLinkValues[i]` to the current index,
 *    and start a Depth-First Search (DFS) using an iterative approach.
 * 3. During DFS, explore each unvisited adjacent node (`adj`) by pushing it onto the stack, assigning it a discovery index,
 *    and marking it as being on the stack.
 * 4. As DFS progresses, update the `lowLinkValues` based on the discovery indices of adjacent nodes.
 *    - If an adjacent node `adj` is already on the stack, update the current node's `lowLinkValues` to be the minimum of its current
 *      value and `lowLinkValues[adj]`.
 * 5. After exploring all adjacent nodes, if the current node is found to be the root of an SCC (i.e., `labels[v] == lowLinkValues[v]`),
 *    pop nodes from the stack until the root node is reached, indicating that all these nodes form an SCC.
 * 6. Continue this process until all nodes have been visited.
 *
 * The function ultimately returns an array of `lowLinkValues`, which can be used to identify the SCCs in the graph.
 * Nodes with the same `lowLinkValue` belong to the same SCC.
 *
 *
 * Time Complexity : O(V + E)
 * Space Complexity: O(V)
 *
 * @param g Pointer to the directed graph.
 * @return An array of `lowLinkValues` where each value represents the smallest discovery index reachable from the corresponding vertex.
 */
int *findSCCs(directed *g);

#endif // ADJACENCY_LIST_PROJECT
