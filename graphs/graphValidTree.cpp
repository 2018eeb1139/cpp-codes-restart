bool dfs(int node, int par, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node, adj, vis))
            {
                return true;
            }
        }
        else if (child != par)
        {
            return true;
        }
    }
    return false;
}
int isTree(int V, int E, vector<vector<int>> &edges)
{
    // code here
    bool ans = true;
    if (V - 1 != E)
        return false;
    vector<int> adj[V];
    vector<bool> vis(V, false);
    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis) == true)
            {
                ans = false;
                break;
            }
        }
    }
    return ans;
}