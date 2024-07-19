#if !defined(SingleLinkedList)
#define SingleLinkedList

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct list
{
    int data;
    struct list *pNext;
} node;
node *pHead;
node *pTail;
int size = 0;

#endif // SingleLinkedList
