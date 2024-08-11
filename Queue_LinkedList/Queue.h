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
typedef struct Queue
{
    node *pHead;
    node *pLast;
} queue;

queue *initQueue();
void enqueue(int, queue *);
node *createNode(int);
int dequeue(queue *);
void printQueue(queue *);

#endif // Queue
