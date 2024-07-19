#if !defined(STACK_HEADERFILE)
#define STACK_HEADERFILE

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *pNext;
} node;

node *pTop = NULL;

node *createNode(int);
void push(int);
int pop();
void printStack();

int size = 0;

#endif // STACK_HEADERFILE
