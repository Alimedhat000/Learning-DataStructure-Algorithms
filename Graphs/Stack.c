#include "Stack.h"

Stack *createStack()
{
    Stack *newStack = malloc(sizeof(Stack));
    if (newStack != NULL)
    {
        newStack->pTop = NULL;

        return newStack;
    }
    return NULL;
}

node *createNode(int data)
{
    node *pNode = (node *)malloc(sizeof(node));

    if (pNode != NULL)
    {
        pNode->data = data;
        pNode->pNext = NULL;
    }
    return pNode;
}

void push(int data, Stack *S)
{
    node *pNode = createNode(data);
    if (pNode == NULL)
    {
        return;
    }
    pNode->pNext = S->pTop;
    S->pTop = pNode;
}

int pop(Stack *S)
{
    if (S->pTop == NULL)
    {
        return -128;
    }

    int data = S->pTop->data;
    node *ptemp = S->pTop;
    S->pTop = S->pTop->pNext;
    free(ptemp);

    return data;
}

void printStack(Stack *S)
{
    node *pCur = S->pTop;
    for (int i = 0; pCur != NULL; i++)
    {
        printf("node No. %d data is = %d\n", i, pCur->data);
        pCur = pCur->pNext;
    }
    printf("#############################\n");
}

int peekStack(Stack *S)
{
    int temp = pop(S);
    push(temp, S);
    return temp;
}

bool isEmpty(Stack *S)
{
    return S->pTop == NULL;
}

void freeStack(Stack *S)
{
    while (!isEmpty(S))
    {
        pop(S);
    }
    free(S);
}

void sortStack(Stack *S)
{
    Stack *temp = createStack();
    while (!isEmpty(S))
    {
        int value = pop(S); // a pivot to compare values

        while (value < peekStack(temp) && !isEmpty(temp))
        {
            push(pop(temp), S);
        }

        push(value, temp);
    }
    while (!isEmpty(temp))
    {
        push(pop(temp), S);
    }
    if (peekStack(S) == -128)
    {
        pop(S);
    }
}