#if !defined(DoubleLinkedList)
#define DoubleLinkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *pPrev;
    struct list *pNext;
} node;
node *pHead;
node *pLast;
int size = 0;

node *createNode(int);
int insertNode(int, int);
void addHeadNode(int);
void addLastNode(int);
void printList();
int deleteNode(int);
void reverseList();
void swapNode(int, int);
node *findNode(int);

#endif // DoubleLinkedList
