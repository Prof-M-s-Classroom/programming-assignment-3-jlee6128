[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jae Yoon Lee

## Description
This program implements Prim’s Algorithm to find the Minimum Spanning Tree (MST) of a connected, 
undirected graph using a custom-built MinHeap (not using STL and an adjacency matrix representation of the graph

The code is modular and object-oriented, with two main classes which is
MinHeap=> Handles priority operations like insert, extractMin and decreaseKey
Graph =>  Manages graph structure and runs Prim’s algorithm using the MinHeap

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.



## Time Complexity Analysis


| Operation            | Time Complexity                                                                                    |
|----------------------|----------------------------------------------------------------------------------------------------|
| Insert in MinHeap    | O(logN)                                                                                            |
| Extract Min          | O(logN)                                                                                            |
| Decrease Key         | O(logN)                                                                                            |
| Prim’s MST Overall   | O(N²logN)  |

_Explain why your MST implementation has the above runtime._
(It is because of the adjacency matrix and heap operations insider a loop over vertices)

Input:  ```cpp
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

Challanges I faced
While debugging my Prim’s Algorithm implementation, I initially 
encountered incorrect MST outputs due to improper index updates in the decreaseKey function. 
The main issue was that I forgot to update the position[] array after swapping nodes in the heap,
which caused the wrong node to be extracted. I used print statements to trace how the heap structure changed after each
operation and verified the correctness of the key[] values during each iteration. After fixing the position tracking and confirming all 
updates occurred in sync, the algorithm produced the correct MST.
