#include <iostream>
#include <queue>
#include <climits>

using namespace std;

void bfs(vector<vector<int>> &level, vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({i, j});
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
            if (newX >= 0 && newY >= 0 && newX < n && newY < m && level[curr.first][curr.second] + 1 < level[newX][newY])
            {
                q.push({newX, newY});
                level[newX][newY] = level[curr.first][curr.second] + 1;
            }
        }
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> level(n, vector<int>(m, INT_MAX));
    bfs(level, mat);
    return level;
}

int main()
{
    vector<vector<int>> matrix = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    updateMatrix(matrix);
}