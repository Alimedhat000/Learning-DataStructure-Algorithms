#include "DoubleLinkedList.h"

int main()
{

    addHeadNode(6);
    addHeadNode(4);
    addHeadNode(3);
    addHeadNode(2);
    addHeadNode(1);
    addHeadNode(0);
    insertNode(5, 5);

    printList();
    printf("##############################\n");
    deleteNode(6);

    printList();
    return 0;
}

void printList()
{
    node *pCur = pHead;
    for (int i = 0; i < size; i++)
    {
        printf("node No. %d data is = %d\n", i, pCur->data);
        pCur = pCur->pNext;
    }
}

node *createNode(int data)
{
    node *pNode = (node *)malloc(sizeof(node));

    if (pNode != NULL)
    {
        pNode->data = data;
        pNode->pPrev = NULL;
        pNode->pNext = NULL;

        return pNode;
    }
    return 0;
}

int insertNode(int data, int index)
{

    if (index == 0)
    {
        addHeadNode(data);
        return 0;
    }

    node *pCurrent = findNode(index);

    if (pCurrent == NULL)
    {
        addLastNode(data);
        return 0;
    }

    node *pNode = createNode(data);
    size++;

    pCurrent->pPrev->pNext = pNode;
    pNode->pPrev = pCurrent->pPrev;
    pCurrent->pPrev = pNode;
    pNode->pNext = pCurrent;
    return 0;

    return 0;
}

void addHeadNode(int data)
{
    node *pNode = createNode(data);
    size++;
    if (pHead == NULL)
    {
        pHead = pLast = pNode;
    }
    else
    {
        pNode->pNext = pHead;
        pHead->pPrev = pNode;
        pHead = pNode;
    }
}
void addLastNode(int data)
{
    node *pNode = createNode(data);
    size++;
    if (pHead == NULL)
    {
        pHead = pLast = pNode;
    }
    else
    {
        pNode->pPrev = pLast;
        pLast->pNext = pNode;
        pLast = pNode;
    }
}
node *findNode(int index)
{
    node *pCurrent = pHead;
    for (int i = 0; i < index; i++)
    {
        pCurrent = pCurrent->pNext;
    }
    return pCurrent;
}

int deleteNode(int index)
{
    if (index > size || index < 0)
    {
        printf("index out of range\n");
        exit(0);
    }
    if (index == 0)
    {
        pHead = pHead->pNext;
        size--;
        int data = pHead->pPrev->data;
        free(pHead->pPrev);
        return data;
    }
    node *pCurrent = createNode(0);
    pCurrent = pHead;
    for (; index > 0; index--)
    {
        pCurrent = pCurrent->pNext;
    }
    if (pCurrent->pNext == NULL)
    {
        pLast = pLast->pPrev;
        int data = pLast->pNext->data;
        size--;
        return data;
    }
    int data = pCurrent->data;
    pCurrent->pNext->pPrev = pCurrent->pPrev;
    pCurrent->pPrev->pNext = pCurrent->pNext;
    size--;
    free(pCurrent);
    return data;
}

void swapNode(int first, int second)
{
    if (first == second)
    {
        printf("Error!!! you entered the same index\n");
        return;
    }
    node *pFirst = findNode(first), *pSecond = findNode(second);

    if (pFirst == NULL || pSecond == NULL)
    {
        printf("Error!!! One of the elements are out of bounds\n");
        return;
    }

    // local vars to ease readability
    node *pFirstPrev = pFirst->pPrev;
    node *pFirstNext = pFirst->pNext;
    node *pSecondPrev = pSecond->pPrev;
    node *pSecondNext = pSecond->pNext;

    // case: if they're not adjacent
    if (pFirstNext != pSecond && pSecondNext != pFirst)
    {
        // update pointers going into first and second

        if (pFirstPrev != NULL) // if not head
            pFirstPrev->pNext = pSecond;
        if (pFirstNext != NULL) // if not last
            pFirstNext->pPrev = pSecond;
        if (pSecondPrev != NULL) // if not head
            pSecondPrev->pNext = pFirst;
        if (pSecondNext != NULL) // if not last
            pSecondNext->pPrev = pFirst;

        // update pointers going out from first and second
        pFirst->pNext = pSecondNext;
        pFirst->pPrev = pSecondPrev;
        pSecond->pNext = pFirstNext;
        pSecond->pPrev = pFirstPrev;
    }

    else // case: if they're adjacent
    {
        // if pFirst comes first
        if (pFirstNext == pSecond)
        {

            // edit pointers going into the two nodes
            if (pFirstPrev != NULL) // if not head
            {
                pFirstPrev->pNext = pSecond;
            }
            if (pSecondNext != NULL) // if not last
            {
                pSecondNext->pPrev = pFirst;
            }

            // edit pointers going out from the nodes
            pFirst->pNext = pSecond->pNext;
            pSecond->pPrev = pFirst->pPrev;

            // edit pointers in between
            pFirst->pPrev = pSecond;
            pSecond->pNext = pFirst;
        }

        else // if pSecond Comes first
        {
            // edit pointers going into the two nodes
            if (pSecondPrev != NULL) // if not head
            {
                pSecondPrev->pNext = pFirst;
            }
            if (pFirstNext != NULL) // if not last
            {
                pFirstNext->pPrev = pSecond;
            }

            // edit pointers going out from the nodes
            {
                pSecond->pNext = pFirst->pNext;
                pFirst->pPrev = pSecond->pPrev;
            }
            // edit pointers in between
            {
                pSecond->pPrev = pFirst;
                pFirst->pNext = pSecond;
            }
        }
    }

    // if pFirst or Pseconed is the Head or tail
    {
        if (pFirst->pPrev == NULL) // if node
            pHead = pFirst;
        if (pSecond->pPrev == NULL)
            pHead = pSecond;
        if (pFirst->pNext == NULL)
            pLast = pFirst;
        if (pSecond->pNext == NULL)
            pLast = pSecond;
    }
}

void reverseList()
{
    node *pCurrent = pHead, *pTemp = pCurrent;

    for (int i = 0; pCurrent != NULL; i++)
    {
        if (i == 0)
        {
            pCurrent->pPrev = pCurrent->pNext;
            pCurrent->pNext = NULL;
            pCurrent = pCurrent->pPrev;
        }
        else
        {
            pTemp = pCurrent->pPrev;
            pCurrent->pPrev = pCurrent->pNext;
            pCurrent->pNext = pTemp;
            pCurrent = pCurrent->pPrev;
        }
    }
    pTemp = pHead;
    pHead = pLast;
    pLast = pTemp;
}
