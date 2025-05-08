int dp[101][101];
int solve(int i, int j, vector<int> &arr)
{
    if (i >= j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int temp = solve(i, k, arr) + solve(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j];

        ans = min(ans, temp);
    }
    return dp[i][j] = ans;
}
int matrixMultiplication(vector<int> &arr)
{
    // code here
    memset(dp, -1, sizeof(dp));
    int n = arr.size();
    return solve(1, n - 1, arr);
}