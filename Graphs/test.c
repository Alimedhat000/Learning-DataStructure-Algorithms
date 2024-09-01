#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "AdjList.h"
#include "AdjMatrix.h"

void test1();
void test_top_order();
void test_top_order_simple();
void test_MST();
void testCyclic();
void testFindSCCs();

int main()
{
    // test_top_order();
    // test_top_order_simple();
    // test_MST();
    // testCyclic();
    testFindSCCs();
    return 0;
}
void test1()
{
    M_undirected *M_g = M_init_graph(10);
    undirected *g = init_u_graph(10);
    add_u_edge(g, 0, 1, 2);
    add_u_edge(g, 0, 4, 1);
    add_u_edge(g, 1, 2, 3);
    add_u_edge(g, 1, 3, 4);
    add_u_edge(g, 2, 3, 1);
    add_u_edge(g, 3, 4, 5);
    M_add_edge(M_g, 0, 1);
    M_add_edge(M_g, 0, 4);
    M_add_edge(M_g, 1, 2);
    M_add_edge(M_g, 1, 3);
    M_add_edge(M_g, 2, 3);
    M_add_edge(M_g, 3, 4);

    u_dfs(g, 0);
    M_dfs(M_g, 0);

    // Test the shortest_path function
    printf("Shortest path from 0 to 3: %d\n", u_shortest_path(g, 0, 3)); // Expected: 6
    printf("Shortest path from 0 to 2: %d\n", u_shortest_path(g, 0, 2)); // Expected: 5
    printf("Shortest path from 1 to 4: %d\n", u_shortest_path(g, 1, 4)); // Expected: 3
}

void test_top_order()
{
    directed *g = init_d_graph(8);
    add_d_edge(g, 0, 2, WEIGHT);
    add_d_edge(g, 0, 3, WEIGHT);
    add_d_edge(g, 1, 3, WEIGHT);
    add_d_edge(g, 1, 4, WEIGHT);
    add_d_edge(g, 2, 5, WEIGHT);
    add_d_edge(g, 3, 5, WEIGHT);
    add_d_edge(g, 4, 6, WEIGHT);
    add_d_edge(g, 5, 7, WEIGHT);
    add_d_edge(g, 6, 7, WEIGHT);

    int *ans = d_top_sort(g);

    for (int i = 0; i < 8; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");
    // Expected Output:
    // 1 4 6 0 3 2 5 7
    // 1 4 0 6 3 2 5 7
    // 0 1 4 6 2 3 5 7

    free(ans);
    free_directed_graph(g);
}

void test_top_order_simple()
{
    directed *g = init_d_graph(6);

    add_d_edge(g, 5, 2, WEIGHT);
    add_d_edge(g, 5, 0, WEIGHT);
    add_d_edge(g, 4, 0, WEIGHT);
    add_d_edge(g, 4, 1, WEIGHT);
    add_d_edge(g, 2, 3, WEIGHT);
    add_d_edge(g, 3, 1, WEIGHT);

    int *ans = d_top_sort(g);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", ans[i]);
    }
    printf("\n");

    // Expected Output:
    //  5, 4, 2, 3, 1, 0
    //  4, 5, 2, 3, 0, 1
    //  5, 2, 3, 4, 0, 1

    free(ans);
    free_directed_graph(g);
}

void test_MST()
{
    // Initialize graph with 8 vertices
    undirected *g1 = init_u_graph(8);

    // Add edges with weights
    add_u_edge(g1, 0, 2, 4);
    add_u_edge(g1, 0, 3, 1);
    add_u_edge(g1, 1, 3, 2);
    add_u_edge(g1, 1, 4, 5);
    add_u_edge(g1, 2, 5, 3);
    add_u_edge(g1, 3, 5, 8);
    add_u_edge(g1, 4, 6, 6);
    add_u_edge(g1, 5, 7, 7);
    add_u_edge(g1, 6, 7, 9);

    // Run Prim's algorithm to find MST
    prim_MST(g1);

    // Edge   Weight
    // 0 - 0   0
    // 3 - 1   2
    // 0 - 2   4
    // 0 - 3   1
    // 1 - 4   5
    // 2 - 5   3
    // 4 - 6   6
    // 5 - 7   7
    // Total cost of MST: 28

    free_undirected_graph(g1);

    // Initialize graph with 5 vertices
    undirected *g2 = init_u_graph(5);

    // Add edges with weights
    add_u_edge(g2, 0, 1, 2);
    add_u_edge(g2, 0, 2, 3);
    add_u_edge(g2, 1, 2, 1);
    add_u_edge(g2, 1, 3, 4);
    add_u_edge(g2, 2, 3, 2);
    add_u_edge(g2, 2, 4, 5);
    add_u_edge(g2, 3, 4, 5);
    add_u_edge(g2, 4, 0, 6);

    // Run Prim's algorithm to find MST
    prim_MST(g2);
    // Total cost of MST: 10

    free_undirected_graph(g2);

    // Initialize graph with 7 vertices
    undirected *g3 = init_u_graph(7);

    // Add edges with weights
    add_u_edge(g3, 0, 1, 1);
    add_u_edge(g3, 0, 2, 2);
    add_u_edge(g3, 1, 2, 3);
    add_u_edge(g3, 1, 3, 4);
    add_u_edge(g3, 2, 3, 5);
    add_u_edge(g3, 2, 4, 6);
    add_u_edge(g3, 3, 4, 7);
    add_u_edge(g3, 3, 5, 8);
    add_u_edge(g3, 4, 5, 9);
    add_u_edge(g3, 5, 6, 10);
    add_u_edge(g3, 6, 0, 11);

    // Run Prim's algorithm to find MST
    prim_MST(g3);
    // Total cost of MST: 31F

    free_undirected_graph(g3);
}

