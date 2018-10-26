#include <iostream>

using namespace std;

void swapKeys(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap {
    int *hArray;
    int size;
    int capacity;
public:
    MinHeap(int capacity);
    void insertKey(int k);
    int getParent(int i) { return (i-1)/2;};
    int getLeft(int i) { return 2*i + 1;};
    int getRight(int i) { return 2*i + 2;};
    void minHeapify(int i);
    int extractMin();
    int getMin() {return hArray[0];};
    void deleteKey(int i);
    void decreaseKey(int i, int newValue);
    void print();
};

void MinHeap::print(){
    cout << endl << "The Min Heap is : ";
    for(int i = 0;i<size;i++){
        cout << hArray[i] << " ";
    }
}

void MinHeap::decreaseKey(int i, int newVal){
    hArray[i] = newVal;
    while(i != 0 && hArray[getParent(i)] > hArray[i]){
        swapKeys(&hArray[getParent(i)], &hArray[i]);
        i = getParent(i);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}

int MinHeap::extractMin(){
    int temp = hArray[0];
    hArray[0] = hArray[size - 1];
    size--;
    minHeapify(0);
    return temp;
}

void MinHeap::minHeapify(int i){
    int l = getLeft(i);
    int r = getRight(i);
    int smallest = i;
    if(l < size && hArray[l] < hArray[i])
        smallest = l;
    if(l < size && hArray[r] < hArray[smallest])
        smallest = r;
    if(smallest != i){
        swapKeys(&hArray[i], &hArray[smallest]);\
        minHeapify(smallest);
    }
}

void MinHeap::insertKey(int k){
    size++;
    int i = size - 1;
    hArray[i] = k;
    while(i != 0 && hArray[getParent(i)] > hArray[i]){
        swapKeys(&hArray[getParent(i)], &hArray[i]);
        i = getParent(i);
    }
}

MinHeap::MinHeap(int cap){
    size = 0;
    capacity = cap;
    hArray = new int[capacity];
}

int main(){
    MinHeap mh(10);
    mh.insertKey(4);
    mh.insertKey(5);
    mh.insertKey(3);

    mh.print();
}


















