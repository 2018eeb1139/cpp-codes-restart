void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
}

int Solution::solve(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V + 1];
    vector<bool> vis(V + 1, false);
    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
    }
    dfs(1, adj, vis);
    return vis[V];
}
