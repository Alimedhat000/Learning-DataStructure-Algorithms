#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for memcp
#include "MinHeap.c"

int main()
{

    min_heap *queue = (min_heap *)calloc(1, sizeof(min_heap));
    queue->size = 0;

    insert(queue, 46);
    assert(get_size(queue) == 1);
    insert(queue, 13);
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
    insert(queue, 4);
    assert(get_size(queue) == 11);
    printf("Passed 1!\n");

    assert(get_min(queue) == 4);
    printf("Passed 2!\n");

    assert(heap_pop(queue) == 4);
    assert(get_size(queue) == 10);
    assert(heap_pop(queue) == 5);
    assert(get_size(queue) == 9);
    assert(heap_pop(queue) == 11);
    assert(heap_pop(queue) == 12);
    assert(heap_pop(queue) == 13);
    assert(heap_pop(queue) == 15);
    assert(heap_pop(queue) == 17);
    assert(heap_pop(queue) == 19);
    assert(heap_pop(queue) == 34);
    assert(get_size(queue) == 2);
    assert(heap_pop(queue) == 46);
    assert(get_size(queue) == 1);
    assert(heap_pop(queue) == 46);
    assert(get_size(queue) == 0);
    printf("Passed 3!\n");

    assert(is_empty(queue));
    printf("Passed 4!\n");

    printf("Passed All Tests!\n");

    return 0;
}