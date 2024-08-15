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

int main()
{
    test_top_order();
    test_top_order_simple();
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
    add_d_edge(g, 0, 2, WIEGHT);
    add_d_edge(g, 0, 3, WIEGHT);
    add_d_edge(g, 1, 3, WIEGHT);
    add_d_edge(g, 1, 4, WIEGHT);
    add_d_edge(g, 2, 5, WIEGHT);
    add_d_edge(g, 3, 5, WIEGHT);
    add_d_edge(g, 4, 6, WIEGHT);
    add_d_edge(g, 5, 7, WIEGHT);
    add_d_edge(g, 6, 7, WIEGHT);

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
}

void test_top_order_simple()
{
    directed *g = init_d_graph(6);

    add_d_edge(g, 5, 2, WIEGHT);
    add_d_edge(g, 5, 0, WIEGHT);
    add_d_edge(g, 4, 0, WIEGHT);
    add_d_edge(g, 4, 1, WIEGHT);
    add_d_edge(g, 2, 3, WIEGHT);
    add_d_edge(g, 3, 1, WIEGHT);

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
}
