int dp[501][501];
int LCS(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
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
int minDistance(string word1, string word2)
{
    int ans = LCS(word1, word2);
    int del = word1.size() - ans;
    int ins = word2.size() - ans;
    return (del + ins);
}