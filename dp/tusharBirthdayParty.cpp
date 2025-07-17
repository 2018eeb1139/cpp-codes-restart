int Solution::solve(const vector<int> &capacity, const vector<int> &dishes, const vector<int> &val)
{
    int ans = 0;

    int W = *max_element(capacity.begin(), capacity.end());
    vector<int> t(W + 1, INT_MAX);
    t[0] = 0;
    for (int i = 0; i < W + 1; i++)
    {
        for (int j = 0; j < dishes.size(); j++)
        {
            if (dishes[j] <= i)
            {
                t[i] = min(t[i], t[i - dishes[j]] + val[j]);
            }
        }
    }
    for (int i = 0; i < capacity.size(); i++)
    {
        ans += t[capacity[i]];
    }
    return ans;
}
