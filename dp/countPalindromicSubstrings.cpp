class Solution
{
public:
    int dp[1001][1001];
    bool solve(string &s, int i, int j)
    {
        if (i >= j)
            return true;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] != s[j])
            return false;
        return dp[i][j] = solve(s, i + 1, j - 1);
    }
    int countSubstrings(string s)
    {
        int n = s.size();
        if (n == 1)
            return 1;
        memset(dp, -1, sizeof(dp));
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (solve(s, i, j) == true)
                {
                    ct++;
                }
            }
        }
        return ct;
    }
};