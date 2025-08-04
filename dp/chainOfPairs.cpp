// derived from Longest Increasing subsequence
int dp[1001];
int lis(vector<vector<int>> &a, int i)
{
    if (dp[i] != -1)
        return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j][1] < a[i][0])
        {
            ans = max(ans, lis(a, j) + 1);
        }
    }
    return dp[i] = ans;
}

int Solution::solve(vector<vector<int>> &a)
{
    memset(dp, -1, sizeof(dp));
    int ans = 1;
    for (int i = 0; i < a.size(); i++)
    {
        ans = max(ans, lis(a, i));
    }
    return ans;
}