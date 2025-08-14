vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int m, int n, vector<vector<int>> &adj)
{
    return (i >= 0 && j >= 0 && i < m && j < n && adj[i][j] == 1);
}

void dfs(int i, int j, vector<vector<int>> &adj, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n)
        return;
    if (adj[i][j] == 0)
        return;
    adj[i][j] = 0;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        dfs(newX, newY, adj, m, n);
    }
}

// just count the number of connected components
int Solution::black(vector<string> &A)
{
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>> adj(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        string s = A[i];
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'X')
            {
                adj[i][j] = 1;
            }
        }
    }
    int ct = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                dfs(i, j, adj, m, n);
                ct++;
            }
        }
    }
    return ct;
}
