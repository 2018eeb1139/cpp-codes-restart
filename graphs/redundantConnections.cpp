bool dfs(int src, int target, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (src == target)
        return true;
    vis[src] = true;
    for (int &child : adj[src])
    {
        if (!vis[child])
        {
            if (dfs(child, target, adj, vis) == true)
            {
                return true;
            }
        }
    }
    return false;
}
vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int V = edges.size();
    vector<vector<int>> adj(V + 1);
    for (auto &edge : edges)
    {
        vector<bool> vis(V + 1, false);
        int x = edge[0];
        int y = edge[1];
        if (dfs(x, y, adj, vis) == true)
        {
            return edge;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    return {};
}