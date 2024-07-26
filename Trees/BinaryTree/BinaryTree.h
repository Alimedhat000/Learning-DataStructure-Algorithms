#if !defined(BINARY_TREE_PROJECT)
#define BINARY_TREE_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *pRight;
    struct node *pLeft;
} treeNode;

treeNode *createNode(int data);

treeNode *insert(treeNode *node, int data);

void printTree(treeNode *node);

int getNodeCount(treeNode *node);

bool searchInTree(treeNode *node, int data);

int getHeight(treeNode *node);

int get_min(treeNode *node);

int get_max(treeNode *node);

bool isValidBST(treeNode *node);

bool isSubtreeLesser(treeNode *node, int value);

bool isSubtreeGreater(treeNode *node, int value);

treeNode *deleteValue(treeNode *node, int value);

int getSuccessor(treeNode *node, int value);

#endif // BINARY_TREE_PROJECT
