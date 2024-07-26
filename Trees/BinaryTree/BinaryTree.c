#include "BinaryTree.h"

int main()
{
    treeNode *tree = createNode(5);
    insert(tree, 3);
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 4);
    insert(tree, 7);
    insert(tree, 6);
    insert(tree, 8);
    printTree(tree);
    printf("\n%d\n", getSuccessor(tree, 8));
    // if (isSubtreeLesser(tree->pRight, tree->data))
    // {
    //     printf("Found it Yay!!\n");
    // }
    // else
    // {
    //     printf("Not found\n");
    // }

    return 0;
}

treeNode *createNode(int data)
{
    treeNode *pNode = (treeNode *)malloc(sizeof(treeNode));
    assert(pNode != NULL);

    pNode->data = data;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;

    return pNode;
}

treeNode *insert(treeNode *node, int data)
{
    if (node == NULL)
    {
        treeNode *new = createNode(data);
        return new;
    }
    if (data < node->data)
    {
        node->pLeft = insert(node->pLeft, data);
    }
    if (data > node->data)
    {
        node->pRight = insert(node->pRight, data);
    }
    return node;
}

void printTree(treeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printTree(node->pLeft);
    printf("%d ", node->data);
    printTree(node->pRight);

    return;
}

int getNodeCount(treeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getNodeCount(node->pLeft) + getNodeCount(node->pRight) + 1;
}

bool searchInTree(treeNode *node, int data)
{
    if (node == NULL)
    {
        return false;
    }
    if (data < node->data && searchInTree(node->pLeft, data))
    {
        return true;
    }
    if (data > node->data && searchInTree(node->pRight, data))
    {
        return true;
    }
    if (data == node->data)
    {
        return true;
    }

    return false;
}

int getHeight(treeNode *node)
{
    if (node == NULL)
    {
        return -1; //
    }
    int leftheight = getHeight(node->pLeft);
    int rightheight = getHeight(node->pRight);

    if (leftheight > rightheight)
    {
        return leftheight + 1;
    }
    return rightheight + 1;
}

int get_min(treeNode *node)
{
    if (node->pLeft == NULL)
    {
        return node->data;
    }
    return get_min(node->pLeft);
}

int get_max(treeNode *node)
{
    if (node->pRight == NULL)
    {
        return node->data;
    }
    return get_max(node->pRight);
}

bool isSubtreeLesser(treeNode *node, int value)
{
    if (node == NULL)
    {
        return true;
    }
    if (node->data < value && isSubtreeLesser(node->pLeft, value) && isSubtreeLesser(node->pRight, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSubtreeGreater(treeNode *node, int value)
{
    if (node == NULL)
    {
        return true;
    }
    if (node->data > value &&
        isSubtreeGreater(node->pLeft, value) &&
        isSubtreeGreater(node->pRight, value))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidBST(treeNode *node)
{
    if (node == NULL)
    {
        return true;
    }
    if (isSubtreeLesser(node->pLeft, node->data) &&
        isSubtreeGreater(node->pRight, node->data) &&
        isValidBST(node->pLeft) &&
        isValidBST(node->pRight))
    {
        return true;
    }
    else
    {
        return false;
    }
}

treeNode *deleteValue(treeNode *node, int value)
{
    if (node == NULL)
        return node;

    if (value < node->data)
    {
        node->pLeft = deleteValue(node->pLeft, value);
    }
    else if (value > node->data)
    {
        node->pRight = deleteValue(node->pRight, value);
    }

    // Node is found !!

    if (node->pLeft == NULL && node->pRight == NULL) // Zero Child
    {
        node = NULL;
        free(node);
    }
    else if (node->pRight == NULL) // Only left Child
    {
        treeNode *temp = node;
        node = node->pLeft;
        free(temp);
    }
    else if (node->pLeft == NULL) // Only right Child
    {
        treeNode *temp = node;
        node = node->pRight;
        free(temp);
    }
    else // two childs
    {
        node->data = get_min(node->pRight);
        node->pRight = deleteValue(node->pRight, get_min(node->pRight));
    }
    return node;
}

int getSuccessor(treeNode *node, int value)
{
    if (node == NULL || value == get_max(node))
    {
        return -1;
    }
    treeNode *pCur = node;
    treeNode *pSuccessor = node;
    while (pCur->data != value)
    {
        if (value < pCur->data)
        {
            pSuccessor = pCur;
            pCur = pCur->pLeft;
        }
        else if (value > pCur->data)
        {
            pCur = pCur->pRight;
        }
    }
    if (pCur->pRight != NULL)
    {
        return get_min(pCur->pRight);
    }
    else
    {
        return pSuccessor->data;
    }
}