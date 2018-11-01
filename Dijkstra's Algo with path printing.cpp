#include <iostream>
#include <cstring>
#define V 9

using namespace std;

int minimumVertex(int dist[], bool sptSet[]) {
    int minimum = INT_MAX, minimumIndex;
    for(int i = 0; i < V; i++) {
        if(dist[i] < minimum && sptSet[i] == false){
            minimum = dist[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

void printPath(int parent[], int u) {
    int result[V];
    int  index = 1;
    result[0] = u;

    while(parent[u] != -1) {
        u = parent[u];
        result[index++] = u;
    }
    for(int i = index - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void printSolution(int dist[], int parent[]) {
    cout << "Vertex Distance  Path" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << "\t";
        printPath(parent, i);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;
    parent[src] = -1;

    for(int i = 0; i < V-1; i++) {
        int u = minimumVertex(dist, sptSet);
        sptSet[u] = true;
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && sptSet[v] == false && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printSolution(dist, parent);
}

int main () {
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


















