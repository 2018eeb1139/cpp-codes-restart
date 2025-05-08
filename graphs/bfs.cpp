#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &level)
{
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();
        cout << curr_node << " ";
        for (int child : adj[curr_node])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[curr_node] + 1;
            }
        }
    }
}

int main()
{
    int V;
    cin >> V;
    vector<int> adj[V + 1];
    for (int i = 0; i < V - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> vis(V + 1, 0);
    vector<int> level(V + 1, 0);
    bfs(1, adj, vis, level);
    cout << "\nNode\t" << "Level" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << "\t" << level[i] << endl;
    }
}
