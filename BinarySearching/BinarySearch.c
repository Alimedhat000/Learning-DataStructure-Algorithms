#include "BinarySearch.h"

void search(int *arr, int arrSize, int target)
{
    int left = 0;
    int right = arrSize - 1;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (target < mid)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }
    }
    return left;
}