#include "HashTables.h"

int main()
{
    hash_table *table = createHashtable(10);
    add(table, "Ali", "Medhat");
    add(table, "Yousef", "Omar");
    add(table, "Magd", "Maged");
    add(table, "Ali", "Omar");
    add(table, "ilA", "Medhat");
    delete (table, "Yousef");
    delete (table, "ilA");
    printTable(table);
}

hash_table *createHashtable(int size)
{
    hash_table *freshTable = (hash_table *)malloc(sizeof(hash_table));
    assert(freshTable != NULL);

    freshTable->data = (node **)malloc(size * sizeof(node));
    assert(freshTable->data != NULL);

    freshTable->size = size;

    // make sure all the pointers in array is null
    for (int i = 0; i < size; ++i)
    {
        freshTable->data[i] = NULL;
    }

    return freshTable;
}
node *createNode(char *key, char *value)
{
    node *pNode = (node *)malloc(sizeof(node));
    assert(pNode != NULL); // terminate if NULL pointer

    pNode->key = strdup(key);
    pNode->value = strdup(value);
    pNode->pNext = NULL;

    return pNode;
}

int hash(char *key, int size)
{
    int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i)
    {
        hash = hash * 12 + key[i];
    }
    return abs(hash % size);
}

void add(hash_table *table, char *key, char *data)
{
    int index = hash(key, table->size);

    if (table->data[index] == NULL) // if its the first element
    {
        table->data[index] = createNode(key, data);
    }
    else
    {
        node *pCur = find(table, key);
        if (pCur != NULL)
        {
            free(pCur->value);
            pCur->value = strdup(data);
            return;
        }
        node *pnew = createNode(key, data);
        table->data[index]->pNext = pnew;
    }
}

node *find(hash_table *table, char *key)
{
    int index = hash(key, table->size);

    node *temp = table->data[index];

    while (temp != NULL)
    {
        if (strcmp(temp->key, key) == 0)
        {
            return temp;
        }
        temp = temp->pNext;
    }
    return NULL;
}

void printTable(hash_table *table)
{
    printf("Cell[x]=> key:value\n");
    for (int i = 0; i < table->size; i++)
    {
        if (table->data[i] != NULL)
        {
            printf("Cell[%d]=> %s:%s", i, table->data[i]->key, table->data[i]->value);
            node *pCur = table->data[i]->pNext;
            while (pCur != NULL)
            {
                printf(" %s:%s", pCur->key, pCur->value);
                pCur = pCur->pNext;
            }
            printf("\n");
        }
        else
        {
            printf("Cell[%d]=>\n", i);
        }
    }
    printf("===================\n");
}

void delete(hash_table *table, char *key)
{
    int index = hash(key, table->size);

    if (table->data[index] != NULL)
    {
        node *pCur = table->data[index];
        node *pPrev = NULL;

        while (pCur != NULL)
        {
            if (strcmp(key, pCur->key) == 0)
            {
                if (pPrev == NULL)
                {
                    table->data[index] = pCur->pNext;
                    free(pCur);
                    return;
                }
                else
                {
                    pPrev->pNext = pCur->pNext;
                    free(pCur);
                }
            }
            pPrev = pCur;
            pCur = pCur->pNext;
        }
    }
}

void destroy(hash_table *table)
{

    for (int i = 0; i < table->size; i++)
    {
        node *pCur = table->data[i];
        while (pCur != NULL)
        {
            node *next = pCur->pNext;
            free(pCur->key);
            free(pCur->value);
            free(pCur);
            pCur = next;
        }
        free(pCur);
    }
    free(table->data);
    free(table);
}
