double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis)
{
    if (adj.find(src) == adj.end())
    {
        return -1.0;
    }
    if (src == dest)
    {
        return 1.0;
    }
    vis.insert(src);
    for (auto &child : adj[src])
    {
        auto ch = child.first;
        auto wt = child.second;
        if (vis.find(ch) == vis.end())
        {
            double res = dfs(ch, dest, adj, vis);
            if (res != -1.0)
            {
                return res * wt;
            }
        }
    }
    return -1.0;
}
vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    vector<double> ans;
    unordered_map<string, vector<pair<string, double>>> adj;
    for (int i = 0; i < equations.size(); i++)
    {
        string A = equations[i][0];
        string B = equations[i][1];
        double value = values[i];
        adj[A].push_back({B, value});
        adj[B].push_back({A, 1.0 / value});
    }
    for (auto &q : queries)
    {
        string C = q[0];
        string D = q[1];
        if (adj.find(C) == adj.end() || adj.find(D) == adj.end())
        {
            ans.push_back(-1.0);
            continue;
        }
        if (C == D)
        {
            ans.push_back(1.0);
            continue;
        }
        unordered_set<string> vis;
        double res = dfs(C, D, adj, vis);
        ans.push_back(res);
    }
    return ans;
}