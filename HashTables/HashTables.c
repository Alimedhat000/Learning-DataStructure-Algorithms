#include "HashTables.h"

hash_table *createHashtable(int size)
{
    hash_table *freshTable = (hash_table *)malloc(sizeof(hash_table));
    assert(freshTable != NULL);

    freshTable->data = (node *)malloc(size * sizeof(node));
    assert(freshTable->data != NULL);

    freshTable->size = size;

    // make sure all the pointers in array is null
    //  for (int i = 0; i < size; ++i)
    //  {
    //      freshTable->data[i] = NULL;
    //  }

    return freshTable;
}

int hash(char *key, int size)
{
    int hash = 0;
    for (int i = 0; i < key[i] != '\0'; ++i)
    {
        hash = hash * 12 + key[i];
    }
    return abs(hash % size);
}

void add(hash_table *table)
{
    
}