#if !defined(Queue)
#define Queue

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
    int data;
    struct List *pNext;

} qnode;
typedef struct Queue
{
    qnode *pHead;
    qnode *pLast;
} queue;

queue *initQueue();
void enqueue(int, queue *);
qnode *Q_createNode(int);
int dequeue(queue *);
void printQueue(queue *);
bool Q_isEmpty(queue *q);
void freeQueue(queue *q);

#endif // Queue
