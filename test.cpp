#include<iostream>
#include<list>
using namespace std;

int n;
string res = "";

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing
    // adjacency lists
    list<int> *adj;

    // A recursive function used by DFS
    bool DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v);
}

bool Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    //cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if(*i == n){
            res += to_string(*i);
            return true;
        }
        if (!visited[*i]){
            bool check = DFSUtil(*i, visited);
            if(check == true){
                res += to_string(*i);
                return true;
            }
        }
    }
    return 0;
}

// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function
    // to print DFS traversal
    DFSUtil(v, visited);
}

int main()
{
    // Create a graph given in the above diagram
    cin >> n;
    int ara[n+1];
    for(int i = 2;i<=n;i++){
        cin >> ara[i];
    }
    Graph g(n+1);
    for(int i = 2;i<=n;i++){
        g.addEdge(ara[i], i);
    }

    //cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(1);
    cout << "1 ";
    for(int i = res.length()-1;i>=0;i--){
        cout << res[i] << " ";
    }
    return 0;
}
