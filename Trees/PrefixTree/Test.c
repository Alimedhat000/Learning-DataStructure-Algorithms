#include "Trie.h"

int main() {
    // Driver program for the Trie Data Structure Operations
    TrieNode* root = CreateNode('\0');
    root = insert_Trie(root, "hello");
    root = insert_Trie(root, "hi");
    root = insert_Trie(root, "teabag");
    root = insert_Trie(root, "teacan");
    print_search(root, "tea");
    print_search(root, "teabag");
    print_search(root, "teacan");
    print_search(root, "hi");
    print_search(root, "hey");
    print_search(root, "hello");
    print_Trie(root);
    DeleteTrieNodes(root);
    return 0;
}