void testCyclic()
{
    // Test Case 1: Simple Acyclic Graph
    directed *g1 = init_d_graph(4);

    add_d_edge(g1, 0, 1, WEIGHT);
    add_d_edge(g1, 1, 2, WEIGHT);
    add_d_edge(g1, 2, 3, WEIGHT);

    assert(isCyclic(g1) == false);
    printf("Test 1 passed! :)\n");

    free_directed_graph(g1);

    // Test Case 2: Simple Cyclic Graph
    directed *g2 = init_d_graph(3);

    add_d_edge(g2, 0, 1, WEIGHT);
    add_d_edge(g2, 1, 2, WEIGHT);
    add_d_edge(g2, 2, 0, WEIGHT);

    assert(isCyclic(g2) == true);
    printf("Test 2 passed! :)\n");

    free_directed_graph(g2);

    // Test Case 3: Disconnected Graph with One Component Having a Cycle
    directed *g3 = init_d_graph(6);

    add_d_edge(g3, 0, 1, WEIGHT);
    add_d_edge(g3, 1, 2, WEIGHT);
    add_d_edge(g3, 3, 4, WEIGHT);
    add_d_edge(g3, 4, 5, WEIGHT);
    add_d_edge(g3, 5, 3, WEIGHT);

    assert(isCyclic(g3) == true);
    printf("Test 3 passed! :)\n");

    free_directed_graph(g3);

    // Test Case 5: Larger Acyclic Graph
    directed *g4 = init_d_graph(8);

    add_d_edge(g4, 0, 1, WEIGHT);
    add_d_edge(g4, 0, 2, WEIGHT);
    add_d_edge(g4, 1, 3, WEIGHT);
    add_d_edge(g4, 1, 4, WEIGHT);
    add_d_edge(g4, 2, 5, WEIGHT);
    add_d_edge(g4, 3, 6, WEIGHT);
    add_d_edge(g4, 4, 7, WEIGHT);

    assert(isCyclic(g4) == false);
    printf("Test 4 passed! :)\n");

    free_directed_graph(g4);

    // Test Case 6: Graph with Multiple Cycles
    directed *g5 = init_d_graph(6);

    add_d_edge(g5, 0, 1, WEIGHT);
    add_d_edge(g5, 1, 2, WEIGHT);
    add_d_edge(g5, 2, 0, WEIGHT); // Cycle 1
    add_d_edge(g5, 3, 4, WEIGHT);
    add_d_edge(g5, 4, 5, WEIGHT);
    add_d_edge(g5, 5, 3, WEIGHT); // Cycle 2

    assert(isCyclic(g5) == true);
    printf("Test 5 passed! :)\n");

    free_directed_graph(g5);

    // Test Case 7: Single Node without Edges
    directed *g6 = init_d_graph(1);

    assert(isCyclic(g6) == false);

    free_directed_graph(g6);
    printf("Test 6 passed! :)\n");

    printf("All tests passed successfully!\n");
}

