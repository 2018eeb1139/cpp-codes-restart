void dfs(int node, vector<int> adj[], int parent, vector<bool> &vis, vector<int> &v, vector<vector<int>> &paths)
{
    vis[node] = true;
    v.push_back(node);
    bool isLeaf = true;
    for (int &child : adj[node])
    {
        if (child != parent)
        {
            isLeaf = false;
            dfs(child, adj, node, vis, v, paths);
        }
    }
    if (isLeaf)
    {
        paths.push_back(v);
    }
    v.pop_back();
}

int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C)
{
    int n = A.size();
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1, false);

    for (auto &edge : B)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<vector<int>> paths;
    vector<int> v;

    dfs(1, adj, 0, vis, v, paths);
    int ans = 0;
    for (auto &vec : paths)
    {
        int ct = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (A[vec[i] - 1] == 1)
            {
                ct++;
            }
        }
        if (ct <= C)
            ans++;
    }
    return ans;
}
