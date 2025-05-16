#include "heap.h"
#include <climits>
#include <iostream>
using namespace std;

MinHeap::MinHeap(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    heapArray = new int[capacity];
    keyArray = new int[capacity];
    position = new int[capacity];

    for (int i = 0; i < capacity; ++i) {
        keyArray[i] = INT_MAX;
        position[i] = -1;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

bool MinHeap::isEmpty() {
    return size == 0;
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size && position[vertex] != -1;
}

void MinHeap::insert(int vertex, int key) {
    if (size == capacity) return;

    size++;
    int i = size - 1;
    heapArray[i] = vertex;
    keyArray[vertex] = key;
    position[vertex] = i;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {
        position[heapArray[i]] = (i - 1) / 2;
        position[heapArray[(i - 1) / 2]] = i;
        swap(heapArray[i], heapArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int MinHeap::extractMin() {
    if (size == 0)
        return -1;

    int root = heapArray[0];

    int lastNode = heapArray[size - 1];
    heapArray[0] = lastNode;

    position[lastNode] = 0;
    position[root] = -1;

    size--;
    minHeapify(0);

    return root;
}

void MinHeap::minHeapify(int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;

    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != idx) {
        int smallestVertex = heapArray[smallest];
        int idxVertex = heapArray[idx];

        position[smallestVertex] = idx;
        position[idxVertex] = smallest;

        swap(heapArray[smallest], heapArray[idx]);
        minHeapify(smallest);
    }
}
