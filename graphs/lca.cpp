#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<int> &par)
{
    par[node] = parent;
    for (int child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node, adj, par);
        }
    }
}

vector<int> path(int node, vector<int> &par)
{
    vector<int> ans;
    while (node != -1)
    {
        ans.push_back(node);
        node = par[node];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    vector<int> par(V + 1);
    dfs(1, -1, adj, par);
    //    for(int i=1;i<=V;i++){
    //        cout<<i<<" "<<par[i]<<endl;
    //    }
    int node1, node2;
    cin >> node1 >> node2;
    vector<int> path1 = path(node1, par);
    vector<int> path2 = path(node2, par);
    int lca = -1;
    int mn = min(path1.size(), path2.size());
    for (int i = 0; i < mn; i++)
    {
        if (path1[i] == path2[i])
        {
            lca = path1[i];
        }
        else
            break;
    }
    cout << lca << endl;
}
