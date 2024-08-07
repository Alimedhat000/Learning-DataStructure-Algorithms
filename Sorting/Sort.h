#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#if !defined(SORT_PROJECT)
#define SORT_PROJECT

/**
 * @param n size of array
 * @param arr the array to be sorted
 * @param out the output array (parent array)
 */
void merge_sort(int n, int *arr, int *out);
/**
 * @param n1 size of left array
 * @param l the left array
 * @param n2 size of right array
 * @param r the right array
 * @param out the output array
 */
void merge(int n1, int *l, int n2, int *r, int *out);

#endif // SORT_PROJECT
