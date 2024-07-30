#if !defined(MAX_HEAP_PROJECT)
#define MAX_HEAP_PROJECT
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct maxHeap
{
    int elements[1000];
    int size;
} max_heap;

int get_size(max_heap *heap);

bool is_empty(max_heap *heap);

void insert(max_heap *Q, int value);

void heapify_up(max_heap *Q, int i);

void print_heap(max_heap *heap);

int get_max(max_heap *heap);

int extract_max(max_heap *heap);

void heapify_down(max_heap *heap, int parent);

void remove_node(max_heap *heap, int i);

void heapsort(int *arr, int size);

void heapify_array(int *arr, int size);

void heapify_array_down(int *arr, int size, int index);

#endif // MAX_HEAP_PROJECT
