int m, n;
int dp[301][301];
int solve(int i, int j, vector<vector<char>> &grid)
{
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (grid[i][j] == '0')
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = solve(i, j + 1, grid);
    int down = solve(i + 1, j, grid);
    int diag = solve(i + 1, j + 1, grid);

    return dp[i][j] = 1 + min(min(right, down), diag);
}
int maximalSquare(vector<vector<char>> &grid)
{
    m = grid.size();
    n = grid[0].size();
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                ans = max(ans, solve(i, j, grid));
            }
        }
    }
    return ans * ans;
}