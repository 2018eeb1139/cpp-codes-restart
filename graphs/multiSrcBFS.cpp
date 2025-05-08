#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> grid(n, vector<int>(m));
vector<vector<int>> vis(n, vector<int>(m));
vector<vector<int>> level(n, vector<int>(m));

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = 0;
            level[i][j] = 0;
        }
    }
};

bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}

int bfs()
{
    int mx = INT_MIN;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, grid[i][j]);
        }
    }
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mx == grid[i][j])
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
            if (isValid(newX, newY) && !vis[newX][newY])
            {
                q.push({newX, newY});
                vis[newX][newY] = 1;
                level[newX][newY] = level[curr.first][curr.second] + 1;
                ans = max(ans, level[newX][newY]);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        reset();
        cout << bfs() << endl;
    }
}