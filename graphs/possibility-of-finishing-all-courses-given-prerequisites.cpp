int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
    vector<int> adj[A + 1];
    vector<int> indegree(A + 1, 0);
    for (int i = 0; i < B.size(); i++)
    {
        int x = B[i];
        int y = C[i];
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for (int i = 1; i <= A; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int &child : adj[curr])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    for (int i = 1; i <= A; i++)
    {
        if (indegree[i] != 0)
        {
            return 0;
        }
    }
    return 1;
}
