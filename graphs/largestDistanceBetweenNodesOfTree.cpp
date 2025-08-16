// same as finding diameter of tree

void dfs(int node, int par, vector<int> adj[], vector<int> &depth)
{
    for (int &child : adj[node])
    {
        if (par != child)
        {
            depth[child] = depth[node] + 1;
            dfs(child, node, adj, depth);
        }
    }
}

int Solution::solve(vector<int> &A)
{
    int V = A.size();
    if (V == 1)
        return 0;
    vector<int> adj[V];
    vector<int> depth(V, 0);
    int root;
    for (int i = 0; i < V; i++)
    {
        if (A[i] == -1)
        {
            root = i;
            depth[root] = 0;
        }
        else
        {
            int x = i;
            int y = A[i];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    dfs(root, -1, adj, depth);
    int max_d_node;
    int max_depth = -1;
    for (int i = 0; i < V; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }
    // cout<<max_d_node<<endl;
    dfs(max_d_node, -1, adj, depth);
    max_depth = -1;
    for (int i = 0; i < V; i++)
    {
        if (max_depth < depth[i])
        {
            max_depth = depth[i];
        }
    }
    return max_depth;
}
