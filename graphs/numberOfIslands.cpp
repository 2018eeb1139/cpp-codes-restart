#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, vector<vector<char>> &grid, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
        return;
    grid[i][j] = '0';
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        dfs(newX, newY, grid, m, n);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ct = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid, m, n);
                ct++;
            }
        }
    }
    return ct;
}