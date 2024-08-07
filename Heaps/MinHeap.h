#if !defined(MIN_HEAP_PROJECT)
#define MIN_HEAP_PROJECT
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct MinHeap
{
    int elements[1000];
    int size;
} min_heap;
int get_size(min_heap *heap);

bool is_empty(min_heap *heap);

int get_min(min_heap *heap);

void heapify_down(min_heap *heap, int parent);

void heapify_up(min_heap *heap, int child);

void insert(min_heap *heap, int value);

void print_heap(min_heap *heap);

void remove_node(min_heap *heap, int index);

int heap_pop(min_heap *heap);

#endif // MIN_HEAP_PROJECT
