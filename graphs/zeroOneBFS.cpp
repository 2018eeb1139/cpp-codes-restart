#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

void bfs(int node, vector<pair<int, int>> adj[], vector<int> &level)
{
    deque<int> q;
    q.push_back(node);
    level[node] = 0;
    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop_front();
        for (auto &child : adj[curr_node])
        {
            int child_node = child.first;
            int wt = child.second;
            if (level[curr_node] + wt < level[child_node])
            {
                level[child_node] = level[curr_node] + wt;
                if (wt == 1)
                {
                    q.push_back(child_node);
                }
                else
                {
                    q.push_front(child_node);
                }
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<pair<int, int>> adj[V + 1];
    vector<int> level(V + 1, INT_MAX);
    for (int i = 0; i < E; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adj[x].push_back({y, wt});
    }
    bfs(0, adj, level);
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << ": " << (level[i] == INT_MAX ? -1 : level[i]) << endl;
    }
}