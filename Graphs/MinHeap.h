#if !defined(MIN_HEAP_PROJECT)
#define MIN_HEAP_PROJECT
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct element
{
    int value;
    int index;
} element;

typedef struct MinHeap
{
    element *elements;
    int size;
    int capacity;
} min_heap;

min_heap *init_min_heap(int capacity);

int get_size(min_heap *heap);

bool is_heap_empty(min_heap *heap);

element get_min(min_heap *heap);

void heapify_down(min_heap *heap, int parent);

void heapify_up(min_heap *heap, int child);

void heap_insert(min_heap *heap, int value, int index);

void print_heap(min_heap *heap);

void remove_node(min_heap *heap, int index);

element heap_pop(min_heap *heap);

void free_min_heap(min_heap *heap);

#endif // MIN_HEAP_PROJECT
