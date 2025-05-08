#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    // cout<<node<<" ";
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
}
void bfs(int src, vector<vector<int>> &adj, vector<bool> &vis)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();
        for (int child : adj[curr_node])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                // level[child] = level[curr_node] + 1;
            }
        }
    }
}
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    vector<vector<int>> adj(n);
    vector<bool> vis(n + 1, false);
    for (auto edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // dfs(source,adj,vis);
    bfs(source, adj, vis);
    if (vis[destination])
        return true;
    else
        return false;
}