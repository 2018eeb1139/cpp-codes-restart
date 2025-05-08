int dp[101][101];
int m, n;

int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == m - 1 && j == n - 1)
    {
        return 1;
    }
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return 0;
    }
    if (grid[i][j] == 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int right = solve(i, j + 1, grid);
    int down = solve(i + 1, j, grid);
    return dp[i][j] = right + down;
}

int uniquePathsWithObstacles(vector<vector<int>> &grid)
{
    m = grid.size();
    n = grid[0].size();
    if (grid[m - 1][n - 1] == 1)
        return 0;
    memset(dp, -1, sizeof(dp)); // Corrected size of the dp array
    return solve(0, 0, grid);
}