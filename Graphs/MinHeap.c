#include "MinHeap.h"

min_heap *init_min_heap(int size)
{
    min_heap *newheap = malloc((size_t)sizeof(min_heap));
    assert(newheap);

    newheap->elements = malloc((size_t)size * sizeof(element));
    assert(newheap->elements);

    newheap->size = 0;
    newheap->capacity = size;
    return newheap;
}

int get_size(min_heap *heap)
{
    return heap->size;
}

bool is_heap_empty(min_heap *heap)
{
    return heap->size == 0;
}

element get_min(min_heap *heap)
{
    if (heap->size)
    {
        return heap->elements[0];
    }
    return (element){.value = -1, .index = -1};
}

void heapify_down(min_heap *heap, int parent)
{
    if (parent * 2 >= heap->size - 1)
    {
        return;
    }

    int leftchild = parent * 2 + 1;
    int rightchild = parent * 2 + 2;
    int swap_index;
    if (leftchild < heap->size && rightchild < heap->size)
    {
        if (heap->elements[leftchild].value < heap->elements[rightchild].value)
        {
            swap_index = leftchild;
        }
        else
        {
            swap_index = rightchild;
        }
    }
    else if (leftchild < heap->size)
    {
        swap_index = leftchild;
    }
    else if (rightchild < heap->size)
    {
        swap_index = rightchild;
    }
    else
    {
        return;
    }
    if (heap->elements[parent].value > heap->elements[swap_index].value)
    {
        element temp = heap->elements[swap_index];
        heap->elements[swap_index] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_down(heap, swap_index);
    }
}

void heapify_up(min_heap *heap, int child)
{
    int parent = ((child - 1) / 2);
    if (heap->elements[parent].value > heap->elements[child].value)
    {
        element temp = heap->elements[child];
        heap->elements[child] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_up(heap, parent);
    }
}

void heap_insert(min_heap *heap, int value, int index)
{
    if (heap->size == heap->capacity)
    {
        printf("Max array size reached! Can't insert more \n");
        return;
    }
    heap->elements[heap->size].value = value;
    heap->elements[heap->size].index = index;
    heap->size++;
    heapify_up(heap, heap->size - 1);
}

void print_heap(min_heap *heap)
{
    for (int i = 0; i <= heap->size - 1; ++i)
    {
        printf("%4d |", heap->elements[i].value);
    }
    putchar('\n');
}

void remove_node(min_heap *heap, int index)
{
    if (index < heap->size)
    {
        element temp = heap->elements[index];
        heap->elements[index] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, index);
    }
}

element heap_pop(min_heap *heap)
{
    if (heap->size)
    {

        element temp = heap->elements[0];
        heap->elements[0] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, 0);
        return temp;
    }
    return (element){.value = -1, .index = -1};
}

void free_min_heap(min_heap *heap)
{
    if (!heap)
        return;

    free(heap->elements); // Free the array of elements
    free(heap);           // Free the heap structure
}