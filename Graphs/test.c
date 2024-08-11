#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "AdjList.c"

int main()
{
    undirected *g = init_graph(10);
    add_edge(g, 0, 1, 2);
    add_edge(g, 0, 4, 1);
    add_edge(g, 1, 2, 3);
    add_edge(g, 1, 3, 4);
    add_edge(g, 2, 3, 1);
    add_edge(g, 3, 4, 5);

    // Test the shortest_path function
    printf("Shortest path from 0 to 3: %d\n", shortest_path(g, 0, 3)); // Expected: 6
    printf("Shortest path from 0 to 2: %d\n", shortest_path(g, 0, 2)); // Expected: 5
    printf("Shortest path from 1 to 4: %d\n", shortest_path(g, 1, 4)); // Expected: 3

    return 0;
}
