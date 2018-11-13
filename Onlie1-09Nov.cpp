#include <bits/stdc++.h>

#define INFINITE 99999
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

using namespace std;

class ListNode
{
public:
    int item;
    int weight;
    ListNode * next;
    ListNode * prev;
};


class LinkedListDoubly
{

    ListNode * list;
    ListNode * tail;
    int length;

public:
    LinkedListDoubly()
    {
        list = 0;  //initially set to NULL
        tail = 0;
        length=0;
    }

    int getLength()
    {
        return length;
    }

    int insertFirst(int item, int weight) //insert at the beginning
    {
        ListNode * newNode ;
        newNode = new ListNode() ;
        newNode->item = item ;
        newNode->weight = weight;

        if(list==0) //inserting the first item
        {
            newNode->next = 0;
            newNode->prev = 0;
            list = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = list;
            list->prev = newNode;
            newNode->prev = 0;
            list = newNode;
        }
        length++;
        return SUCCESS_VALUE ;
    }

    ListNode * searchItem(int item)
    {
        ListNode * temp ;
        temp = list ; //start at the beginning
        while (temp != 0)
        {
            if (temp->item == item) return temp ;
            temp = temp->next ; //move to next node
        }
        return 0 ; //0 means invalid pointer in C, also called NULL value in C
    }

    void printListForward()
    {
        ListNode * temp;
        temp = list;
        cout << "(item, weight)->" << endl;
        while(temp!=0)
        {
            printf("(%d, %d)->", temp->item, temp->weight);
            temp = temp->next;
        }
        printf("\n");
        cout << "Length : " << length << endl;
    }

    int getElementAtTail(){
        if(tail == NULL){
            return NULL_VALUE;
        }else
            return tail->item;
    }

    ListNode* getFirstElement() {
        return list;
    }

    //------------write code for the functions below-----------
    int insertLast(int item, int weight)
    {
        //write your codes here
        if(length == 0){
            insertFirst(item, weight);
            return SUCCESS_VALUE;
        }
        ListNode* temp = new ListNode();
        temp->item = item;
        temp->weight = weight;
        temp->next = NULL;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        length++;
    }

    int deleteLast()
    {
        //write your codes here
        if(length > 1){
            ListNode* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            length--;
            delete temp;
            return SUCCESS_VALUE;
        }
        else if(length == 1){
            delete tail;
            tail = 0;
            list = 0;
            length = 0;
            return SUCCESS_VALUE;
        }
        else if(length == 0){
            return NULL_VALUE;
        }
    }

    void printListBackward()
    {
        //will print the list backward starting from the tail position
        ListNode* temp = tail;
        cout << "(item, weight)" << endl;
        while(temp != NULL){
            cout << "(" << temp->item << ", " << temp->weight << ")->";
            temp = temp->prev;
        }
        cout << endl;

    }

};

///-----------------------------------------------------------------------------///

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


void printSolution(int dist[], int prev[], int V) {
    cout << "Vertex  Distance  Previous Vertex" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t" << prev[i] << endl;
    }
}

void dijkstra(LinkedListDoubly ll[], int V, int src) {
    int dist[V];
    int prev[V];
    bool sptSet[V];

    for(int i = 0; i < V; i++) {
        dist[i] = INFINITE;
        prev[i] = -1;
        sptSet[i] = false;
    }

    dist[src] = 0;
    MinHEAP h(V);

    for(int i = 0; i < V; i++) {
        Node a;
        a.dist = dist[i];
        a.vertex = i;
        h.insertNode(a);
    }
    while(!h.isEmpty()) {
        Node extracted = h.extractMin();
        int u = extracted.vertex;
        ListNode* temp = ll[u].getFirstElement();
        while(temp != NULL) {
            int v = temp->item;
            int wt = temp->weight;
            if(sptSet[v] == false && dist[u] != INFINITE && dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                prev[v] = u;
                h.decreaseKey(v, dist[v]);
            }
            temp = temp->next;
        }
    }
    printSolution(dist, prev, V);
}

void addEdge(LinkedListDoubly ll[], int u, int v, int wt) {
    ll[u].insertLast(v, wt);
    ll[v].insertLast(u, wt);
}


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, u, v, wt;
    cin >> n >> m;

    int V = n;
    LinkedListDoubly graph[V];

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> wt;
        addEdge(graph, u, v, wt);
    }

    int src;
    cin >> src;

    dijkstra(graph, V, src);

}


















