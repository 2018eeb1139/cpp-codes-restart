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

int Solution::motherVertex(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V + 1];
    vector<bool> vis(V + 1, false);
    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        if (x != y)
        {
            adj[x].push_back(y);
        }
    }
    int candidate = -1;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            candidate = i; // last finished vertex
        }
    }
    for (int i = 1; i <= V; i++)
    {
        vis[i] = false;
    }
    // do dfs from candidate
    dfs(candidate, adj, vis);
    for (int i = 1; i <= V; i++)
    {
        if (vis[i] == false)
            return 0;
    }
    return 1; // return candidate for node
}
