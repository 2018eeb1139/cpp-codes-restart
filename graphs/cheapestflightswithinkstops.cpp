typedef pair<int, int> pi;
const int INF = 1e9 + 10;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pi>> adj(n);

    for (auto &edge : flights)
    {
        int x = edge[0];
        int y = edge[1];
        int wt = edge[2];
        adj[x].push_back({y, wt});
    }

    vector<int> dist(n, INF);
    queue<vector<int>> q;
    dist[src] = 0;
    q.push({0, src, 0}); // stop node dist
    while (!q.empty())
    {
        auto curr = q.front();
        int curr_stop = curr[0];
        int curr_node = curr[1];
        int curr_dist = curr[2];
        q.pop();
        if (curr_stop > k)
            break;
        for (auto &child : adj[curr_node])
        {
            int child_node = child.first;
            int child_wt = child.second;
            if (curr_dist + child_wt < dist[child_node])
            {
                dist[child_node] = curr_dist + child_wt;
                q.push({curr_stop + 1, child_node, dist[child_node]});
            }
        }
    }
    return dist[dst] == INF ? -1 : dist[dst];
}