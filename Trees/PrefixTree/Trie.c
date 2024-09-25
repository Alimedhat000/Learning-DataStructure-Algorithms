#include "Trie.h"

TrieNode *CreateNode(char Data){
    TrieNode* NewNode = malloc((size_t)sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        NewNode->children[i] = NULL;
    }
    NewNode->isLeaf = false;
    NewNode->data = Data;
    return NewNode;
}

void DeleteTrieNodes(TrieNode* Node){
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        if (Node->children[i] != NULL)
        {
            DeleteTrieNodes(Node->children[i]);
        }
    }
    free(Node);
}

//for now our words will only have lowercase chars
TrieNode* insert_Trie(TrieNode*Root, char* Word){
    TrieNode * tempNode = Root;

    for (int i = 0; Word[i] != '\0' ; i++)
    {
        int index = Word[i] - 'a';
        //We have Two possibilities either the current level has this char or not
        if (tempNode->children[index] == NULL)
        {
            tempNode->children[index] = CreateNode(Word[i]);
        }
        // Move Down a level to continue insertion
        tempNode = tempNode->children[index];
    }
    tempNode->isLeaf = true;
    return Root;
}

//Basic Search in Trie
bool search_Trie(TrieNode*Root,char*Word){
        TrieNode * tempNode = Root;

    for (int i = 0; Word[i] != '\0' ; i++)
    {
        int index = Word[i] - 'a';
        //We have Two possibilities either the current level has this char or not
        if (tempNode->children[index] == NULL)
        {
            return false;
        }
        // Move Down a level to continue insertion
        tempNode = tempNode->children[index];
    }
    if (tempNode && tempNode->isLeaf == true){
        return true;
    }
    return false;
}

void print_Trie(TrieNode* Root){
    if (!Root){
        return;
    }
    TrieNode*tempNode = Root;
    printf("%c", tempNode->data);
    if (tempNode->isLeaf){
        printf("(end)");
    }
    printf(" -> ");
    for (int i = 0; i < ALPHABET_LENGTH; i++)
    {
        print_Trie(tempNode->children[i]);
    }
    
}

void print_search(TrieNode* root, char* word) {
    printf("Searching for %s: ", word);
    if (search_Trie(root, word) == 0)
        printf("Not Found\n");
    else
        printf("Found!\n");
}