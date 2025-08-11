int Solution::solve(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));
    int ans = INT_MIN;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            t[i][j] = A[i][j] + (t[i + 1][j] + t[i][j + 1] - t[i + 1][j + 1]);
            ans = max(ans, t[i][j]);
        }
    }
    return ans;
}
