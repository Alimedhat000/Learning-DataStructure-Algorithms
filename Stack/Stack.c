#include "Stack.h"

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    printStack();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    printStack();
}

node *createNode(int data)
{
    node *pNode = (node *)malloc(sizeof(node));

    if (pNode != NULL)
    {
        pNode->data = data;
        pNode->pNext = NULL;
        size++;
    }
    return pNode;
}

void push(int data)
{
    node *pNode = createNode(data);
    if (pNode == NULL)
    {
        return;
    }
    pNode->pNext = pTop;
    pTop = pNode;
    size++;
    return;
}

int pop()
{
    if (pTop == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    int data = pTop->data;
    node *ptemp = pTop;
    pTop = pTop->pNext;
    free(ptemp);
    size--;

    if (pTop == NULL)
    {
        printf("Poped all elements, the stack is now empty.\n");
    }

    return data;
}

void printStack()
{
    node *pCur = pTop;
    for (int i = 0; i < size; i++)
    {
        printf("node No. %d data is = %d\n", i, pCur->data);
        pCur = pCur->pNext;
    }
    printf("#############################\n");
}
