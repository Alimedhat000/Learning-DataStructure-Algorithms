#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h> // for mem_cmp
#include <time.h>
#include "MergeSort.c"

void test1();
void test2();

int main()
{
    test1();
    test2();
}

void test1()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int out[10] = {};
    int ans[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    clock_t begin = clock();

    merge_sort(10, arr, out);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d", out[i]);
    // }
    // printf("\n");

    assert(memcmp(ans, out, sizeof(out)) == 0);
    printf("Passed Test 1 in %f\n", time_spent);
}
void test2()
{
    int arr[100] = {43, 73, 87, 81, 57, 94, 26, 32, 56, 38, 54, 93, 27, 75, 14, 11, 63, 62, 64, 60, 6, 88, 1, 25, 76, 40, 3, 36, 28, 9, 78, 29, 51, 96, 86, 23, 68, 10, 30, 92, 69, 79, 74, 49, 39, 33, 61, 5, 34, 65, 15, 16, 77, 85, 35, 55, 98, 53, 59, 71, 13, 84, 17, 80, 37, 90, 91, 24, 99, 19, 0, 95, 12, 21, 52, 47, 2, 41, 4, 89, 45, 67, 50, 18, 58, 82, 8, 97, 70, 46, 7, 20, 22, 42, 66, 83, 44, 48, 31, 72};

    int out[100] = {};

    int ans[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};

    clock_t begin = clock();

    merge_sort(100, arr, out);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    assert(memcmp(ans, out, sizeof(out)) == 0);
    printf("Passed Test 2 in %f\n", time_spent);
}
