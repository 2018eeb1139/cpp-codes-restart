int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> t(n, vector<int>(n));

    for (int j = 0; j < n; j++)
    {
        t[n - 1][j] = A[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            t[i][j] = A[i][j] + max(t[i + 1][j], t[i + 1][j + 1]);
        }
    }
    return t[0][0];
}
