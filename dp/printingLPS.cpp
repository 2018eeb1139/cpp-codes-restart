int dp[1001][1001];
int LCS(string &s1, string &s2, int m, int n)
{
    memset(dp, 0, sizeof(dp));
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
string printLCS(string &s1, string &s2, int m, int n)
{
    int i = m;
    int j = n;
    string res = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            res.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                i = i - 1;
            }
            else
            {
                j = j - 1;
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
string longestPalindrome(string s)
{
    int size = s.size();
    string s1 = s;
    reverse(s.begin(), s.end());
    LCS(s1, s, size, size);
    return printLCS(s1, s, size, size);
}