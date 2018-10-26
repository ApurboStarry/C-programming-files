#include<iostream>
#include<cstdlib>

using namespace std;

class MinHeapNode {
    char data;
    int freq;
    MinHeapNode* left;
    MinHeapNode* right;
public:
    MinHeapNode(char data, int freq){
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
    int getFrequency(){return freq;}
    char getData(){return data;}
    bool isLeaf(){return !left && !right;}
    void setLeft(MinHeapNode* a){left = a;}
    void setRight(MinHeapNode* a){right = a;}
    MinHeapNode* getLeft(){return left;}
    MinHeapNode* getRight(){return right;}
};

void swapNodes(MinHeapNode** a, MinHeapNode** b){
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void printCodes(MinHeapNode* mh, int ara[], int top){
    if(mh->getLeft()){
        ara[top] = 0;
        printCodes(mh->getLeft(), ara, top+1);
    }
    if(mh->getRight()){
        ara[top] = 1;
        printCodes(mh->getRight(), ara, top+1);
    }

    if(mh->isLeaf()){
        cout << mh->getData() << ": ";
        for(int i = 0;i<top;i++)
            cout << ara[i];
        cout << endl;
    }
}

class MinHeap {
    int size,capacity;
    MinHeapNode** hArray;
public:
    MinHeap(char data[], int freq[], int capacity);
    int getParent(int index){return (index-1)/2;};
    int getLeft(int i){return 2*i+1;};
    int getRight(int i){return 2*i+2;};
    void minHeapify(int i);
    MinHeapNode* extractMin();
    void print();
    void insertNewNode(MinHeapNode* mh);
};

void MinHeap::insertNewNode(MinHeapNode* mh){
    size++;
    int i = size - 1;
    while(i && mh->getFrequency() < hArray[getParent(i)]->getFrequency()){
        hArray[i] = hArray[getParent(i)];
        i = getParent(i);
    }
    hArray[i] = mh;
}

void MinHeap::print(){
    for(int i = 0;i<size;i++)
        cout << hArray[i]->getData() << " " << hArray[i]->getFrequency() << endl;
}

MinHeapNode* MinHeap::extractMin(){
    MinHeapNode* temp = hArray[0];
    hArray[0] = hArray[size - 1];
    size--;
    minHeapify(0);
    return temp;
}

void MinHeap::minHeapify(int i){
    int smallest = i;
    int left = getLeft(i);
    int right = getRight(i);

    if(left < size && hArray[left]->getFrequency() < hArray[smallest]->getFrequency())
        smallest = left;
    if(right < size && hArray[right]->getFrequency() < hArray[smallest]->getFrequency())
        smallest = right;
    if(smallest != i){
        swapNodes(&hArray[smallest], &hArray[i]);
        minHeapify(smallest);
    }
}

MinHeap::MinHeap(char data[], int freq[], int capacity){
    hArray = (MinHeapNode**) malloc(capacity * sizeof(MinHeapNode));
    this->capacity = capacity;
    size = capacity;

    for(int i = 0;i<capacity;i++){
        hArray[i] = new MinHeapNode(data[i], freq[i]);
    }

    int n = size - 1;
    for(int i = (n-1)/2;i>=0;i--){
        minHeapify(i);
    }

    MinHeapNode *left, *right, *top;

    while(size > 1){
        left = extractMin();
        right = extractMin();
        top = new MinHeapNode('$', left->getFrequency()+right->getFrequency());
        top->setLeft(left);
        top->setRight(right);
        insertNewNode(top);
        //cout << endl << endl;
        //print();
    }

    MinHeapNode* mh = extractMin();
    //cout << "%%" << mh->getData() << " " << mh->getFrequency() << endl;

    int ara[size];
    printCodes(mh, ara, 0);

    MinHeapNode* hh = mh->getLeft();
    //cout << "^^" << hh->getData() << endl;
    //cout << "^^" << mh->getLeft()->getData() << endl;

    /*
    for(int i = 0;i<capacity;i++){
        cout << hArray[i]->getData() << " " << hArray[i]->getFrequency() << endl;
    }
    */
}





int main(){
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = {45, 13, 12, 16, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);

    MinHeap* mh = new MinHeap(data, freq, size);
    //mh->print();

    //MinHeapNode* mh1 = new MinHeapNode('z', 111);

    //mh->print();

    /*
    MinHeapNode* mh1 = new MinHeapNode('a', 12);
    MinHeapNode* mh2 = new MinHeapNode('b', 13);

    cout << mh1->getData() << " " << mh1->getFrequency() << endl;
    cout << mh2->getData() << " " << mh2->getFrequency() << endl;

    swapNodes(&mh1, &mh2);

    cout << mh1->getData() << " " << mh1->getFrequency() << endl;
    cout << mh2->getData() << " " << mh2->getFrequency() << endl;
    */
}
