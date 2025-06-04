#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> allPaths;

void dfs(int node, int parent, vector<int> &path)
{
    path.push_back(node);
    bool isLeaf = true;

    for (int child : adj[node])
    {
        if (child != parent)
        {
            isLeaf = false;
            dfs(child, node, path);
        }
    }

    if (isLeaf)
    {
        allPaths.push_back(path); // Save the current root-to-leaf path
    }

    path.pop_back(); // Backtrack
}

int main()
{
    int n; // number of nodes
    cin >> n;

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's an undirected tree
    }

    vector<int> path;
    dfs(1, 0, path); // root = 1, parent of root = 0

    // Print all paths
    for (const auto &p : allPaths)
    {
        for (int node : p)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
