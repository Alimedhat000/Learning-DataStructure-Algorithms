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
void test1_MST();
void test2_MST();
void test3_MST();

int main()
{
    // test_top_order();
    // test_top_order_simple();
    test_MST();
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
    test1_MST();
    test2_MST();
    test3_MST();
}
void test1_MST()
{ // Initialize graph with 8 vertices
    undirected *g = init_u_graph(8);

    // Add edges with weights
    add_u_edge(g, 0, 2, 4);
    add_u_edge(g, 0, 3, 1);
    add_u_edge(g, 1, 3, 2);
    add_u_edge(g, 1, 4, 5);
    add_u_edge(g, 2, 5, 3);
    add_u_edge(g, 3, 5, 8);
    add_u_edge(g, 4, 6, 6);
    add_u_edge(g, 5, 7, 7);
    add_u_edge(g, 6, 7, 9);

    // Run Prim's algorithm to find MST
    prim_MST(g);

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

    free_undirected_graph(g);
}
void test2_MST()
{ // Initialize graph with 5 vertices
    undirected *g = init_u_graph(5);

    // Add edges with weights
    add_u_edge(g, 0, 1, 2);
    add_u_edge(g, 0, 2, 3);
    add_u_edge(g, 1, 2, 1);
    add_u_edge(g, 1, 3, 4);
    add_u_edge(g, 2, 3, 2);
    add_u_edge(g, 2, 4, 5);
    add_u_edge(g, 3, 4, 5);
    add_u_edge(g, 4, 0, 6);

    // Run Prim's algorithm to find MST
    prim_MST(g);
    // Total cost of MST: 10

    free_undirected_graph(g);
}

void test3_MST()
{ // Initialize graph with 7 vertices
    undirected *g = init_u_graph(7);

    // Add edges with weights
    add_u_edge(g, 0, 1, 1);
    add_u_edge(g, 0, 2, 2);
    add_u_edge(g, 1, 2, 3);
    add_u_edge(g, 1, 3, 4);
    add_u_edge(g, 2, 3, 5);
    add_u_edge(g, 2, 4, 6);
    add_u_edge(g, 3, 4, 7);
    add_u_edge(g, 3, 5, 8);
    add_u_edge(g, 4, 5, 9);
    add_u_edge(g, 5, 6, 10);
    add_u_edge(g, 6, 0, 11);

    // Run Prim's algorithm to find MST
    prim_MST(g);
    // Total cost of MST: 31

    free_undirected_graph(g);
}