// There are A people numbered 1 to A in a football academy.

// The coach of the academy wants to make two
// teams(not necessary of equal size) but unfortunately,
// not all people get along, and several refuse to be put on the same team as that of their enemies.

// Given a 2 -
// D array B of size M x 2 denoting the enemies i.e B[i][0] and
// B[i][1] both are enemies of each other.

// Return 1 if it possible to make exactly two teams else return 0.

// Same as bipartite graph

int Solution::solve(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V + 1];
    vector<int> color(V + 1, -1);
    for (auto &edge : edges)
    {
        int x = edge[0];
        int y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= V; i++)
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
                for (auto &child : adj[curr_node])
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
