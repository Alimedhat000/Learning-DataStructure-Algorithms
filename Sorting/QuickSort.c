#include "Sort.h"

void partition(int *arr, int size)
{
    if (size < 2)
    {
        return;
    }
    int pivot = arr[rand() % size], left = 0, right = size - 1;

    while (left < right)
    {
        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }

        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    partition(arr, left);
    partition(&arr[left + 1], size - left - 1);
}

void quick_sort(int *arr, int size)
{
    partition(arr, size);
}
