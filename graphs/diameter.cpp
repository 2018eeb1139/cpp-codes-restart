#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int> &depth)
{
    for (int child : adj[node])
    {
        if (child != par)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node, adj, depth);
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
    vector<int> depth(V + 1, 0);
    dfs(1, -1, adj, depth);

    // for(int i=1;i<=V;i++){
    //     cout<<i<<" "<<depth[i]<<endl;
    // }
    int max_d_node;
    int max_depth = -1;
    for (int i = 1; i <= V; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0; // resetting the depth
    }
    // cout<<max_d_node<<" "<<max_depth<<endl;
    dfs(max_d_node, -1, adj, depth);
    max_depth = -1;
    for (int i = 1; i <= V; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
        }
    }
    cout << max_depth << endl;
}
