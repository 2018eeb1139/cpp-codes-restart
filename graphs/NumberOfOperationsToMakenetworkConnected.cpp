#include <iostream>
#include <vector>

using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    for (int child : adj[node])
    {
        if (vis[child] == 0)
        {
            dfs(child, vis, adj);
        }
    }
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    int conn = connections.size();
    if (conn < n - 1)
        return -1;
    vector<int> adj[n];
    vector<int> vis(n, 0);
    for (int i = 0; i < conn; i++)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, vis, adj);
            cnt++;
        }
    }
    return cnt - 1;
}