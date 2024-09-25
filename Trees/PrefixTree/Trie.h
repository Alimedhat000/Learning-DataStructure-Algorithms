#if !defined(TRIE_PROJECT)
#define TRIE_PROJECT

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define ALPHABET_LENGTH 26

typedef struct node
{
    // The Trie Node Structure
    // Each node has N children, starting from the root
    // and a flag to check if it's a leaf node
    char data;
    struct node *children[ALPHABET_LENGTH];
    bool isLeaf;
} TrieNode;

TrieNode *CreateNode(char Data);
void DeleteTrieNodes(TrieNode* Node);
TrieNode* insert_Trie(TrieNode*Root, char* Word);
bool search_Trie(TrieNode*Root,char*Word);
void print_search(TrieNode* root, char* word) ;
void print_Trie(TrieNode *root);

#endif // TRIE_PROJECT
