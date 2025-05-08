#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int child : adj[node]) {
        if (!visited[child]) {
            if (dfs(child, node, adj, visited)) {
                return true;  // Cycle found
            }
        } else if (child != parent) {
            return true;  // Back edge detected
        }
    }

    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;  // Cycle detected
            }
        }
    }
    return false;  // No cycle
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }

    if (isCyclic(V, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
