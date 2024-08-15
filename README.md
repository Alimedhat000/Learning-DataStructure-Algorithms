# 🚀 Data Structures and Algorithms Training

This repository is a result of my deep dive into Data Structures and Algorithms (DSA), following the curriculum from [Coding Interview University](https://github.com/jwasham/coding-interview-university). It includes comprehensive implementations of fundamental data structures and algorithms.

## 📚 Table of Contents

- [Data Structures](#-data-structures)
  - [Dynamic Arrays](#-dynamic-arrays)
  - [Linked Lists](#-linked-lists)
  - [Queue](#%EF%B8%8F-queue)
  - [Stack](#-stack)
  - [HashMaps](#-hashmaps)
  - [Trees](#-trees)
  - [Heaps](#%EF%B8%8F-heaps)
  - [Graphs](#-graphs)
- [Algorithms](#-algorithms)

## 🧩 Data Structures

### 📊 Dynamic Arrays
Implementation of a dynamically sized array that automatically adjusts its size based on the number of elements.

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

### 🔗 Linked Lists
Implementation of **Single**, **Double**, and **Circular (Ring)** linked lists, each serving different purposes and use cases.

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

### 🛤️ Queue
Implementation of a **Queue** using linked lists, adhering to the First-In-First-Out (FIFO) principle.

<details>
<summary>Click to expand operations</summary>

- `void enqueue(data)`
- `int dequeue()`
- `int printqueue(index)`
</details>

### 🥞 Stack
Implementation of a **Stack** using linked lists, operating on the Last-In-First-Out (LIFO) principle.

<details>
<summary>Click to expand operations</summary>

- `void push(data)`
- `int pop()`
- `int printstack()`
- `void sortstack()`
- `int peekstack()`
</details>

### 🌐 HashMaps
Implementation of a **HashMap** with chaining (an array of linked lists) to handle collisions efficiently.

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

### 🌳 Trees
Implementation of a **Binary Search Tree (BST)**, a tree data structure with nodes that follow the left child < parent < right child rule.

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

### 🛠️ Heaps

Implementation of **Max Heap** and **Min Heap** (priority queues) using a static array.

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

### 🌐 Graphs

Implementation of both **Directed** and **Undirected Graphs** using adjacency lists, and adjacency Matrix along with essential graph algorithms.

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

## 🧠 Algorithms

Implementation of core algorithms that are widely used in computer science:

- Binary Search
- Quicksort
- Mergesort

---

This repository is designed to help reinforce my understanding of DSA and to serve as a reference for others who are on a similar learning journey. Feel free to explore, learn, and contribute!
