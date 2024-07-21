#include "Arrays.h"

int main()
{
    int *arr = addArray(8);
    push(8, arr);
    push(5, arr);
    push(2, arr);
    push(4, arr);
    push(3, arr);
    push(5, arr);
    push(9, arr);
    push(4, arr);
    push(5, arr);
    push(5, arr);
    push(7, arr);
    push(4, arr);
    push(5, arr);
    push(5, arr);

    printArray(arr);
    // printSize();
    // printCap();
    // quickSortArray(arr, 0, size - 1);
    // printf("##############################\n");
    // printArray(arr);
    // prepend(pop(arr), arr);

    printf("##############################\n");
    removeAllEqual(5, arr);
    printArray(arr);
    return 0;
}

void push(int data, int *arr)
{
    call = 1;
    resizeArray(arr);
    arr[size] = data;
    size = size + 1;
    return;
}

int *addArray(int cap)
{
    int *arr = (int *)malloc((size_t)cap * (int)sizeof(int)); // size_t is a conversion to remove warning
    capacity = cap;
    return arr;
}

void printArray(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
}

void printCap()
{
    printf("capacity = %d\n", capacity);
}

void printSize()
{
    printf("size = %d\n", size);
}

void insertElement(int data, int index, int *arr)
{
    if (index < 0 || index > size)
    {
        printf("You Entered the Wrong index you DumbAss !!\n");
        return;
    }
    call = 1;
    resizeArray(arr);

    for (int i = size; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = data;
    size = size + 1;
}

void removeElement(int index, int *arr)
{
    if (index < 0 || index >= size)
    {
        printf("You Entered the Wrong index you DumbAss !!\n");
        return;
    }
    call = 0;
    resizeArray(arr);

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size = size - 1;
}

void resizeArray(int *arr)
{
    if (size == capacity && call == 1)
    {
        capacity = capacity * 2;
        int *newarr = addArray(capacity);
        for (int i = 0; i < size - 1; i++)
        {
            newarr[i] = arr[i];
        }
        *arr = *newarr;
        free(arr);

        printf("up reallocation\n");
    }
    if (size < capacity / 4 && call == 0)
    {
        capacity = capacity / 2;
        int *newarr = addArray(capacity);
        for (int i = 0; i < size - 1; i++)
        {
            newarr[i] = arr[i];
        }
        *arr = *newarr;
        free(arr);

        printf("down reallocation\n");
    }
}

void prepend(int data, int *arr)
{
    insertElement(data, 0, arr);
}

int pop(int *arr)
{
    int temp = arr[size - 1];
    removeElement(size - 1, arr);
    return temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = (low - 1);     // Index of the smaller element

    for (int j = low; j < high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSortArray(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // pi is the partitioning index

        // Recursively sort elements before partition and after partition
        quickSortArray(arr, low, pi - 1);
        quickSortArray(arr, pi + 1, high);
    }
}

int findElement(int start, int data, int *arr)
{

    for (int i = start; i < size; i++)
    {
        if (data == arr[i])
        {
            return i;
        }
    }
    return -1;
}

void removeAllEqual(int data, int *arr)
{
    for (int i = 0; i < size; i++)
    {
        if (findElement(i, data, arr) != -1)
        {
            removeElement(findElement(i, data, arr), arr);
        };
    }
}