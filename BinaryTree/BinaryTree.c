#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *pRight;
    struct node *pLeft;
} node;

typedef struct Tree
{
    node *pRoot;
} Tree;
