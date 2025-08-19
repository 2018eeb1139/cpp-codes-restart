vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
string dir = "UDRL";

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

int Solution::solve(int m, int n, vector<string> &mat)
{
    vector<vector<char>> adj(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = mat[i][j];
        }
    }
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq; // min heap

    pq.push({0, {0, 0}});

    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int x = curr.second.first;
        int y = curr.second.second;
        int cost = curr.first;

        if (x == m - 1 && y == n - 1)
            return cost;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + directions[i].first;
            int newY = y + directions[i].second;
            if (isValid(newX, newY, m, n))
            {
                int newCost = cost;
                if (dir[i] != adj[x][y])
                {
                    newCost++;
                }
                if (newCost < dist[newX][newY])
                {
                    dist[newX][newY] = newCost;
                    pq.push({newCost, {newX, newY}});
                }
            }
        }
    }

    return dist[m - 1][n - 1];
}
