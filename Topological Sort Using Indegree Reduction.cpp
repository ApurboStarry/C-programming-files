#include <iostream>
#include <cstring>

using namespace std;

int main () {
    int n;
    cin >> n;
    int graph[n][n];
    int indegree[n];
    for(int i = 0; i < n; i++) {
        indegree[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }

    bool visited[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }

    int length = n;

    while(length--) {
        for(int i = 0; i < n; i++) {
            if(visited[i] == false && indegree[i] == 0) {
                for(int j = 0; j < n; j++) {
                    if(graph[i][j] == 1){
                        indegree[j]--;
                    }
                }
                cout << i << " ";
                visited[i] = true;
                break;
            }
        }
    }

}


















