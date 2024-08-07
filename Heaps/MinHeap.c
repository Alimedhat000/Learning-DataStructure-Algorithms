#include "MinHeap.h"

int get_size(min_heap *heap)
{
    return heap->size;
}

bool is_empty(min_heap *heap)
{
    return heap->size == 0;
}

int get_min(min_heap *heap)
{
    if (heap->size)
    {
        return heap->elements[0];
    }
    return 0;
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
        if (heap->elements[leftchild] < heap->elements[rightchild])
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
    if (heap->elements[parent] > heap->elements[swap_index])
    {
        int temp = heap->elements[swap_index];
        heap->elements[swap_index] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_down(heap, swap_index);
    }
}

void heapify_up(min_heap *heap, int child)
{
    int parent = ((child - 1) / 2);
    if (heap->elements[parent] > heap->elements[child])
    {
        int temp = heap->elements[child];
        heap->elements[child] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_up(heap, parent);
    }
}

void insert(min_heap *heap, int value)
{
    if (heap->size == 1000)
    {
        printf("Max array size reached! Can't insert more \n");
        return;
    }
    heap->elements[heap->size] = value;
    heap->size++;
    heapify_up(heap, heap->size - 1);
}

void print_heap(min_heap *heap)
{
    for (int i = 0; i <= heap->size - 1; ++i)
    {
        printf("%4d |", heap->elements[i]);
    }
    putchar('\n');
}

void remove_node(min_heap *heap, int index)
{
    if (index < heap->size)
    {
        int temp = heap->elements[index];
        heap->elements[index] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, index);
    }
}

int heap_pop(min_heap *heap)
{
    if (heap->size)
    {

        int temp = heap->elements[0];
        heap->elements[0] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, 0);
        return temp;
    }
    return 0;
}