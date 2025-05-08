int dp[1005][1005];
int lcs(int i, int j, string &s1, string &s2)
{
    if (i == 0 || j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i - 1] == s2[j - 1])
    {
        return dp[i][j] = 1 + lcs(i - 1, j - 1, s1, s2);
    }
    else
    {
        return dp[i][j] = max(lcs(i - 1, j, s1, s2), lcs(i, j - 1, s1, s2));
    }
}
int longestCommonSubsequence(string s1, string s2)
{
    memset(dp, -1, sizeof(dp));
    return lcs(s1.size(), s2.size(), s1, s2);
    // TOP down
    int m = s1.size();
    int n = s2.size();
    for (int i = 0; i < m + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j < n + 1; j++)
    {
        dp[0][j] = 0;
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