typedef pair<int, int> pi;
const int INF = 1e9 + 10;
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    vector<vector<pi>> adj(n + 1);
    vector<int> dist(n + 1, INF);
    for (auto &edge : times)
    {
        int x = edge[0];
        int y = edge[1];
        int wt = edge[2];
        adj[x].push_back({y, wt});
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, k});
    dist[k] = 0;
    while (!pq.empty())
    {
        auto [curr_dist, curr_node] = pq.top();
        pq.pop();
        for (auto &child : adj[curr_node])
        {
            int child_node = child.first;
            int child_wt = child.second;
            if (curr_dist + child_wt < dist[child_node])
            {
                dist[child_node] = curr_dist + child_wt;
                pq.push({dist[child_node], child_node});
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            return -1;
        else
        {
            ans = max(ans, dist[i]);
        }
    }
    return ans;
}