#include <bits/stdc++.h>
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
    int n, m, a, b, w;
    cin >> n >> m;
    vector<pair<int, int>> graph(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b, w));
    }


    //dijkstra(graph, 0);
}


















