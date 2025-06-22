// mutltisource BFS

vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int m, int n)
{
    return i >= 0 && j >= 0 && i < m && j < n;
}

void bfs(vector<vector<int>> &adj, vector<vector<bool>> &vis, vector<vector<int>> &level, int m, int n)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = true;
                level[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, m, n) && !vis[newX][newY])
            {
                q.push({newX, newY});
                vis[newX][newY] = true;
                level[newX][newY] = level[x][y] + 1;
            }
        }
    }
}

vector<int> Solution::nearestHotel(vector<vector<int>> &adj, vector<vector<int>> &edges)
{
    int m = adj.size();
    int n = adj[0].size();
    vector<vector<bool>> vis(m + 1, vector<bool>(n + 1, false));
    vector<vector<int>> level(m + 1, vector<int>(n + 1, 0));

    bfs(adj, vis, level, m, n);
    vector<int> ans;
    for (auto &edge : edges)
    {
        int i = edge[0];
        int j = edge[1];
        ans.push_back(level[i - 1][j - 1]);
    }

    return ans;
}