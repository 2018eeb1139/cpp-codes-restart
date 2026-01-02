vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int m, int n, vector<vector<int>> &grid)
{
    return (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] != -1);
}

void islandsAndTreasure(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;

    // Push all gates (0) into queue
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }

    // Multi-source BFS
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

            if (isValid(newX, newY, m, n, grid) &&
                grid[x][y] + 1 < grid[newX][newY])
            {

                grid[newX][newY] = grid[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
}
