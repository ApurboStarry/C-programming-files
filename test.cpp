#include <bits/stdc++.h>

#define INFINITE 99999
#define V 500

using namespace std;

void printSolution(int dist[V][V], int n) {
    cout << "\nAll pair shortest path:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == 999999)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int summation(int graph[V][V], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(graph[i][j] != 999999)
                sum += graph[i][j];
        }
    }
    return sum;
}

int FloydWarshall(int dist[V][V], int k, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][k] + dist[k][j] < dist[i][j])
                dist[i][j] = dist[i][k] + dist[k][j];
        }
    }
    printSolution(dist, n);
    return summation(dist, n);
}

int main() {
    int graph[V][V];
    int n, m, u, v, wt;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> wt;
            graph[i][j] = wt;
        }
    }

    int nodes[n];
    int input;

    for(int i = 0; i < n; i++) {
        cin >> input;
        nodes[i] = input - 1;
    }

    int dist[V][V];
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = 999999;
        }
    }

    for(int i = n-1; i >= 0; i--) {

    }
}

/*
int main() {
    int graph[V][V];
    //int originalGraph[V][V];
    int n, m, u, v, wt;
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> wt;
            graph[i][j] = wt;
            //originalGraph[i][j] = graph[i][j];
        }
    }

    int nodes[n];
    int input;

    for(int i = 0; i < n; i++) {
        cin >> input;
        nodes[i] = input - 1;
    }

    int result[n];

    //cout << FloydWarshall(graph, n) << endl;



    for(int i = 0; i < n; i++) {
        result[i] = FloydWarshall(graph, n);

        for(int j = 0; j < n; j++) {
            graph[nodes[i]][j] = 999999;
        }
        for(int j = 0; j < n; j++) {
            graph[j][nodes[i]] = 999999;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }


}
*/
