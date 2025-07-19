int t[101];
int solve(string s, int i)
{
    if (i == s.size())
    {
        return t[i] = 1;
    }
    if (t[i] != -1)
        return t[i];
    if (s[i] == '0')
        return t[i] = 0;
    int res = solve(s, i + 1);
    if (i + 1 < s.size())
    {
        if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
        {
            res += solve(s, i + 2);
        }
    }
    return t[i] = res;
}
// BOTTOM-UP
int Solution::numDecodings(string s)
{
    int n = s.size();
    const int MOD = 1e9 + 7;
    vector<int> t(n + 1, 0);
    t[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            t[i] = 0;
        }
        else
        {
            t[i] = (t[i + 1] % MOD);
            if (i + 1 < n)
            {
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                {
                    t[i] = ((t[i] + t[i + 2]) % MOD);
                }
            }
        }
    }
    return (t[0] % MOD);
}

int numDecodings(string s)
{
    memset(t, -1, sizeof(t));
    return solve(s, 0);
}