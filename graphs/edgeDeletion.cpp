#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &subtree, vector<int> &weight)
{
    vis[node] = true;
    subtree[node] += weight[node - 1];
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, subtree, weight);
            subtree[node] += subtree[child];
        }
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {1, 2}, {1, 4}, {4, 3}};
    vector<int> weight = {10, 5, 12, 6};
    vector<int> adj[V + 1];
    vector<bool> vis(V + 1, false);
    vector<int> subtree(V + 1, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, adj, vis, subtree, weight);
    int mx = INT_MIN;
    for (int i = 2; i <= V; i++)
    {
        int part1 = subtree[i];
        int part2 = subtree[1] - part1;
        mx = max(mx, part1 * part2);
    }
    cout << mx << endl;
}

void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &subtree, vector<int> &weight)
{
    vis[node] = true;
    subtree[node] += weight[node - 1];
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis, subtree, weight);
            subtree[node] += subtree[child];
        }
    }
}

int Solution::deleteEdge(vector<int> &weight, vector<vector<int>> &edges)
{
    int V = weight.size();
    vector<int> adj[V + 1];
    vector<bool> vis(V + 1, false);
    vector<int> subtree(V + 1, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, adj, vis, subtree, weight);
    long long mx = INT_MIN;
    for (int i = 2; i <= V; i++)
    {
        long long part1 = subtree[i];
        long long part2 = subtree[1] - part1;
        long long ans = (part1 * 1LL * part2) % M;
        mx = max(mx, ans);
    }
    return mx;
}
