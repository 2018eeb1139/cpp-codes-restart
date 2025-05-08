#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    // Your code here
    int v = adj.size();
    vector<int> ans;
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++)
    {
        for (int &child : adj[i])
        {
            indegree[child] += 1;
        }
    }
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int curr_node = q.front();
        ans.push_back(curr_node);
        q.pop();
        for (int child : adj[curr_node])
        {
            indegree[child] -= 1;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    return ans;
}

deque<int> dq;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (int child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
    dq.push_front(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    int v = adj.size();
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
        }
    }
    vector<int> ans;
    for (int x : dq)
    {
        ans.push_back(x);
    }
    return ans;
}