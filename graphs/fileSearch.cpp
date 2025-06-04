// You are given an assignment to sort out the files of your department today.

//     A file contains various records.Each record has
//     an(ID, Parent ID)
//         .

//     To make your task easier,
//     you decided to separate records into different sets.

//         If a set contains a record with(ID, Parent ID) -
//         (X, Y),
//     then both X and Y must be present in the set.

//     There are A records.You are also given a 2D array B of dimensions N x 2,

//     where each row is record's (ID, Parent ID).

//     You have to find the maximum number of sets you can divide the records into.

// Number of connected components

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    for (int &child : adj[node])
    {
        if (!vis[child])
        {
            dfs(child, adj, vis);
        }
    }
}

int Solution::breakRecords(int A, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(A + 1);
    vector<bool> vis(A + 1, false);
    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ct = 0;
    for (int i = 1; i <= A; i++)
    {
        if (!vis(i))
        {
            dfs(i, adj, vis);
            ct++;
        }
    }
    return ct;
}
