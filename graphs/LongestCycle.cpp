#include <iostream>
#include <vector>
using namespace std;

int ans = -1;
bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &curr_path, int curr)
{
    vis[node] = true;
    curr_path[node] = curr;
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, curr_path, curr + 1);
        }
        else if (curr_path[child] > 0)
        {
            int cycle = curr_path[node] - curr_path[child] + 1;
            ans = max(ans, cycle);
        }
    }
    curr_path[node] = 0;
    return false;
}
int longestCycle(vector<int> &edges)
{
    int V = edges.size();
    vector<vector<int>> adj(V);
    vector<bool> vis(V, false);
    vector<int> curr_path(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (edges[i] != -1)
        {
            adj[i].push_back(edges[i]);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, curr_path, 1);
        }
    }
    return ans;
}