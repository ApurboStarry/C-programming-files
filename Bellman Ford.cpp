#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    Edge *edge;
};

Graph* createNewGraph(int V, int E) {
    Graph *graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

bool BellmanFord(Graph *graph, int src, int dist[]) {
    int V = graph->V;
    int E = graph->E;

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    for(int i = 0; i < V-1; i++) {
        for(int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int wt = graph->edge[j].weight;

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(int j = 0; j < E; j++) {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int wt = graph->edge[j].weight;

        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            return true;
        }
    }
    return false;
}

bool negativeCycleDetection(Graph *graph) {
    int V = graph->V;
    int dist[V];

    bool visited[V];
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < V; i++) {
        if(visited[i] == false) {
            if(BellmanFord(graph, i, dist))
                return true;
            for(int j = 0; j < V; j++) {
                if(dist[j] != INT_MAX)
                    visited[j] == true;
            }
        }
    }
    return false;
}

int main() {
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    Graph* graph = createNewGraph(V, E);
    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;
    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;
    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;
    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;
    // add edge 1-4 (or A-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;
    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;
    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;
    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;
    cout << negativeCycleDetection(graph) << endl;
}























