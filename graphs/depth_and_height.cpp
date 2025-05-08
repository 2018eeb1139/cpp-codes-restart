#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int> &depth, vector<int> &height)
{
    for (int child : adj[node])
    {
        if (child != par)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node, adj, depth, height);
            height[node] = max(height[node], height[child] + 1);
        }
    }
}

int main()
{
    int V;
    cin >> V;
    vector<int> adj[V + 1];
    // tree will have V-1 edges
    for (int i = 1; i <= V - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> depth(V + 1, 0);
    vector<int> height(V + 1, 0);

    dfs(1, -1, adj, depth, height);

    cout << "Node\tDepth\tHeight" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << "\t" << depth[i] << "\t" << height[i] << endl;
    }
}
