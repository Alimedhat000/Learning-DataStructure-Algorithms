#if !defined(Queue)
#define Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int data;
    struct list *pNext;
    struct list *pPrev;
} node;
node *pHead;
node *pLast;

void enqueue(int);
node *createNode(int);
int dequeue();
bool isempty();
void print_debug();

#endif // Queue
