#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isValid(int x, int y, int n, vector<vector<bool>> &vis)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n && vis[x][y] == false);
}

vector<pair<int, int>> directions = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

void bfs(int srcX, int srcY, vector<vector<int>> &adj, vector<vector<bool>> &vis, vector<vector<int>> &level, int N)
{
    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vis[srcX][srcY] = true;
    while (!q.empty())
    {
        auto curr_node = q.front();
        q.pop();
        // cout<<curr_node.first<<" "<<curr_node.second;
        for (auto dir : directions)
        {
            int newX = curr_node.first + dir.first;
            int newY = curr_node.second + dir.second;
            if (isValid(newX, newY, N, vis))
            {
                q.push({newX, newY});
                vis[newX][newY] = true;
                level[newX][newY] = level[curr_node.first][curr_node.second] + 1;
            }
        }
    }
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    vector<vector<int>> adj(N + 1, vector<int>(N + 1));
    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));
    vector<vector<int>> level(N + 1, vector<int>(N + 1, 0));
    int srcX = KnightPos[0];
    int srcY = KnightPos[1];
    int destX = TargetPos[0];
    int destY = TargetPos[1];
    bfs(srcX, srcY, adj, vis, level, N);

    return level[destX][destY];
}