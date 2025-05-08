int dp[101][101][201];
int m, n;
int N;
int len(string &s)
{
    return s.size();
}
bool solve(string &s1, string &s2, string &s3, int i, int j, int k)
{
    if (i == m && j == n && k == N)
    {
        return true;
    }
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    bool res = false;
    if (s1[i] == s3[k])
    {
        res = solve(s1, s2, s3, i + 1, j, k + 1);
    }
    if (res == true)
    {
        return dp[i][j][k] = true;
    }
    if (s2[j] == s3[k])
    {
        res = solve(s1, s2, s3, i, j + 1, k + 1);
    }
    return dp[i][j][k] = res;
}
bool isInterleave(string s1, string s2, string s3)
{
    m = len(s1);
    n = len(s2);
    N = len(s3);
    if (m + n != len(s3))
        return false;
    memset(dp, -1, sizeof(dp));
    return solve(s1, s2, s3, 0, 0, 0);
}