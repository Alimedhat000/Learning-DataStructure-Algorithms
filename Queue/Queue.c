#include <stdio.h>

typedef struct linkedList
{
    int data;
    struct list *pNext;
    struct list *pPrev;
} node;
node *pHead;
node *pLast;
