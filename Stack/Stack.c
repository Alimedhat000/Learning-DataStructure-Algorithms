#include "Stack.h"

int main()
{
    Stack *S = createStack();

    push(9, S);
    push(7, S);
    push(5, S);
    push(2, S);
    push(2, S);
    push(1, S);
    push(3, S);

    printf("stack before sorting :\n");
    printStack(S);

    printf("stack after sorting :\n");
    sortStack(S);
    printStack(S);
}

Stack *createStack()
{
    Stack *newStack = malloc(sizeof(node));
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
    return;
}

int pop(Stack *S)
{
    if (S->pTop == NULL)
    {
        printf("Stack is empty.\n");
        return -128;
    }

    int data = S->pTop->data;
    node *ptemp = S->pTop;
    S->pTop = S->pTop->pNext;
    free(ptemp);

    if (S->pTop == NULL)
    {
        printf("Poped all elements, the stack is now empty.\n");
    }

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
bool empty(Stack *S)
{
    return S->pTop == NULL;
}

void sortStack(Stack *S)
{
    Stack *temp = createStack();
    while (!empty(S))
    {
        int value = pop(S); // a pivot to compare values

        while (value < peekStack(temp) && !empty(temp))
        {
            push(pop(temp), S);
        }

        push(value, temp);
    }
    while (!empty(temp))
    {
        push(pop(temp), S);
    }
    if (peekStack(S) == -128)
    {
        pop(S);
    }
}