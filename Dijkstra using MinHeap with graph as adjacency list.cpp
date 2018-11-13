#include <bits/stdc++.h>
#include <huday.h>

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


void printSolution(int dist[], int V) {
    cout << "Vertex  Distance" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

void dijkstra(vector<pair<int, int>> adj[], int V, int src) {
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
        for(auto it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first;
            int wt = it->second;
            if(sptSet[v] == false && dist[u] != INFINITE && dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                prev[v] = u;
                h.decreaseKey(v, dist[v]);
            }
        }
    }

    printSolution(dist, V);
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}


int main() {
    /*
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 7, 8, 7);
    addEdge(adj, 7, 6, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 6, 5, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 5, 4, 10);

    dijkstra(adj, V, 0);
    */
    foo();
}


















