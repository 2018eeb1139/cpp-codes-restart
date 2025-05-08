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

// accepted
const int M = 1e9 + 7;

void dfs(int node, int par, vector<int> adj[], vector<int> &subtree_sum, vector<int> &val)
{
    subtree_sum[node] += val[node-1;
    for(int child : adj[node]){
        if (child != par)
        {
            dfs(child, node, adj, subtree_sum, val);
            subtree_sum[node] += subtree_sum[child];
        }
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{
    vector<int> adj[A.size() + 1];
    vector<int> subtree_sum(A.size() + 1, 0);
    for (auto edge : B)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    long long ans = 0;
    int n = A.size();
    dfs(1, 0, adj, subtree_sum, A);
    for (int i = 2; i <= n; i++)
    {
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1] - part1;
        ans = max(ans, part1 * 1LL * part2);
    }
    return (ans % M);
}
