#if !defined(Queue)
#define Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
    int data;
    struct List *pNext;

} node;
node *pHead;
node *pLast;

void enqueue(int);
node *createNode(int);
int dequeue();
void printQueue();

#endif // Queue
