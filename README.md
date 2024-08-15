# Data Structures and Algorithms Training
This repository is the result of my DSA (Data Structures and Algorithms) training, following the curriculum from [Coding Interview University](https://github.com/jwasham/coding-interview-university). It includes implementations of various data structures and algorithms commonly used in computer science and software engineering.

## Table of Contents
- [Data Structures](#data-structures)
  - [Arrays](#arrays)
  - [Linked Lists](#linked-lists)
  - [Queue](#queue)
  - [Stack](#stack)
  - [HashMaps](#hashmaps)
  - [Trees](#trees)
  - [Heaps](#heaps)
  - [Graphs](#graphs)
- [Algorithms](#algorithms)


## Data Structures

### Arrays
Implementation of a dynamically sized array that changes size based on the number of elements.

<details>
<summary>Click to expand operations</summary>

- `void push(data, arr)`
- `void insertElement(data, index, arr)`
- `void removeElement(index, arr)`
- `void resizeArray(arr)`
- `void prepend(data, arr)`
- `int pop(arr)`
- `void swap(a, b)`
- `void quickSortArray(arr, low, high)`
- `int findElement(start, data, arr)`
- `void removeAllEqual(data, arr)`
</details>

### Linked Lists
Implementation of Single, Double, and Ring linked lists.

<details>
<summary>Click to expand operations</summary>

- `void addHeadNode(data)`
- `void addLastNode(data)`
- `int deleteNode(index)`
- `void reverseList()`
- `void swapNode(a,b)`
- `node *findNode(int)`
- `int insertNode(data, index)`
- `void printList()`
</details>

### Queue
Implementation of a Queue using linked lists.

<details>
<summary>Click to expand operations</summary>

- `void enqueue(data)`
- `int dequeue()`
- `int printqueue(index)`
</details>

### Stack
Implementation of a Stack using linked lists.

<details>
<summary>Click to expand operations</summary>

- `void push(data)`
- `int pop()`
- `int printstack()`
- `void sortstack()`
- `int peekstack()`
</details>

### HashMaps
Implementation of a Hashmap with chaining (an array of linked lists) to avoid collisions.

<details>
<summary>Click to expand operations</summary>

- `hash_table *createHashtable(int size)`
- `void add(table, key, data)`
- `int hash(key, size)`
- `node *find(table, key)`
- `void printTable(table)`
- `void delete(table, key)`
- `void destroy(table)`
</details>

### Trees
Implementation of a Binary Search Tree.

<details>
<summary>Click to expand operations</summary>

- `treeNode *insert(treeNode *node, int data)`
- `int getNodeCount(treeNode *node)`
- `bool searchInTree(treeNode *node, int data)`
- `int getHeight(treeNode *node)`
- `bool isValidBST(treeNode *node)`
- `treeNode *deleteValue(treeNode *node, int value)`
- `int getSuccessor(treeNode *node, int value)`

</details>

### Heaps
Implementation of a max heap and a min heap (priority queue) using a static array.

<details>

<summary>Click to expand operations</summary>

- `void insert(max_heap *Q, int value)`
- `void heapify_up(max_heap *Q, int i)`
- `int get_max(max_heap *heap)`
- `int get_min(min_heap *heap)`
- `int extract_max(max_heap *heap)`
- `void heapify_down(max_heap *heap, int parent)`
- `void remove_node(max_heap *heap, int i)`
- `void heapsort(int *arr, int size)`

</details>

### Graphs
Implementation of both directed and undirected graphs using adjacency lists.

<details>
<summary>Click to expand operations</summary>

- `Graph* createGraph(int vertices, bool isDirected)`
- `void addEdge(Graph* graph, int src, int dest, int weight)`
- `void removeEdge(Graph* graph, int src, int dest)`
- `void printGraph(Graph* graph)`
- `void BFS(Graph* graph, int startVertex)`
- `void DFS(Graph* graph, int startVertex)`
- `void DFSUtil(Graph* graph, int vertex, bool visited[])`
- `void dijkstra(Graph* graph, int src)`
- `void primMST(Graph* graph)`
- `void topologicalSort(Graph* graph)`
- `bool isCyclic(Graph* graph)`
- `void stronglyConnectedComponents(Graph* graph)`
</details>

#### Graph Algorithms
- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Dijkstra's Shortest Path
- Prim's Minimum Spanning Tree
- Topological Sort
- Cycle Detection
- Strongly Connected Components (Kosaraju's algorithm)

## Algorithms

- Binary Search
- Quicksort
- Mergesort
