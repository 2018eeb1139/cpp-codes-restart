class Solution
{
public:
    using ppi = pair<int, pair<int, int>>;
    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool isValid(int i, int j, int m, int n)
    {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    int minimumEffortPath(vector<vector<int>> &adj)
    {
        int m = adj.size();
        int n = adj[0].size();
        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            auto [x, y] = curr.second;
            int curr_dist = curr.first;
            if (x == m - 1 && y == n - 1)
            {
                return curr_dist;
            }
            for (auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (isValid(newX, newY, m, n))
                {
                    int new_dist = max(curr_dist, abs(adj[newX][newY] - adj[x][y]));
                    if (new_dist < dist[newX][newY])
                    {
                        dist[newX][newY] = new_dist;
                        pq.push({new_dist, {newX, newY}});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};