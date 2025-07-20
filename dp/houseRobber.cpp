int dp[101];
int solve(vector<int> &nums, int i, int n)
{
    if (i >= n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int steal = nums[i] + solve(nums, i + 2, n);
    int skip = solve(nums, i + 1, n);

    return dp[i] = max(steal, skip);
}
int rob(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int n = nums.size();
    return solve(nums, 0, n);
    // return dp[n];
}

// bottom up
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> t(n + 1, 0);
    // t[i] max stolen money till ith house
    t[0] = 0;
    t[1] = nums[0];
    for (int i = 2; i <= n; i++)
    {
        int steal = nums[i - 1] + t[i - 2];
        int skip = t[i - 1];
        t[i] = max(steal, skip);
    }
    return t[n];
}
