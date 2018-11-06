#include <iostream>

#define V 9
#define INFINITE 99999

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node {
    int dist;
    int vertex;
};

void swapNode(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

class MinHEAP {
    Node *heapArray;
    int *index;
    int heapSize;
    int capacity;
public:
    MinHEAP(int capacity);
    int parent(int i) {return (i-1) / 2;}
    int left(int i) {return 2*i + 1;}
    int right(int i) {return 2*i + 2;}
    void insertNode(Node a);
    void minHeapify(int i);
    void decreaseKey(int vertex, int dist);
    bool isEmpty() {return heapSize == 0;};
    Node extractMin();
    void print();
    Node check();
    int indexOf(int vertex) {return index[vertex];}
};

Node MinHEAP::check() {
    Node a;
    a.dist = 3;
    a.vertex = 4;
    return a;
}

void MinHEAP::print() {
    cout << "Vertex  Distance  Index" << endl;
    for(int i = 0; i < heapSize; i++) {
        cout << heapArray[i].vertex << "\t" << heapArray[i].dist << "\t\t" << index[heapArray[i].vertex] << endl;
    }
    cout << endl;
}

Node MinHEAP::extractMin() {
    if(heapSize <= 0) {
        cout << "Heap is already empty" << endl;
        //return INT_MAX;
    }
    if(heapSize == 1) {
        heapSize--;
        return heapArray[0];
    }
    Node root = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    index[heapArray[0].vertex] = 0;
    heapSize--;
    minHeapify(0);
    return root;
}

void MinHEAP::decreaseKey(int vertex, int dist) {
    int i = index[vertex];
    heapArray[i].dist = dist;
    while (i != 0 && heapArray[parent(i)].dist > heapArray[i].dist) {
        swapNode(&heapArray[i], &heapArray[parent(i)]);
        swap(&index[heapArray[i].vertex], &index[heapArray[parent(i)].vertex]);
        i = parent(i);
    }
}

void MinHEAP::minHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heapSize && heapArray[l].dist < heapArray[i].dist) {
        smallest = l;
    }
    if(r < heapSize && heapArray[r].dist < heapArray[smallest].dist) {
        smallest = r;
    }

    if(smallest != i) {
        swapNode(&heapArray[smallest], &heapArray[i]);
        swap(&index[heapArray[smallest].vertex], &index[heapArray[i].vertex]);
        minHeapify(smallest);
    }
}

void MinHEAP::insertNode(Node a) {
    if(heapSize == capacity) {
        cout << "Overload" << endl;
        return;
    }
    heapSize++;
    int i = heapSize - 1;
    heapArray[i] = a;
    index[a.vertex] = i;
    while(i != 0 && heapArray[parent(i)].dist > heapArray[i].dist) {
        swapNode(&heapArray[parent(i)], &heapArray[i]);
        swap(&index[heapArray[parent(i)].vertex], &index[heapArray[i].vertex]);
        i = parent(i);
    }
}

MinHEAP::MinHEAP(int cap) {
    heapArray = new Node[cap];
    capacity = cap;
    heapSize = 0;
    index = new int[cap];
}

///-----------------------------------------------------------------------------------///


void printSolution(int dist[]) {
    cout << "Vertex  Distance" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int prev[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INFINITE;
        prev[i] = -1;
        sptSet[i] = false;
    }

    dist[src] = 0;
    MinHEAP h(V);

    for(int i = 0; i < V; i++) {
        Node a;
        a.vertex = i;
        a.dist = dist[i];
        h.insertNode(a);
    }

    while(!h.isEmpty()) {
        Node extracted = h.extractMin();
        int u = extracted.vertex;
        for(int v = 0; v < V; v++) {
            if(sptSet[v] == false && graph[u][v] && dist[u] != INFINITE && dist[v] > dist[u] + graph[u][v]){
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
                h.decreaseKey(v, dist[v]);
            }
        }
    }

    printSolution(dist);
}


int main() {
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                        {4, 0, 8, 0, 0, 0, 0, 11, 0},
                        {0, 8, 0, 7, 0, 4, 0, 0, 2},
                        {0, 0, 7, 0, 9, 14, 0, 0, 0},
                        {0, 0, 0, 9, 0, 10, 0, 0, 0},
                        {0, 0, 4, 14, 10, 0, 2, 0, 0},
                        {0, 0, 0, 0, 0, 2, 0, 1, 6},
                        {8, 11, 0, 0, 0, 0, 1, 0, 7},
                        {0, 0, 2, 0, 0, 0, 6, 7, 0}
                      };
    dijkstra(graph, 0);
}

















