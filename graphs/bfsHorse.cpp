#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int getX(string s)
{
    return s[0] - 'a';
}

int getY(string s)
{
    return s[1] - '1';
}

bool isValid(int x, int y)
{
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int bfs(string s1, string s2, vector<vector<bool>> &vis, vector<vector<int>> &level)
{
    int srcX = getX(s1);
    int srcY = getY(s1);
    int destX = getX(s2);
    int destY = getY(s2);
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {-2, 1}, {2, 1}, {-2, -1}, {2, -1}};
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
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
                vis[newX][newY] = true;
                level[newX][newY] = level[curr.first][curr.second] + 1;
            }
        }
    }
    return level[destX][destY];
}

void reset(vector<vector<bool>> &level, vector<vector<int>> &vis)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<bool>> vis(8, vector<bool>(8, false));
        vector<vector<int>> level(8, vector<int>(8, 0));
        cout << bfs(s1, s2, vis, level) << endl;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                level[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
}