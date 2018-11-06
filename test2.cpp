#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

class MinHeap {
    int *heapArray;
    int heapSize;
    int capacity;
public:
    MinHeap(int cap);
    int parent(int i) {return (i-1) / 2;};
    int left(int i) {return 2 * i + 1;};
    int right(int i) {return 2 * i + 2;};
    void insertKey(int val);
    void MinHeapify(int i);
    void decreaseKey(int i, int val);
    void deleteKey(int i);
    int extractMin();
    int getMin();
    void print();
    bool isEmpty();
};

bool MinHeap::isEmpty() {
    return (heapSize==0);
}

void MinHeap::print() {
    for(int i = 0; i < heapSize; i++) {
        cout << heapArray[i] << " ";
    }
    cout << endl;
}

MinHeap::MinHeap(int cap) {
    capacity = cap;
    heapSize = 0;
    heapArray = new int[capacity];
}

void MinHeap::insertKey(int val) {
    if(heapSize == capacity) {
        cout << "\nOverload" << endl;
        return;
    }
    heapSize++;
    int i = heapSize - 1;
    heapArray[i] = val;
    while(i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(&heapArray[parent(i)], &heapArray[i]);
        i = parent(i);
    }
}

void MinHeap::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heapSize && heapArray[l] < heapArray[i]) {
        smallest = l;
    }
    if(r < heapSize && heapArray[r] < heapArray[smallest])
        smallest = r;

    if(smallest != i) {
        swap(&heapArray[i], &heapArray[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if(heapSize <= 0) {
        cout << "Heap is already empty" << endl;
        return INT_MAX;
    }
    if(heapSize == 1) {
        heapSize--;
        return heapArray[0];
    }
    int root = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    MinHeapify(0);
    return root;
}

void MinHeap::decreaseKey(int i, int new_val)
{
    heapArray[i] = new_val;
    while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN);
    extractMin();
}

int MinHeap::getMin() {return heapArray[0];}


int main () {

}

















