bool isBipartite(vector<vector<int>> &graph)
{
    int V = graph.size();
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                auto curr_node = q.front();
                q.pop();
                for (auto &child : graph[curr_node])
                {
                    if (color[child] == -1)
                    {
                        color[child] = !color[curr_node];
                        q.push(child);
                    }
                    else if (color[child] == color[curr_node])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}