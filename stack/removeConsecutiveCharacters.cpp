string Solution::solve(string A, int B)
{
    stack<pair<char, int>> s;
    for (int i = 0; i < A.size(); i++)
    {
        if (s.empty())
        {
            s.push({A[i], 1});
        }
        else if (s.top().first == A[i])
        {
            s.top().second += 1;
            if (s.top().second == B)
            {
                s.pop();
            }
        }
        else
        {
            if (s.top().second == B)
            {
                s.pop();
            }
            s.push({A[i], 1});
        }
    }

    // Final clean-up: remove if top has count == B
    if (!s.empty() && s.top().second == B)
    {
        s.pop();
    }

    string ans = "";
    while (!s.empty())
    {
        int ct = s.top().second;
        char c = s.top().first;
        while (ct--)
        {
            ans.push_back(c);
        }
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
