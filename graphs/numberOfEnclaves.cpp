vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}
void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int m, int n)
{
    queue<pair<int, int>> q;
    for (int j = 0; j < n; j++)
    {
        if (grid[0][j] == 1)
        {
            q.push({0, j});
            vis[0][j] = 1;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (grid[m - 1][j] == 1)
        {
            q.push({m - 1, j});
            vis[m - 1][j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 1)
        {
            q.push({i, 0});
            vis[i][0] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[i][n - 1] == 1)
        {
            q.push({i, n - 1});
            vis[i][n - 1] = 1;
        }
    }
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for (auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, m, n) && !vis[newX][newY] && grid[newX][newY] == 1)
            {
                q.push({newX, newY});
                vis[newX][newY] = 1;
            }
        }
    }
}
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    bfs(grid, vis, m, n);
    int ct = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                ct++;
            }
        }
    }
    return ct;
}