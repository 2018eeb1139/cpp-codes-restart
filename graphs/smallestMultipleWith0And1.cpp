// Classic BFS +  Modulo Problem

string Solution::multiple(int A)
{
    if (A == 0)
        return "0";

    queue<string> q;
    vector<bool> vis(A, false);

    q.push("1");

    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        // compute remainder of curr mod A without converting to integer
        int rem = 0;
        for (char c : curr)
        {
            rem = (rem * 10 + (c - '0')) % A;
        }

        if (rem == 0)
        {
            return curr;
        }

        if (!vis[rem])
        {
            vis[rem] = true;
            q.push(curr + "0");
            q.push(curr + "1");
        }
    }
    return "";
}