void testFindSCCs()
{
    // Test Case 1: Single SCC (Simple Cycle)
    directed *g1 = init_d_graph(3);
    add_d_edge(g1, 0, 1, WEIGHT);
    add_d_edge(g1, 1, 2, WEIGHT);
    add_d_edge(g1, 2, 0, WEIGHT);

    int *scc1 = findSCCs(g1);

    assert(scc1[0] == scc1[1] && scc1[1] == scc1[2]); // All nodes should be in the same SCC

    free(scc1);
    free_directed_graph(g1);
    printf("Test 1 passed! :)\n");

    // Test Case 2: Disconnected Graph with One SCC
    directed *g2 = init_d_graph(4);
    add_d_edge(g2, 0, 1, WEIGHT);
    add_d_edge(g2, 1, 2, WEIGHT);
    add_d_edge(g2, 2, 1, WEIGHT);
    add_d_edge(g2, 3, 0, WEIGHT);

    int *scc2 = findSCCs(g2);
    assert(scc2[1] == scc2[2]); // Nodes 1 and 2 should be in the same SCC
    assert(scc2[0] != scc2[1]); // Node 0 should be in a different SCC
    assert(scc2[3] != scc2[0]); // Node 3 should be in its own SCC

    free(scc2);
    free_directed_graph(g2);
    printf("Test 2 passed! :)\n");

    // Test Case 3: Completely Disconnected Nodes
    directed *g3 = init_d_graph(3);

    int *scc3 = findSCCs(g3);
    assert(scc3[0] != scc3[1] && scc3[1] != scc3[2] && scc3[0] != scc3[2]); // Each node is its own SCC

    free(scc3);
    free_directed_graph(g3);
    printf("Test 3 passed! :)\n");

    // Test Case 4: Larger Graph with Multiple SCCs
    directed *g4 = init_d_graph(6);
    add_d_edge(g4, 0, 1, WEIGHT);
    add_d_edge(g4, 1, 2, WEIGHT);
    add_d_edge(g4, 2, 0, WEIGHT); // SCC 1: 0 -> 1 -> 2 -> 0
    add_d_edge(g4, 3, 4, WEIGHT);
    add_d_edge(g4, 4, 5, WEIGHT);
    add_d_edge(g4, 5, 3, WEIGHT); // SCC 2: 3 -> 4 -> 5 -> 3

    int *scc4 = findSCCs(g4);
    assert(scc4[0] == scc4[1] && scc4[1] == scc4[2]); // Nodes 0, 1, 2 are in the same SCC
    assert(scc4[3] == scc4[4] && scc4[4] == scc4[5]); // Nodes 3, 4, 5 are in the same SCC
    assert(scc4[0] != scc4[3]);                       // SCC 1 and SCC 2 are different

    free(scc4);
    free_directed_graph(g4);
    printf("Test 4 passed! :)\n");

    // Test Case 5: Single Node without Edges
    directed *g5 = init_d_graph(1);

    int *scc5 = findSCCs(g5);
    assert(scc5[0] == 0); // Single node is its own SCC

    free(scc5);
    free_directed_graph(g5);
    printf("Test 5 passed! :)\n");

    // Test Case 6:  One big SCC
    directed *g6 = init_d_graph(4);

    add_d_edge(g6, 0, 1, WEIGHT);
    add_d_edge(g6, 1, 2, WEIGHT);
    add_d_edge(g6, 2, 3, WEIGHT);
    add_d_edge(g6, 0, 3, WEIGHT);
    add_d_edge(g6, 2, 0, WEIGHT);

    int *scc6 = findSCCs(g6);
    // The expected SCCs are {0, 1, 2} and {3}
    assert(scc6[0] == scc6[1] && scc6[1] == scc6[2]); // Nodes 0, 1, 2 should be in the same SCC
    assert(scc6[3] != scc6[0]);                       // Node 3 should be in a different SCC

    free(scc6);
    free_directed_graph(g6);
    printf("Test 6 passed! :)\n");

    // Test Case 7: Graph with Back Edges
    directed *g7 = init_d_graph(5);
    add_d_edge(g7, 0, 1, WEIGHT);
    add_d_edge(g7, 1, 2, WEIGHT);
    add_d_edge(g7, 2, 3, WEIGHT);
    add_d_edge(g7, 3, 4, WEIGHT);
    add_d_edge(g7, 4, 1, WEIGHT); // Adding back edge to form a cycle between nodes 1, 2, 3, 4
    add_d_edge(g7, 0, 2, WEIGHT); // Adding an extra edge from 0 to 2

    int *scc7 = findSCCs(g7);
    assert(scc7[1] == scc7[2] && scc7[2] == scc7[3] && scc7[3] == scc7[4]); // Nodes 1, 2, 3, 4 should be in the same SCC
    assert(scc7[0] != scc7[1]);                                             // Node 0 should be in a different SCC

    free(scc7);
    free_directed_graph(g7);
    printf("Test 7 passed! :)\n");

    // Test Case 8: Graph with Multiple Cycles
    directed *g8 = init_d_graph(6);
    add_d_edge(g8, 0, 1, WEIGHT);
    add_d_edge(g8, 1, 2, WEIGHT);
    add_d_edge(g8, 2, 0, WEIGHT); // SCC 1: 0 -> 1 -> 2 -> 0
    add_d_edge(g8, 3, 4, WEIGHT);
    add_d_edge(g8, 4, 5, WEIGHT);
    add_d_edge(g8, 5, 3, WEIGHT); // SCC 2: 3 -> 4 -> 5 -> 3

    int *scc8 = findSCCs(g8);
    assert(scc8[0] == scc8[1] && scc8[1] == scc8[2]); // Nodes 0, 1, 2 should be in the same SCC
    assert(scc8[3] == scc8[4] && scc8[4] == scc8[5]); // Nodes 3, 4, 5 should be in the same SCC

    free(scc8);
    free_directed_graph(g8);
    printf("Test 8 passed! :)\n");

    printf("All tests passed successfully!\n");
}
