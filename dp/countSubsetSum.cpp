int dp[1005][1005];
int func(int idx, int target, vector<int> &arr)
{
    if (target == 0)
        return 1;
    if (idx < 0)
        return 0;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    int ans = func(idx - 1, target, arr);
    if (target - arr[idx] >= 0)
    {
        ans += func(idx - 1, target - arr[idx], arr);
    }
    return dp[idx][target] = ans;
}
int countSubsetSum(vector<int> &arr, int target)
{
    // code here
    memset(dp, -1, sizeof(dp));
    int n = arr.size();
    int zeroCount = 0;
    for (int num : arr)
    {
        if (num == 0)
            zeroCount++;
    }
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int result = dp[n][target];
    if (zeroCount > 0)
    {
        result = (result * (1 << zeroCount));
    }
    return result;
}