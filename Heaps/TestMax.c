#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for memcp
#include "maxHeap.c"

int main()
{

    max_heap *queue = (max_heap *)calloc(1, sizeof(max_heap));
    queue->size = 0;

    insert(queue, 4);
    assert(get_size(queue) == 1);
    insert(queue, 14);
    assert(get_size(queue) == 2);
    insert(queue, 34);
    assert(get_size(queue) == 3);
    insert(queue, 15);
    insert(queue, 5);
    insert(queue, 12);
    insert(queue, 46);
    insert(queue, 19);
    insert(queue, 17);
    insert(queue, 11);
    insert(queue, 17);
    assert(get_size(queue) == 11);
    printf("Passed 1!\n");

    assert(get_max(queue) == 46);
    printf("Passed 2!\n");

    remove_node(queue, 1); // 19

    assert(get_size(queue) == 10);
    printf("Passed 3!\n");

    assert(extract_max(queue) == 46);
    assert(get_size(queue) == 9);
    assert(extract_max(queue) == 34);
    assert(get_size(queue) == 8);
    assert(extract_max(queue) == 17);
    assert(extract_max(queue) == 17);
    assert(extract_max(queue) == 15);
    assert(extract_max(queue) == 14);
    assert(extract_max(queue) == 12);
    assert(extract_max(queue) == 11);
    assert(extract_max(queue) == 5);
    assert(get_size(queue) == 1);
    assert(extract_max(queue) == 4);
    assert(get_size(queue) == 0);
    printf("Passed 4!\n");

    assert(is_empty(queue));
    printf("Passed 5!\n");

    // Now for sorting

    int to_sort[10] = {10, 123, 43, 17, 13, 9, 422, 2477, 18, 53};
    int sorted[10] = {9, 10, 13, 17, 18, 43, 53, 123, 422, 2477};

    // will do this one with a 0 indexed array, sorted in place

    heapsort(to_sort, 10);

    for (int i = 0; i < 10; ++i)
    {
        printf("%1d ", to_sort[i]);
    }
    printf("\n");

    // compares 2 arrays for exact match
    assert(memcmp(to_sort, sorted, sizeof(to_sort)) == 0);
    printf("Passed sorting!\n");
    printf("Passed All Tests!\n");

    return 0;
}