#include "Sort.h"

void merge(int n1, int *l, int n2, int *r, int *out)
{
    int i = 0, j = 0, k = 0;

    while (i < n1 || j < n2)
    {
        if (j >= n2 || (i < n1 && l[i] < r[j])) // checks if r[j] doesn't exist or l[i] exists and is less than r[j]
        {
            out[k++] = l[i++];
        }
        else
        {
            out[k++] = r[j++]; // either l[i] doesn't exist or r[j] is less than l[i]
        }
    }
}

void merge_sort(int n, int *arr, int *out)
{
    if (n < 2)
    {
        // if 1 or 0 elements, just copy it to the out array
        memcpy(out, arr, sizeof(int) * n);
        return;
    }
    else
    {
        int *l;
        int *r;
        int mid = n / 2;
        l = malloc(sizeof(int) * mid);       // the first half of the array has size mid where mid = n/2
        r = malloc(sizeof(int) * (n - mid)); // the second half is the full size - mid, hence n - mid

        merge_sort(mid, arr, l);           // recurse on the first half
        merge_sort(n - mid, arr + mid, r); // recurse on the second half

        merge(mid, l, n - mid, r, out); // merge the two subarrays to their parent array

        free(l); // free temporary arrays
        free(r);
    }
}
