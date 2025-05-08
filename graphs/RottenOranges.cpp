#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}
int bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &level, int m, int n)
{
    int ans = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (2 == grid[i][j])
            {
                q.push({i, j}); // pushing all the max in the queue all the sources;
                vis[i][j] = 1;
                level[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (auto dir : directions)
        {
            int newX = curr.first + dir.first;
            int newY = curr.second + dir.second;
            if (isValid(newX, newY, m, n) && !vis[newX][newY] && grid[newX][newY] == 1)
            {
                q.push({newX, newY});
                vis[newX][newY] = 1;
                level[newX][newY] = level[curr.first][curr.second] + 1;
                ans = max(ans, level[newX][newY]);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                return -1;
            }
        }
    }
    return ans;
}
int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> level(m, vector<int>(n, 0));
    int res = bfs(grid, vis, level, m, n);
    if (res == INT_MIN)
    {
        return -1;
    }
    else
    {
        return res;
    }
}