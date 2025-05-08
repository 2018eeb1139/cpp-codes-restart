int dp[3000];
int LIS(int i, vector<int> &a)
{
    int ans = 1;
    if (dp[i] != -1)
        return dp[i];
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
        {
            ans = max(ans, LIS(j, a) + 1);
        }
    }
    return dp[i] = ans;
}
int lengthOfLIS(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans = max(ans, LIS(i, nums));
    }
    return ans;
}