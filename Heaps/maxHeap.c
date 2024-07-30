#include "maxHeap.h"

int get_size(max_heap *heap)
{
    return heap->size;
}

bool is_empty(max_heap *heap)
{
    return heap->size == 0;
}

void insert(max_heap *heap, int value)
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

void heapify_up(max_heap *heap, int i)
{

    int temp;
    int parent = ((i - 1) / 2);
    if (heap->elements[parent] < heap->elements[i])
    {
        temp = heap->elements[i];
        heap->elements[i] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_up(heap, parent);
    }
}

void print_heap(max_heap *heap)
{
    for (int i = 0; i <= heap->size - 1; ++i)
    {
        printf("%4d |", heap->elements[i]);
    }
    putchar('\n');
}

int get_max(max_heap *heap)
{
    if (heap->size)
    {
        return heap->elements[0];
    }
    return 0;
}

int extract_max(max_heap *heap)
{
    if (heap->size)
    {
        int temp;
        temp = heap->elements[0];
        heap->elements[0] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, 0);
        return temp;
    }
    return 0;
}

void heapify_down(max_heap *heap, int parent)
{
    int temp;
    if (2 * parent >= heap->size - 1)
    {
        return;
    }

    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;
    int swap_index;
    if (left_child <= heap->size - 1 && right_child <= heap->size - 1) // two childs : we have to choose the max to swap
    {
        if (heap->elements[left_child] > heap->elements[right_child])
        {
            swap_index = left_child;
        }
        else
        {
            swap_index = right_child;
        }
    }
    else if (left_child <= heap->size - 1)
    {
        swap_index = left_child;
    }
    else if (right_child <= heap->size - 1)
    {
        swap_index = right_child;
    }
    else
    {
        return;
    }
    if (heap->elements[parent] < heap->elements[swap_index])
    {
        temp = heap->elements[swap_index];
        heap->elements[swap_index] = heap->elements[parent];
        heap->elements[parent] = temp;
        heapify_down(heap, swap_index);
    }
}

void remove_node(max_heap *heap, int i)
{
    if (i <= heap->size - 1)
    {
        int temp;
        temp = heap->elements[i];
        heap->elements[i] = heap->elements[heap->size - 1];
        heap->elements[heap->size - 1] = temp;
        heap->size--;
        heapify_down(heap, i);
    }
}

void heapsort(int *arr, int size)
{
    int temp;
    heapify_array(arr, size);
    for (int i = size - 1; i > 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify_array_down(arr, i, 0);
    }
}

void heapify_array(int *arr, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify_array_down(arr, size, i);
    }
}

void heapify_array_down(int *arr, int size, int index)
{
    int temp;
    if (2 * index >= size - 1)
    {
        return;
    }

    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int swap_index;
    if (left_child <= size - 1 && right_child <= size - 1) // two childs : we have to choose the max to swap
    {
        if (arr[left_child] > arr[right_child])
        {
            swap_index = left_child;
        }
        else
        {
            swap_index = right_child;
        }
    }
    else if (left_child <= size - 1)
    {
        swap_index = left_child;
    }
    else if (right_child <= size - 1)
    {
        swap_index = right_child;
    }
    else
    {
        return;
    }
    if (arr[index] < arr[swap_index])
    {
        temp = arr[swap_index];
        arr[swap_index] = arr[index];
        arr[index] = temp;
        heapify_array_down(arr, size, swap_index);
    }
}