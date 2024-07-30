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
//* returns the size of the heap
int get_size(max_heap *heap);
//* checks if heap is empty
bool is_empty(max_heap *heap);
//* inserts values while maintaining the max heap property
void insert(max_heap *Q, int value);
//* reorders values Up the tree to satisfy the max heap property
void heapify_up(max_heap *Q, int i);
//* print heap for debuging
void print_heap(max_heap *heap);
//* gets the max value in heap without removing it
int get_max(max_heap *heap);
//* pops the max value and returns it
int extract_max(max_heap *heap);
//* reorders values Down the tree to satisfy the max heap property
void heapify_down(max_heap *heap, int parent);
//* remove node at specified index and rearranges to maintain max heap property
void remove_node(max_heap *heap, int i);
//* heapsort algorithm
void heapsort(int *arr, int size);
//* turn an array into a heap that satisfies max heap proberty
void heapify_array(int *arr, int size);
//* just like heapify_down but for arrays
void heapify_array_down(int *arr, int size, int index);

#endif // MAX_HEAP_PROJECT
