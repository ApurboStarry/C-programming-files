#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    Edge *edge;
};

Graph* createGraph(int V, int E) {
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void BellmanFord(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(int i = 0; i < V-1; i++) {
        for(int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if(dist[u] != INT_MAX && dist[v] > dist[u] + weight)
                dist[v] = dist[u] + weight;
        }
    }

    for(int j = 0; j < E; j++) {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;

        if(dist[u] != INT_MAX && dist[v] > dist[u] + weight) {
            cout << "The given graph contains negative weighted edge" << endl;
            return;
        }
    }

    cout << "Vertex  Distance from Source" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
    cout << endl;
}

void spfa(Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;

    int dist[V];
    queue<int> q;
    bool isInQueue[V];
    int counter = 0;
    int flag = -1;

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;
    q.push(src);
    q.push(flag);
    isInQueue[src] = 1;

    while(q.size() != 1) {
        int u = q.front();
        q.pop();
        cout << "Popped Element : " << u << endl;

        if(u == flag) {
            counter++;
            q.push(flag);
            continue;
        }
        isInQueue[u] = 0;

        cout << counter << endl;

        for(int i = 0; i < E; i++) {
            int x = graph->edge[i].src;
            int y = graph->edge[i].dest;
            int weight = graph->edge[i].weight;

            if(x == u) {
                if(dist[y] > dist[x] + weight) {
                    dist[y] = dist[x] + weight;
                    if(isInQueue[y] == false){
                        isInQueue[y] = true;
                        q.push(y);
                    }
                }
            }
        }

        if(counter > V-1) {
            cout << "The graph contains negative weight cycle" << endl;
            return;
        }
    }

    cout << "Vertex  Distance from source" << endl;
    for(int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
    cout << endl;
    cout << endl << counter << endl;
}

int main() {
    int n, m, u, v, wt;
    cin >> n >> m;
    Graph *graph = createGraph(n, m);

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> wt;
        graph->edge[i].src = u;
        graph->edge[i].dest = v;
        graph->edge[i].weight = wt;
    }

    int src;
    cin >> src;

    BellmanFord(graph, src);
    //spfa(graph, src);
}














