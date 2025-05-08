int dp[1001][1001];
int LCS(string &s1, string &s2, int m, int n)
{
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int minInsertions(string s)
{
    string t = s;
    reverse(s.begin(), s.end());
    int n = s.size();
    return n - LCS(t, s, n, n);
}