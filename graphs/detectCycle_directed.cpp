#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &curr_path)
{
    vis[node] = true;
    curr_path[node] = 1;
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, adj, vis, curr_path))
            {
                return true;
            }
        }
        else if (curr_path[child] == 1)
        {
            return true;
        }
    }
    curr_path[node] = 0;
    return false;
}

int main()
{
    int V = 4;
    int E = 4;
    vector<int> adj[V + 1];
    vector<bool> vis(V + 1, false);
    vector<int> curr_path(V + 1, 0);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(2);
    // adj[1].push_back(2);
    // adj[1].push_back(3);
    // adj[2].push_back(3);

    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, vis, curr_path) == true)
            {
                cout << "true";
                return 0;
            }
        }
    }
    cout << "false";
    return 0;
}
