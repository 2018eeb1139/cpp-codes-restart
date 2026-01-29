typedef pair<int, pair<int, int>> ppi;
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
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    dist[0][0] = 0;
    pq.push({0, {0, 0}}); // dist {i,j};
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int curr_dist = curr.first;
        int i = curr.second.first;
        int j = curr.second.second;
        for (auto &dir : directions)
        {
            int newX = i + dir.first;
            int newY = j + dir.second;
            if (isValid(newX, newY, m, n))
            {
                int new_dist = max(dist[i][j], abs(adj[newX][newY] - adj[i][j]));
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