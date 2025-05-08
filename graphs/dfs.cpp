#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";
    for (int child : adj[node])
    {
        if (!visited[child])
        {
            dfs(child, adj, visited);
        }
    }
}

int main()
{
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1, 5};
    adj[5] = {4};

    vector<bool> visited(V, false);

    cout << "DFS traversal starting from node 0: \n";
    dfs(0, adj, visited);

    return 0;
}
