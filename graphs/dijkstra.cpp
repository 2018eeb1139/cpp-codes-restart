#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int inf = 1e7;

void dijkstra(int source, vector<int> &dist, vector<vector<pair<int, int>>> &graph)
{
    dist[source] = 0;

    // Using a set to keep track of vertices with their current distance
    set<pair<int, int>> st; // {weight, vertex}
    st.insert({0, source});

    // Dijkstra's algorithm
    while (!st.empty())
    {
        auto node = *st.begin();
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());

        // Traverse through all neighbors of vertex v
        for (auto child : graph[v])
        {
            int child_v = child.first;
            int w = child.second;
            // Relaxation step
            if (dist[v] + w < dist[child_v])
            {
                dist[child_v] = dist[v] + w;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    // Initialize the graph as an adjacency list
    vector<vector<pair<int, int>>> graph(nodes + 1);

    // Initialize distance array with infinity
    vector<int> dist(nodes + 1, inf);

    // Read edges and weights
    for (int i = 0; i < edges; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    dijkstra(1, dist, graph);
    // Output distances from source to all nodes
    for (int i = 1; i <= nodes; ++i)
    {
        cout << "Distance from " << 1 << " to " << i << " is ";
        if (dist[i] == inf)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
