#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
void dfs(int node, vector<vector<int>> &adj_fwd, vector<vector<int>> &adj_bwd, vector<bool> &vis)
{
    vis[node] = true;
    for (int child : adj_fwd[node])
    {
        if (!vis[child])
        {
            ans += 1;
            dfs(child, adj_fwd, adj_bwd, vis);
        }
    }
    for (int child : adj_bwd[node])
    {
        if (!vis[child])
        {
            dfs(child, adj_fwd, adj_bwd, vis);
        }
    }
}
int minReorder(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj_fwd(n);
    vector<vector<int>> adj_bwd(n);
    vector<bool> vis(n, false);
    for (auto edge : connections)
    {
        int x = edge[0];
        int y = edge[1];
        adj_fwd[x].push_back(y);
        adj_bwd[y].push_back(x);
    }

    dfs(0, adj_fwd, adj_bwd, vis);
    return ans;
}