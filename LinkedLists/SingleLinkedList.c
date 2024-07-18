#include "SingleLinkedList.h"

node *createNode(int data)
{
    node *pNode = (node *)malloc(sizeof(node));

    if (pNode != NULL)
    {
        pNode->data = data;
        pNode->pNext = NULL;
        size++;
        // printf("node is created\n");
    }
    return pNode;
}

void pushFront(int data)
{
    node *pNode = createNode(data);
    if (pHead == NULL)
    {
        pHead = pTail = pNode;
        return;
    }
    else
    {
        pNode->pNext = pHead;
        pHead = pNode;
    }
}
void pushBack(int data)
{
    node *pNode = createNode(data);
    if (pHead == NULL)
    {
        pHead = pTail = pNode;
        return;
    }
    else
    {
        pTail->pNext = pNode;
        pTail = pNode;
    }
}

void eraseNode(int index)
{
    if (pHead == NULL)
    {
        return;
    }
    // if index is the head just mive the pointer to pNext
    if (index == 0)
    {
        pHead = pHead->pNext;

        // if the list had only one item update pTail also
        if (pHead == NULL)
        {
            pTail = pHead;
            size--;
        }
        return;
    }

    node *pCurrent = pHead;
    node *pPrev = NULL;
    for (int current = 0; current < index && pCurrent != NULL; current++)
    {
        pPrev = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    if (pCurrent == NULL)
    {
        return;
    }

    pPrev->pNext = pCurrent->pNext;
    if (pCurrent == pTail)
    {
        pTail = pPrev;
    }
    size--;
}
void popFront()
{
    printf("FrontPop : %d\n", pHead->data);
    eraseNode(0);
}
void popBack()
{
    printf("BackPop : %d\n", pTail->data);
    eraseNode(size - 2);
}

void valueAt(int index)
{
    node *pCurrent = pHead;
    for (int i = 0; i < index && pCurrent != NULL; i++)
    {
        pCurrent = pCurrent->pNext;
    }
    printf("Value At index %d = %d\n", index, pCurrent->data);
}
void valueFromEnd(int index)
{
    node *pCurrent = pHead;
    for (int i = 0; i < size - index && pCurrent != NULL; i++)
    {
        pCurrent = pCurrent->pNext;
    }
    printf("Value At index %d from the back = %d\n", index, pCurrent->data);
}
void frontValue()
{
    printf("Value At Front = %d\n", pHead->data);
}
void backValue()
{
    printf("Value At Back = %d\n", pTail->data);
}

void insertNode(int data, int index)
{
    if (index == 0)
    {
        pushFront(data);
        return;
    }
    else
    {
        node *pCurrent = pHead;
        node *pPrev = NULL;
        for (int current = 0; current < index && pCurrent != NULL; current++)
        {
            pPrev = pCurrent;
            pCurrent = pCurrent->pNext;
            if (pCurrent == NULL)
            {
                pushback(data);
                return;
            }
        }
        node *pNode = createNode(data);
        pPrev->pNext = pNode;
        pNode->pNext = pCurrent;
        return;
    }
}

void reverseList()
{
    node *pFirst = pHead;
    node *pSecond = pFirst->pNext;
    node *pTemp = pFirst;
    for (int i = 0; pFirst != NULL; i++)
    {
        if (i == 0)
        {
            pFirst->pNext = NULL;
        }
        else
        {
            pFirst->pNext = pTemp;
        }
        pTemp = pFirst;
        pFirst = pSecond;

        if (pFirst != NULL)
        {
            pSecond = pFirst->pNext;
        }
    }
    pTemp = pHead;
    pHead = pTail;
    pTail = pTemp;
}

void printList()
{
    node *pCur = pHead;
    for (int i = 0; i < size; i++)
    {
        printf("node No. %d data is = %d\n", i, pCur->data);
        pCur = pCur->pNext;
    }
    printf("#############################\n");
}

int main()
{
    pushback(2);

    pushback(4);
    pushFront(1);
    printf("size = %d \n", size);
    insertNode(3, 2);
    printList();
    valueFromEnd(3);
    popFront();
    reverseList();
    printList();
    return 0;
}