vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int dfs(int i, int j, int m, int n, vector<vector<int>> &mat)
{

    if (i < 0 || j < 0 || i >= m || j >= n)
        return 0;
    if (mat[i][j] == 0)
        return 0;
    mat[i][j] = 0;
    int ct = 1;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        ct += dfs(newX, newY, m, n, mat);
    }
    return ct;
}

int Solution::solve(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                ans = max(ans, dfs(i, j, m, n, mat));
            }
        }
    }

    return ans;
}
