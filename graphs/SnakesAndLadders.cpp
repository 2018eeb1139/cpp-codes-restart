int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    vector<int> connections(n * n + 1, -1);
    int node = 1;
    int flag = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (flag)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != -1)
                {
                    int dest = board[i][j];
                    connections[node] = dest;
                }
                node += 1;
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[i][j] != -1)
                {
                    int dest = board[i][j];
                    connections[node] = dest;
                }
                node += 1;
            }
        }
        flag = !flag;
    }
    unordered_map<int, vector<int>> adj;
    for (int i = 1; i <= n * n - 1; i++)
    {
        for (int count = 1; count <= 6; count++)
        {
            int child = i + count;
            if (child <= n * n)
            {
                if (connections[child] != -1)
                {
                    adj[i].push_back(connections[child]);
                }
                else
                {
                    adj[i].push_back(child);
                }
            }
        }
    }
    int level = 0;
    vector<int> vis(n * n + 1, 0);
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto curr = q.front();
            q.pop();
            if (curr == n * n)
            {
                return level;
            }
            for (int &child : adj[curr])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        level += 1;
    }
    return -1;
}
// interview bit
int Solution::snakeLadder(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int n = 10;
    vector<int> connections(n * n + 1, -1);
    for (auto &edge : A)
    {
        int x = edge[0];
        int y = edge[1];
        connections[x] = y;
    }
    for (auto &edge : B)
    {
        int x = edge[0];
        int y = edge[1];
        connections[x] = y;
    }
    unordered_map<int, vector<int>> adj;
    for (int i = 1; i <= n * n; i++)
    {
        for (int count = 1; count <= 6; count++)
        {
            int child = i + count;
            if (child <= n * n)
            {
                if (connections[child] != -1)
                {
                    adj[i].push_back(connections[child]);
                }
                else
                {
                    adj[i].push_back(child);
                }
            }
        }
    }
    int level = 0;
    vector<int> vis(n * n + 1, 0);
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            auto curr = q.front();
            q.pop();
            if (curr == n * n)
            {
                return level;
            }
            for (int &child : adj[curr])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = 1;
                }
            }
        }
        level += 1;
    }
    return -1;
}
