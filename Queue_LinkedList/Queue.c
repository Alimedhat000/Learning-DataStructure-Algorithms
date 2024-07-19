#include "Queue.h"

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printQueue();
    return 0;
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
};

void enqueue(int data)
{
    node *newNode = createNode(data);
    if (newNode != NULL)
    {
        if (pHead == NULL)
        {
            pHead = pLast = newNode;
            return;
        }
        pLast->pNext = newNode;
        pLast = newNode;
        return;
    }
}
int dequeue()
{
    if (pHead == NULL)
    {
        printf("can't dequeue, the Queue is empty");
        return -1;
    }
    int data = pHead->data;
    node *temp = pHead;
    pHead = pHead->pNext;
    free(temp);
    if (pHead == NULL)
    {
        pLast = NULL;
        printf("The Queue is now empty and ");
    }
    printf("The dequeued data = %d\n", data);
    return data;
}

void printQueue()
{
    printf("Queue contents: ");

    node *current = pHead;

    while (current)
    {
        printf("%d < ", current->data);
        current = current->pNext;
    }

    printf("\n");
}
