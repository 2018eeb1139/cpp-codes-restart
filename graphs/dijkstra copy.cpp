#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.top();
        int curr_dist = curr.first;
        int curr_node = curr.second;
        for (auto &child : adj[curr_node])
        {
            int child_node = child.first;
            int child_wt = child.second;
            // relaxation step
            if (curr_dist + child_wt < dist[child_node])
            {
                dist[child_node] = curr_dist + child_wt;
                pq.push({dist[child_node], child_node});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            dist[i] = -1;
        }
    }
    return dist;
}
