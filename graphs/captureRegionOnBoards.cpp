vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void Solution::solve(vector<vector<char>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();

    queue<pair<int, int>> q;
    for (int j = 0; j < n; j++)
    {
        if (mat[0][j] == 'O')
        {
            q.push({0, j});
            mat[0][j] = '#';
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (mat[m - 1][j] == 'O')
        {
            q.push({m - 1, j});
            mat[m - 1][j] = '#';
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mat[i][0] == 'O')
        {
            q.push({i, 0});
            mat[i][0] = '#';
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mat[i][n - 1] == 'O')
        {
            q.push({i, n - 1});
            mat[i][n - 1] = '#';
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
            if (isValid(newX, newY, m, n) && mat[newX][newY] == 'O')
            {
                q.push({newX, newY});
                mat[newX][newY] = '#';
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
            else if (mat[i][j] == '#')
            {
                mat[i][j] = 'O';
            }
        }
    }
}

// DFS use this
int m, n;
vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, vector<vector<char>> &mat, vector<vector<int>> &vis)
{
    if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || mat[i][j] == 'X')
        return;
    vis[i][j] = 1;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        dfs(newX, newY, mat, vis);
    }
}
void solve(vector<vector<char>> &mat)
{
    m = mat.size();
    n = mat[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
            {
                if (mat[i][j] == 'O')
                {
                    dfs(i, j, mat, vis);
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
}
