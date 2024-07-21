#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/*
a implemetation of hashtables in c using an array of pointers to linkedlist
to avoid collisions where you could have the more than one value for each key.
*/

#if !defined(HASH_TABLES_PROJECT)
#define HASH_TABLES_PROJECT

typedef struct node
{
    char *key;
    char *value;
    struct node *pNext;
} node;

typedef struct HashTable
{
    node **data;
    int size;
} hash_table;

// creates a new hash table with 'size' slots
hash_table *createHashtable(int size);
// prints the hashtable for debbuging
void printHashtable(hash_table *table);
//
void add(hash_table *table);

int hash(char *key, int size);
#endif // HASH_TABLES_PROJECT
