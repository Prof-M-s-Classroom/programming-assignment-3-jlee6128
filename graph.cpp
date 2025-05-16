#include "graph.h"
#include "heap.h"
#include <iostream>
using namespace std;

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new int[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; // Undirected graph
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    int* key = new int[numVertices];
    MinHeap minHeap(numVertices);

    for (int v = 0; v < numVertices; v++) {
        key[v] = INT_MAX;
        parent[v] = -1;
        minHeap.insert(v, key[v]);
    }

    key[0] = 0;
    minHeap.decreaseKey(0, 0);

    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin();

        for (int v = 0; v < numVertices; v++) {
            if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {
                key[v] = adjMatrix[u][v];
                parent[v] = u;
                minHeap.decreaseKey(v, key[v]);
            }
        }
    }

    int totalWeight = 0;
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < numVertices; i++) {
        cout << parent[i] << " - " << i << "    " << adjMatrix[i][parent[i]] << endl;
        totalWeight += adjMatrix[i][parent[i]];
    }
    cout << "Total Weight of MST: " << totalWeight << endl;

    delete[] parent;
    delete[] key;
}