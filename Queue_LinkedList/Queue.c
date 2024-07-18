#include "Queue.h"

node *createNode(int data)
{
    node *newNode = (node *)calloc(1, sizeof(node *));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->pNext = NULL;
        newNode->pPrev = NULL;
        return newNode;
    }
    printf("Memmory Allocation Failed!\n");
    return NULL;
};

void enqueue(int data)
{
    node *newNode = createNode(data);
    if (pHead == NULL)
    {
        pHead = pLast = newNode;
        return;
    }
    pLast->pNext = newNode;
    pLast = newNode;
    return;
}
int dequeue()
{
    if (isempty())
    {
        printf("can't dequeue, the Queue is empty");
        return;
    }
    node *temp = pHead;
    pHead = pHead->pNext;
    free(temp);
    return temp->data;
}

bool isempty()
{
    return pHead == NULL;
}

void print_debug()
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

void destroy_queue()
{

    node *current = pHead;
    node *temp = current;

    while (current)
    {
        temp = current;
        current = current->pNext;
        free(temp);
    }
}
