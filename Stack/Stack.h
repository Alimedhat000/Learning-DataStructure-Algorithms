#if !defined(STACK_HEADERFILE)
#define STACK_HEADERFILE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *pNext;
} node;

typedef struct Stack
{
    node *pTop;
} Stack;

// creates a new stack
Stack *createStack();
// creates a new node
node *createNode(int);
// addes to top
void push(int, Stack *);
// removes from top
int pop(Stack *);
// prints the whole stack
void printStack(Stack *);
// an insertion sort like function where you sort in temp in reverse order first
void sortStack(Stack *);
// a function that returns the first element value without poping
int peekStack(Stack *);

#endif // STACK_HEADERFILE
