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
    int n;
    cin >> n;

    int ara[n];

    for(int i = 0; i < n; i++) {
        cin >> ara[i];
    }

    for(int i = 0; i < n; i++) {
        cout << ara[i] << endl;
    }
}
















