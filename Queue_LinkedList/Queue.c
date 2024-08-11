#include "Queue.h"

// int main()
// {
//     queue *test = initQueue();
//     enqueue(1, test);
//     enqueue(2, test);
//     enqueue(3, test);
//     enqueue(4, test);
//     enqueue(5, test);
//     enqueue(6, test);
//     enqueue(7, test);
//     printQueue(test);
//     dequeue(test);
//     dequeue(test);
//     dequeue(test);
//     dequeue(test);
//     dequeue(test);
//     dequeue(test);
//     dequeue(test);
//     printQueue(test);
//     return 0;
// }

queue *initQueue()
{
    queue *q = malloc(sizeof(node));
    if (q != NULL)
    {
        q->pHead = q->pLast = NULL;

        return q;
    }
    return NULL;
}

node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node *));

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
    node *newNode = createNode(data);
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
    node *temp = q->pHead;
    q->pHead = q->pHead->pNext;
    free(temp);
    if (q->pHead == NULL)
    {
        q->pLast = NULL;
        printf("The Queue is now empty and ");
    }
    printf("The dequeued data = %d\n", data);
    return data;
}

void printQueue(queue *q)
{
    printf("Queue contents: ");

    node *current = q->pHead;

    while (current)
    {
        printf("%d < ", current->data);
        current = current->pNext;
    }

    printf("\n");
}
