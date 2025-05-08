bool isValid(int i, int j, int n, int m)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
void bfs(vector<vector<char>> &grid, vector<vector<int>> &vis, vector<vector<int>> &level, int n, int m)
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ('W' == grid[i][j])
            {
                q.push({i, j}); // pushing all the W in the queue all the sources;
                vis[i][j] = 1;
                level[i][j] = 0;
            }
        }
    }
    int lev = 1;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto curr = q.front();
            q.pop();
            for (auto dir : directions)
            {
                int newX = curr.first + dir.first;
                int newY = curr.second + dir.second;
                if (isValid(newX, newY, n, m) && !vis[newX][newY] && (grid[newX][newY] == 'H' || grid[newX][newY] == '.'))
                {
                    if (grid[newX][newY] == 'H')
                    {
                        level[newX][newY] = lev * 2;
                    }
                    q.push({newX, newY});
                    vis[newX][newY] = 1;
                }
            }
        }
        lev++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 'H')
            {
                level[i][j] = -1;
            }
        }
    }
}
vector<vector<int>> chefAndWells(int n, int m, vector<vector<char>> &c)
{
    // Code here
    vector<vector<int>> level(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    bfs(c, vis, level, n, m);

    return level;
}