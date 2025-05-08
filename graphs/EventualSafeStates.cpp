#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &curr_path)
{
    vis[node] = true;
    curr_path[node] = 1;
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, adj, vis, curr_path))
            {
                return true;
            }
        }
        else if (curr_path[child] == 1)
        {
            return true;
        }
    }
    curr_path[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> vis(V, false);
    vector<int> curr_path(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, curr_path);
        }
    }
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (curr_path[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}