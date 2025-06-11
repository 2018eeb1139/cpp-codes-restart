vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && i < m && j >= 0 && j < n);
}

void bfs(queue<pair<int, int>> &q, vector<vector<int>> &mat, vector<vector<bool>> &vis, int m, int n)
{
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
                if (mat[x][y] <= mat[newX][newY])
                {
                    q.push({newX, newY});
                    vis[newX][newY] = true;
                }
            }
        }
    }
}

int Solution::solve(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<bool>> vis1(m, vector<bool>(n, false));
    vector<vector<bool>> vis2(m, vector<bool>(n, false));

    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0)
            {
                q1.push({i, j});
                vis1[i][j] = true;
            }
            if (i == m - 1 || j == n - 1)
            {
                q2.push({i, j});
                vis2[i][j] = true;
            }
        }
    }

    bfs(q1, mat, vis1, m, n);
    bfs(q2, mat, vis2, m, n);

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis1[i][j] && vis2[i][j])
            {
                ans++;
            }
        }
    }
    return ans;
}
