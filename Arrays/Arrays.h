#if !defined(Arrays)
#define Arrays

#include <stdio.h>
#include <stdlib.h>

int *addArray(int);
void push(int, int *);
void printArray(int *);
void removeElement(int, int *);
void printSize();
void printCap();
void insertElement(int, int, int *);
// add alement to the start of the array and move all the elements to the left
void prepend(int, int *);
// delete element from the end of the array and return it
int pop(int *);
// double array size if filled and half it if 3/4 is empty
void resizeArray(int *);
// swap two items
void swap(int *a, int *b);
// quick sort where the pivot is the last element
void quickSortArray(int *, int, int);
// Partition function to place the pivot element in its correct position Essential for quicksort
int partition(int *, int, int);
int findElement(int, int, int *);
void removeAllEqual(int, int *);

int size = 0, capacity = 0, call = 1;

#endif // Arrays
