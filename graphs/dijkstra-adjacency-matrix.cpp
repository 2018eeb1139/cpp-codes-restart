#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{
    const int INF = 1e9;

    vector<vector<pi>> adj(V);
    vector<int> dist(V, INF);

    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        int wt = edge[2];
        adj[x].push_back({y, wt});
        adj[y].push_back({x, wt}); // remove if graph is directed
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        auto [curr_dist, curr_node] = pq.top();
        pq.pop();

        // ✅ skip outdated entries
        if (curr_dist > dist[curr_node])
            continue;

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
    return dist;
}