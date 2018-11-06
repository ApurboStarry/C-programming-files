#include <iostream>
#include <algorithm>

using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
}

void print(vector<pair<int, int>> adj[], int V) {
    for(int i = 0; i < V; i++) {
        cout << "Vertex " << i << " makes an edge with" << endl;
        for(auto it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << "\tVertex " << it->first << " with an weight " << it->second << endl;
        }
        cout << endl;
    }
}

int main()
{
    int V = 5;
    vector<pair<int, int> > adj[V];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    print(adj, V);
}
















