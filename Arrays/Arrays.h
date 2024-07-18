#include <stdio.h>
#include <stdlib.h>

int *addArray(int);
void push(int, int *);
void printArray(int *);
void removeElement(int, int *);
void printSize();
void printCap();
void insertElement(int, int, int *);
void prepend(int, int *);
int pop(int *);
void resizeArray(int *);
void quickSortArray(int *, int, int);
int partition(int *, int, int);
int findElement(int, int, int *);
void removeAllEqual(int, int *);

int size = 0, capacity = 0, call = 1;