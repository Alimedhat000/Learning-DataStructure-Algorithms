#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/*
a implemetation of hashtables in c using an array of pointers to linkedlist(Chaining)
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
/*
add an element to the table at the index = hash(key)
and if collision is faced append to the last element in the chain
*/
void add(hash_table *table, char *key, char *data);
// universal string hashfunction (i didn't invent this haha!)
int hash(char *key, int size);
// find if the key exists in the table
node *find(hash_table *table, char *key);
// print table and all the chains
void printTable(hash_table *table);
// delete the value specified by key
void delete(hash_table *table, char *key);

#endif // HASH_TABLES_PROJECT
