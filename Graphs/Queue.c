#include "Queue.h"
queue *initQueue()
{
    queue *q = malloc(sizeof(qnode));
    if (q != NULL)
    {
        q->pHead = q->pLast = NULL;

        return q;
    }
    return NULL;
}
qnode *Q_createNode(int data)
{
    qnode *newNode = (qnode *)malloc(sizeof(qnode *));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->pNext = NULL;
        return newNode;
    }
    printf("Memmory Allocation Failed!\n");
    return NULL;
}
void enqueue(int data, queue *q)
{
    qnode *newNode = Q_createNode(data);
    if (newNode != NULL)
    {
        if (q->pHead == NULL)
        {
            q->pHead = q->pLast = newNode;
            return;
        }
        q->pLast->pNext = newNode;
        q->pLast = newNode;
        return;
    }
}
int dequeue(queue *q)
{
    if (q->pHead == NULL)
    {
        printf("can't dequeue, the Queue is empty");
        return -1;
    }
    int data = q->pHead->data;
    qnode *temp = q->pHead;
    q->pHead = q->pHead->pNext;
    free(temp);
    if (q->pHead == NULL)
    {
        q->pLast = NULL;
    }
    return data;
}
bool Q_isEmpty(queue *q)
{
    return q->pHead == NULL;
}
void printQueue(queue *q)
{
    printf("Queue contents: ");

    qnode *current = q->pHead;

    while (current)
    {
        printf("%d < ", current->data);
        current = current->pNext;
    }

    printf("\n");
}
void freeQueue(queue *q)
{
    while (!Q_isEmpty(q))
    {
        dequeue(q);
    }
    free(q);
}